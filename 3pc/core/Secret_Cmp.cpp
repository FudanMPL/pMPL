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
    else if (party == 2)
    {
        share = x * 3;
    }
    else if (party == 3)
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

MatrixXu Secret_Cmp::get_sign(MatrixXu &x)
{
    MatrixXu boolean_share = Secret_Cmp::to_Boolean_Share(x);
    MatrixXu bool_share_bit = Mat::op_shift_right(boolean_share, BIT_LENGTH - 1);
    MatrixXu add_share_bit = Boolean_Share::to_additive_share(bool_share_bit);
    MatrixXu sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);
    if (party == 0)
    {
        sign = sign;
    }
    else if (party == 2)
    {
        sign = sign / 3;
    }
    else if (party == 3)
    {
        sign = (sign * UINT64_MAX) / 2;
    }
    return sign;
}

MatrixXu Secret_Cmp::get_sign_xor_1(MatrixXu &x)
{
    int row = x.rows(), col = x.cols();
    MatrixXu sign(row, col);
    if (party == 1)
    {
        sign.setZero();
        return sign;
    }
    MatrixXu boolean_share = Secret_Cmp::to_Boolean_Share(x);
    MatrixXu bool_share_bit = Mat::op_shift_right(boolean_share, BIT_LENGTH - 1);

    MatrixXu bool_share_bit_xor_1 = Mat::op_Xor(1, bool_share_bit);

    MatrixXu add_share_bit = Boolean_Share::to_additive_share(bool_share_bit_xor_1);

    sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);

    if (party == 0)
    {
        sign = sign;
    }
    else if (party == 2)
    {
        sign = sign / 3;
    }
    else if (party == 3)
    {
        sign = (sign * UINT64_MAX) / 2;
    }
    return sign;
}

MatrixXu Secret_Cmp::Relu(MatrixXu x)
{
    MatrixXu result;
    int row = x.rows(), col = x.cols();
    MatrixXu r(row, col), q(row, col), t(row, col);
    if (party == 0 || party == 2 || party == 3)
    {
        MatrixXu b = Secret_Cmp::get_sign_xor_1(x);
        result = Secret_Mul::CwiseProduct(x, b, r, q, t);
    }
    else if (party == 1)
    {
        MatrixXu b(row, col);
        result = Secret_Mul::CwiseProduct(x, b, r, q, t);
    }
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

        MatrixXu r(row, col), q(row, col), t(row, col);
        MatrixXu b1_xor_1 = Secret_Cmp::get_sign_xor_1(x_plus_ie);

        MatrixXu b2 = Secret_Cmp::get_sign(x_sub_ie);

        MatrixXu b2_xor_1 = Secret_Cmp::get_sign_xor_1(x_sub_ie);

        MatrixXu k1, b2_xor_1_plus_k2, b2_xor_1_plus_k3;
        if (row == B && col == numClass)
        {
            k1 = Secret_Mul::m0_1;
        }
        tel.receive(&b2_xor_1_plus_k2, 2);
        tel.receive(&b2_xor_1_plus_k3, 3);
        MatrixXu b2_xor_1_1 = b2_xor_1_plus_k3 - b2_xor_1_plus_k2 - k1;
        tel.send(&b2_xor_1_1, 1);
        MatrixXu temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        MatrixXu result1 = Secret_Mul::CwiseProduct(temp, x_plus_ie, r, q, t);
        result = result1 + b2_xor_1;
    }
    else if (party == 2)
    {
        MatrixXu r(row, col), q(row, col), t(row, col);
        MatrixXu b1_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        MatrixXu b2 = Secret_Cmp::get_sign(x);
        MatrixXu b2_xor_1 = Secret_Cmp::get_sign_xor_1(x);

        MatrixXu k2;
        if (row == B && col == numClass)
        {
            k2 = Secret_Mul::m0_2;
        }
        MatrixXu b2_xor_1_plus_k = b2_xor_1 + k2;
        tel.send(&b2_xor_1_plus_k, 0);
        MatrixXu temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        MatrixXu result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    else if (party == 3)
    {
        MatrixXu r(row, col), q(row, col), t(row, col);
        MatrixXu b1_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        MatrixXu b2 = Secret_Cmp::get_sign(x);
        MatrixXu b2_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        MatrixXu k3;
        if (row == B && col == numClass)
        {
            k3 = Secret_Mul::m0_3;
        }
        MatrixXu b2_xor_1_plus_k = b2_xor_1 + k3;
        tel.send(&b2_xor_1_plus_k, 0);
        MatrixXu temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        MatrixXu result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    else if (party == 1)
    {
        MatrixXu b2_xor_1(row, col), temp(row, col);
        MatrixXu r(row, col), q(row, col), t(row, col);
        tel.receive(&b2_xor_1, 0);
        MatrixXu result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    return result;
}