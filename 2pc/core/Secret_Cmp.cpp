#include "Secret_Cmp.h"
#include "Secret_Mul.h"

MatrixXu Secret_Cmp::to_Boolean_Share(MatrixXu &x)
{
    int row = x.rows();
    int col = x.cols();
    // 先把空间秘密分享转为additive share
    MatrixXu share(row, col);
    if (party == 0)
    {
        share = x;
    }
    else if (party == 1)
    {
        share = x * 3;
    }
    else if (party == 2)
    {
        share = x * (UINT64_MAX - 1);
    }
    // A2B
    vector<MatrixXu> temp_shares;
    for (int i = 0; i < M; i++)
    {
        if (party == i)
        {
            temp_shares.push_back(share);
        }
        else
        {
            MatrixXu temp(row, col);
            temp.setZero();
            temp_shares.push_back(temp);
        }
    }
    MatrixXu boolean_share = temp_shares[0];
    for (int i = 1; i < M; i++)
    {
        boolean_share = Boolean_Share::add(boolean_share, temp_shares[i]);
    }
    return boolean_share;
}

MatrixXu Secret_Cmp::get_bool_share_bit(MatrixXu &x)
{
    int row = x.rows();
    int col = x.cols();
    MatrixXu r_bool, r_add;
    if (col == numClass)
    {
        if (party == 0)
        {
            r_bool = Boolean_Share::r0_0;
            r_add = Boolean_Share::r_00;
        }
        else if (party == 1)
        {
            r_bool = Boolean_Share::r0_1;
            r_add = Boolean_Share::r_01;
        }
        else if (party == 2)
        {
            r_bool = Boolean_Share::r0_2;
            r_add = Boolean_Share::r_02;
        }
    }
    else if (col == hiddenDim)
    {
        if (party == 0)
        {
            r_bool = Boolean_Share::r1_0;
            r_add = Boolean_Share::r_10;
        }
        else if (party == 1)
        {
            r_bool = Boolean_Share::r1_1;
            r_add = Boolean_Share::r_11;
        }
        else if (party == 2)
        {
            r_bool = Boolean_Share::r1_2;
            r_add = Boolean_Share::r_12;
        }
    }
    // 先把空间秘密分享转为additive share
    MatrixXu share(row, col);
    if (party == 0)
    {
        share = x;
    }
    else if (party == 1)
    {
        share = x * 3;
    }
    else if (party == 2)
    {
        share = x * (UINT64_MAX - 1);
    }
    MatrixXu a = share + r_add;
    MatrixXu rev_a = Boolean_Share::add_reveal(a);
    MatrixXu max(row, col), mat_IE(row, col);
    max.setConstant(UINT64_MAX);
    mat_IE.setConstant(1);
    MatrixXu t = Mat::op_Xor(r_bool, max);
    MatrixXu a_plus_one = rev_a + mat_IE;
    MatrixXu boolean_share = Boolean_Share::add(a_plus_one, t);
    MatrixXu bool_share_bit = Mat::op_shift_right(boolean_share, BIT_LENGTH - 1);
    return bool_share_bit;
}

MatrixXu Secret_Cmp::get_sign(MatrixXu &x)
{
    MatrixXu add_share_bit = Boolean_Share::to_additive_share(x);
    MatrixXu sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);
    if (party == 0)
    {
        sign = sign;
    }
    else if (party == 1)
    {
        sign = sign / 3;
    }
    else if (party == 2)
    {
        sign = (sign * UINT64_MAX) / 2;
    }
    return sign;
}

MatrixXu Secret_Cmp::get_sign_xor_1(MatrixXu &x)
{
    MatrixXu bool_share_bit_xor_1 = Mat::op_Xor(1, x);
    MatrixXu add_share_bit = Boolean_Share::to_additive_share(bool_share_bit_xor_1);
    MatrixXu sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);
    if (party == 0)
    {
        sign = sign;
    }
    else if (party == 1)
    {
        sign = sign / 3;
    }
    else if (party == 2)
    {
        sign = (sign * UINT64_MAX) / 2;
    }
    return sign;
}

MatrixXu Secret_Cmp::Relu(MatrixXu x)
{
    MatrixXu bool_share_bit = Secret_Cmp::get_bool_share_bit(x);
    MatrixXu b = Secret_Cmp::get_sign_xor_1(bool_share_bit);
    int row = x.rows(), col = x.cols();
    MatrixXu r(row, col), q(row, col), t(row, col);
    MatrixXu result = Secret_Mul::CwiseProduct(x, b, r, q, t);
    return result;
}

MatrixXu Secret_Cmp::Sigmoid(MatrixXu x)
{
    int row = x.rows();
    int col = x.cols();
    MatrixXu result;
    //第0方的秘密值用于形成真实值的(x+1/2)或(x-1/2)，其他方秘密值保持不变
    if (party == 0)
    {
        MatrixXu Mat_IE(row, col);
        Mat_IE.setConstant(IE / 2);
        MatrixXu x_plus_ie = x + Mat_IE;
        MatrixXu x_sub_ie = x - Mat_IE;
        MatrixXu combination(row * 2, col);
        combination << x_plus_ie,
            x_sub_ie;
        MatrixXu com_bool_share_bit = Secret_Cmp::get_bool_share_bit(combination);
        MatrixXu r(row, col), q(row, col), t(row, col);
        MatrixXu b2_bool_share_bit = com_bool_share_bit.bottomRows(row);
        MatrixXu com_xor_1 = Secret_Cmp::get_sign_xor_1(com_bool_share_bit);
        MatrixXu b1_xor_1 = com_xor_1.topRows(row);
        MatrixXu b2_xor_1 = com_xor_1.bottomRows(row);
        MatrixXu b2 = Secret_Cmp::get_sign(b2_bool_share_bit);
        // MatrixXu b1_bool_share_bit = Secret_Cmp::get_bool_share_bit(x_plus_ie);
        // MatrixXu b1_xor_1 = Secret_Cmp::get_sign_xor_1(b1_bool_share_bit);
        // MatrixXu b2_bool_share_bit = Secret_Cmp::get_bool_share_bit(x_sub_ie);
        // MatrixXu b2 = Secret_Cmp::get_sign(b2_bool_share_bit);
        // MatrixXu b2_xor_1 = Secret_Cmp::get_sign_xor_1(b2_bool_share_bit);
        MatrixXu temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        MatrixXu result1 = Secret_Mul::CwiseProduct(temp, x_plus_ie, r, q, t);
        result = result1 + b2_xor_1;
    }
    else
    {
        MatrixXu combination(row * 2, col);
        combination << x,
            x;
        MatrixXu com_bool_share_bit = Secret_Cmp::get_bool_share_bit(combination);
        MatrixXu r(row, col), q(row, col), t(row, col);
        MatrixXu b2_bool_share_bit = com_bool_share_bit.bottomRows(row);
        MatrixXu com_xor_1 = Secret_Cmp::get_sign_xor_1(com_bool_share_bit);
        MatrixXu b1_xor_1 = com_xor_1.topRows(row);
        MatrixXu b2_xor_1 = com_xor_1.bottomRows(row);
        MatrixXu b2 = Secret_Cmp::get_sign(b2_bool_share_bit);
        // MatrixXu r(row, col), q(row, col), t(row, col);
        // MatrixXu b1_bool_share_bit = Secret_Cmp::get_bool_share_bit(x);
        // MatrixXu b1_xor_1 = Secret_Cmp::get_sign_xor_1(b1_bool_share_bit);
        // MatrixXu b2_bool_share_bit = Secret_Cmp::get_bool_share_bit(x);
        // MatrixXu b2 = Secret_Cmp::get_sign(b2_bool_share_bit);
        // MatrixXu b2_xor_1 = Secret_Cmp::get_sign_xor_1(b2_bool_share_bit);
        MatrixXu temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        MatrixXu result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    return result;
}