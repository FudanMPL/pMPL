#include "Secret_Cmp.h"
#include "Secret_Mul.h"

Matrixint64 Secret_Cmp::to_Boolean_Share(Matrixint64 &x)
{
    int row = x.rows();
    int col = x.cols();
    // 先把空间秘密分享转为additive share
    Matrixint64 share(row, col);
    if (party == 0)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (x(i, j) % 2 != 0)
                {
                    if (x(i, j) < 0)
                        share(i, j) = x(i, j) * (-1) / 2 + 1;
                    if (x(i, j) > 0)
                        share(i, j) = x(i, j) * (-1) / 2 - 1;
                }
                else
                {
                    share(i, j) = x(i, j) * (-1) / 2;
                }
            }
        }
    }
    else if (party == 2 || party == 3)
    {
        share = x / 2;
    }
    // A2B
    vector<Matrixint64> temp_shares;
    for (int i = 0; i < 4; i++)
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
    for (int i = 1; i < 4; i++)
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
    if (party == 0)
    {
        sign = -sign * 2;
        return sign;
    }
    else
    {
        sign *= 2;
        return sign;
    }
}

Matrixint64 Secret_Cmp::get_sign_xor_1(Matrixint64 &x)
{
    int row = x.rows(), col = x.cols();
    Matrixint64 sign(row, col);
    if (party == 1)
    {
        sign.setZero();
        return sign;
    }
    Matrixint64 boolean_share = Secret_Cmp::to_Boolean_Share(x);
    Matrixint64 bool_share_bit = Mat::op_shift_right(boolean_share, BIT_LENGTH - 1);

    Matrixint64 bool_share_bit_xor_1 = Mat::op_Xor(1, bool_share_bit);

    Matrixint64 add_share_bit = Boolean_Share::to_additive_share(bool_share_bit_xor_1);

    sign = Mat::op_shift_left(add_share_bit, DECIMAL_LENGTH);

    if (party == 0)
    {
        sign = sign * (-1) * 2;
    }
    else if (party == 2 || party == 3)
    {
        sign = sign * 2;
    }
    return sign;
}

Matrixint64 Secret_Cmp::Relu(Matrixint64 x)
{
    Matrixint64 result;
    int row = x.rows(), col = x.cols();
    Matrixint64 r(row, col), q(row, col), t(row, col);
    if (party == 0 || party == 2 || party == 3)
    {
        Matrixint64 b = Secret_Cmp::get_sign_xor_1(x);
        result = Secret_Mul::CwiseProduct(x, b, r, q, t);
    }
    else if (party == 1)
    {
        Matrixint64 b(row, col);
        result = Secret_Mul::CwiseProduct(x, b, r, q, t);
    }
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

        Matrixint64 r(row, col), q(row, col), t(row, col);
        Matrixint64 b1_xor_1 = Secret_Cmp::get_sign_xor_1(x_sub_ie);

        Matrixint64 b2 = Secret_Cmp::get_sign(x_plus_ie);

        Matrixint64 b2_xor_1 = Secret_Cmp::get_sign_xor_1(x_plus_ie);

        Matrixint64 k1, b2_xor_1_plus_k2, b2_xor_1_plus_k3;
        if (row == B && col == 1)
        {
            k1 = Secret_Mul::m0_1;
        }
        tel.receive(&b2_xor_1_plus_k2, 2);
        tel.receive(&b2_xor_1_plus_k3, 3);
        Matrixint64 b2_xor_1_1 = 2 * b2_xor_1_plus_k2 + b2_xor_1_plus_k2 - k1;
        tel.send(&b2_xor_1_1, 1);
        Matrixint64 temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        Matrixint64 result1 = Secret_Mul::CwiseProduct(temp, x_sub_ie, r, q, t);
        result = result1 + b2_xor_1;
    }
    else if (party == 2)
    {
        Matrixint64 r(row, col), q(row, col), t(row, col);
        Matrixint64 b1_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        Matrixint64 b2 = Secret_Cmp::get_sign(x);
        Matrixint64 b2_xor_1 = Secret_Cmp::get_sign_xor_1(x);

        Matrixint64 k2;
        if (row == B && col == 1)
        {
            k2 = Secret_Mul::m0_2;
        }
        Matrixint64 b2_xor_1_plus_k = b2_xor_1 + k2;
        tel.send(&b2_xor_1_plus_k, 0);
        Matrixint64 temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        Matrixint64 result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    else if (party == 3)
    {
        Matrixint64 r(row, col), q(row, col), t(row, col);
        Matrixint64 b1_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        Matrixint64 b2 = Secret_Cmp::get_sign(x);
        Matrixint64 b2_xor_1 = Secret_Cmp::get_sign_xor_1(x);
        Matrixint64 k3;
        if (row == B && col == 1)
        {
            k3 = Secret_Mul::m0_3;
        }
        Matrixint64 b2_xor_1_plus_k = b2_xor_1 + k3;
        tel.send(&b2_xor_1_plus_k, 0);
        Matrixint64 temp = Secret_Mul::CwiseProduct(b1_xor_1, b2, r, q, t);
        Matrixint64 result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    else if (party == 1)
    {
        Matrixint64 b2_xor_1(row, col), temp(row, col);
        Matrixint64 r(row, col), q(row, col), t(row, col);
        tel.receive(&b2_xor_1, 0);
        Matrixint64 result1 = Secret_Mul::CwiseProduct(temp, x, r, q, t);
        result = result1 + b2_xor_1;
    }
    return result;
}