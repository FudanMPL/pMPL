#include "Secret_Cmp.h"
#include "Secret_Mul.h"

Matrixint64 Secret_Cmp::to_Boolean_Share(Matrixint64 &x)
{
    int row = x.rows();
    int col = x.cols();
    // 先把空间秘密分享转为additive share
    Matrixint64 share(row, col);
    share = x;
    if (party == 0 || party == 2)
    {
        share = x * (-1) / 2;
    }
    else if (party == 1)
    {
        share = x / 2;
    }
    // A2B
    vector<Matrixint64> temp_shares;
    for (int i = 0; i < M; i++)
    {
        if (party == i)
        {
            temp_shares.push_back(share);
        }
        else
        {
            Matrixint64 temp(row, col);
            temp.setZero();
            temp_shares.push_back(temp);
        }
    }
    Matrixint64 boolean_share = temp_shares[0];
    for (int i = 1; i < M; i++)
    {
        boolean_share = Boolean_Share::add(boolean_share, temp_shares[i]);
    }
    return boolean_share;
}

Matrixint64 Secret_Cmp::get_sign(Matrixint64 &x)
{
    Matrixint64 boolean_share = Secret_Cmp::to_Boolean_Share(x);
    Matrixint64 bool_share_bit = Mat::op_shift_right(boolean_share, BIT_LENGTH - 1);
    Matrixint64 add_share_bit = Boolean_Share::to_additive_share(bool_share_bit);
    Matrixint64 sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);
    if (party == 0 || party == 2)
    {
        sign= sign * (-1) * 2;
    }
    else if (party == 1)
    {
        sign = sign * 2;
    }
    return sign;
}

Matrixint64 Secret_Cmp::get_sign_xor_1(Matrixint64 &x)
{
    Matrixint64 boolean_share = Secret_Cmp::to_Boolean_Share(x);
    Matrixint64 bool_share_bit = Mat::op_shift_right(boolean_share, BIT_LENGTH - 1);
    Matrixint64 bool_share_bit_xor_1 = Mat::op_Xor(1, bool_share_bit);
    Matrixint64 add_share_bit = Boolean_Share::to_additive_share(bool_share_bit_xor_1);
    Matrixint64 sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);
    if (party == 0 || party == 2)
    {
        sign = sign * (-1) * 2;
    }
    else if (party == 1)
    {
        sign = sign * 2;
    }
    return sign;
}

Matrixint64 Secret_Cmp::Relu(Matrixint64 x)
{
    Matrixint64 b = Secret_Cmp::get_sign_xor_1(x);
    int row = x.rows(), col = x.cols();
    Matrixint64 r(row, col), q(row, col), t(row, col);
    Matrixint64 result = Secret_Mul::CwiseProduct(x, b, r, q, t);
    return result;
}

Matrixint64 Secret_Cmp::Sigmoid(Matrixint64 x)
{
    int row = x.rows();
    int col = x.cols();
    Matrixint64 result;
    //第0方的秘密值用于形成真实值的(x+1/2)或(x-1/2)，其他方秘密值保持不变
    if (party == 0)
    {
        Matrixint64 Mat_IE(row, col);
        Mat_IE.setConstant(IE);
        Matrixint64 x_plus_ie = x + Mat_IE;
        Matrixint64 x_sub_ie = x - Mat_IE;
        // cout << x_sub_ie << endl;
        Matrixint64 r(B, 1), q(B, 1), t(B, 1);
        Matrixint64 b1_xor_1 = Secret_Cmp::get_sign_xor_1(x_sub_ie);
        // cout << "b1_xor_1:" << Secret_Mul::reveal(b1_xor_1) << endl;
        Matrixint64 b2 = Secret_Cmp::get_sign(x_plus_ie);
        // cout << "b2:" << Secret_Mul::reveal(b2) << endl;
        Matrixint64 b2_xor_1 = Secret_Cmp::get_sign_xor_1(x_plus_ie);
        // cout << "b2_xor_1:" << Secret_Mul::reveal(b2_xor_1) << endl;
        Matrixint64 temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        Matrixint64 result1 = Secret_Mul::CwiseProduct(temp, x_sub_ie, r, q, t);
        result = result1 + b2_xor_1;
    }
    else
    {
        Matrixint64 r(B, 1), q(B, 1), t(B, 1);
        Matrixint64 b1_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        // cout << "b1_xor_1:" << Secret_Mul::reveal(b1_xor_1) << endl;
        Matrixint64 b2 = Secret_Cmp::get_sign(x);
        // cout << "b2:" << Secret_Mul::reveal(b2) << endl;
        Matrixint64 b2_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        // cout << "b2_xor_1:" << Secret_Mul::reveal(b2_xor_1) << endl;
        Matrixint64 temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        Matrixint64 result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    return result;
}