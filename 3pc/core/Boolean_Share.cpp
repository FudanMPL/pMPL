#include "Secret_Mul.h"
#include "Secret_Cmp.h"

// Matrix8 Boolean_Share::a = Matrix8(B, 1);
// Matrix8 Boolean_Share::b = Matrix8(B, 1);
// Matrix8 Boolean_Share::c = Matrix8(B, 1);

// Matrix8 Boolean_Share::r_add_share = Matrix8(B, 1);
// Matrix8 Boolean_Share::r_bool_share = Matrix8(B, 1);

Matrixint64 Boolean_Share::secret_share(Matrixint64 &share)
{
    vector<Matrixint64> sec_share;
    Matrixint64 temp = Mat::randomMatrixint64(B, D);
    Matrixint64 truth = temp;
    // cout << "The truth:" << endl
    //      << temp << endl;
    for (int i = 0; i < 2; i++)
    {
        Matrixint64 noise = Mat::randomMatrixint64(B, D);
        sec_share.push_back(noise);
        temp = Mat::op_Xor(temp, noise);
    }
    sec_share.push_back(temp);
    share = sec_share[party];
    // cout << "share:" << endl
    //      << share << endl;
    return truth;
}

Matrix8 Boolean_Share::secret_share(Matrix8 &share)
{
    vector<Matrix8> sec_share;
    Matrix8 temp = Mat::randomMatrix8(B, D);
    Matrix8 truth = temp;
    // cout << "The truth:" << endl
    //      << temp << endl;
    for (int i = 0; i < 2; i++)
    {
        Matrix8 noise = Mat::randomMatrix8(B, D);
        sec_share.push_back(noise);
        temp = Mat::op_Xor(temp, noise);
    }
    sec_share.push_back(temp);
    share = sec_share[party];
    return truth;
}

Matrixint64 Boolean_Share::reveal(Matrixint64 &share)
{
    Matrixint64 result;
    if (party == 0)
    {
        Matrixint64 share2, share3;
        tel.receive(&share2, 2);
        tel.receive(&share3, 3);
        Matrixint64 result1 = Mat::op_Xor(share, share2);
        result = Mat::op_Xor(result1, share3);
        tel.send(&result, 2);
        tel.send(&result, 3);
    }
    else if (party == 2 || party == 3)
    {
        tel.send(&share, 0);
        tel.receive(&result, 0);
    }
    return result;
}

Matrix8 Boolean_Share::reveal(Matrix8 &share)
{
    Matrix8 result;
    if (party == 0)
    {
        Matrix8 share2, share3;
        tel.receive(&share2, 2);
        tel.receive(&share3, 3);
        Matrix8 result1 = Mat::op_Xor(share, share2);
        result = Mat::op_Xor(result1, share3);
        tel.send(&result, 2);
        tel.send(&result, 3);
    }
    else if (party == 2 || party == 3)
    {
        tel.send(&share, 0);
        tel.receive(&result, 0);
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     Matrix8 recv;
    //     if (i != party)
    //     {
    //         tel.send(&share, i);
    //         tel.receive(&recv, i);
    //         result = Mat::op_Xor(result, recv);
    //     }
    // }
    return result;
}

Matrixint64 Boolean_Share::add_reveal(Matrixint64 &share)
{
    Matrixint64 result = share;
    // cout <<"share:"<< share << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i != party)
        {
            Matrixint64 recv;
            tel.send(&share, i);
            tel.receive(&recv, i);
            result += recv;
        }
    }
    return result;
}

// void Boolean_Share::get_byte_and_triplets()
// {
//     a.setZero();
//     b.setZero();
//     c.setZero();
// }

// void Boolean_Share::get_n_dabits()
// {
//     r_add_share.setZero();
//     r_bool_share.setZero();
// }
Matrix8 Boolean_Share::byte_and_byte(Matrix8 &x, Matrix8 &y)
{
    int row = x.rows(), col = x.cols();
    Matrix8 a(row, col), b(row, col), c(row, col);
    a.setZero();
    b.setZero();
    c.setZero();
    Matrix8 s_share = Mat::op_Xor(x, a);
    Matrix8 t_share = Mat::op_Xor(y, b);
    Matrix8 s = Boolean_Share::reveal(s_share);
    Matrix8 t = Boolean_Share::reveal(t_share);
    if (party == 0)
    {
        Matrix8 temp1 = Mat::op_And(s, t);
        Matrix8 temp2 = Mat::op_And(s, b);
        Matrix8 temp3 = Mat::op_And(t, a);
        Matrix8 res1 = Mat::op_Xor(temp1, temp2);
        Matrix8 res2 = Mat::op_Xor(temp3, c);
        return Mat::op_Xor(res1, res2);
    }
    else
    {
        Matrix8 temp1 = Mat::op_And(s, b);
        Matrix8 temp2 = Mat::op_And(t, a);
        Matrix8 temp3 = Mat::op_Xor(temp1, temp2);
        return Mat::op_Xor(temp3, c);
    }
}

Matrixint64 Boolean_Share::bool_and(Matrixint64 &x, Matrixint64 &y)
{
    int row = x.rows(), col = x.cols();
    Matrixint64 a(row, col), b(row, col), c(row, col);
    a.setZero();
    b.setZero();
    c.setZero();
    Matrixint64 s_share = Mat::op_Xor(x, a);
    Matrixint64 t_share = Mat::op_Xor(y, b);
    Matrixint64 s = Boolean_Share::reveal(s_share);
    Matrixint64 t = Boolean_Share::reveal(t_share);
    if (party == 0)
    {
        Matrixint64 temp1 = Mat::op_And(s, t);
        Matrixint64 temp2 = Mat::op_And(s, b);
        Matrixint64 temp3 = Mat::op_And(t, a);
        Matrixint64 res1 = Mat::op_Xor(temp1, temp2);
        Matrixint64 res2 = Mat::op_Xor(temp3, c);
        return Mat::op_Xor(res1, res2);
    }
    else
    {
        Matrixint64 temp1 = Mat::op_And(s, b);
        Matrixint64 temp2 = Mat::op_And(t, a);
        Matrixint64 temp3 = Mat::op_Xor(temp1, temp2);
        return Mat::op_Xor(temp3, c);
    }
}


Matrixint64 Boolean_Share::add(Matrixint64 &x, Matrixint64 &y)
{
    int row = x.rows();
    int col = x.cols();
    Matrixint64 G(row, col), P(row, col), temp(row, col), c_mask(row, col), k_mask(row, col), G1(row, col), P1(row, col), C(row, col);
    temp.setOnes();
    Matrixint64 keep_masks(6, 1);
    keep_masks << 0x5555555555555555,
        0x3333333333333333,
        0x0F0F0F0F0F0F0F0F,
        0x00FF00FF00FF00FF,
        0x0000FFFF0000FFFF,
        0x00000000FFFFFFFF;
    Matrixint64 copy_masks(6, 1);
    copy_masks << 0x5555555555555555,
        0x2222222222222222,
        0x0808080808080808,
        0x0080008000800080,
        0x0000800000008000,
        0x0000000080000000;
    G = Boolean_Share::bool_and(x, y);
    P = Mat::op_Xor(x, y);
    for (int i = 0; i < 6; i++)
    {
        c_mask = temp * copy_masks(i);
        k_mask = temp * keep_masks(i);
        G1 = Mat::op_shift_left(Mat::op_And(G, c_mask), 1);
        P1 = Mat::op_shift_left(Mat::op_And(P, c_mask), 1);
        for (int j = 0; j < i; j++)
        {
            G1 = Mat::op_Xor(Mat::op_shift_left(G1, int(pow(2, j))), G1);
            P1 = Mat::op_Xor(Mat::op_shift_left(P1, int(pow(2, j))), P1);
        }
        P1 = Mat::op_Xor(P1, k_mask);
        G = Mat::op_Xor(G, Boolean_Share::bool_and(P, G1));
        P = Boolean_Share::bool_and(P, P1);
    }
    C = Mat::op_shift_left(G, 1);
    P = Mat::op_Xor(x, y);
    return Mat::op_Xor(C, P);
}

// 采用New Primitives for Actively-Secure MPC over Rings with Applications to Private Machine Learning论文中的b2a的方法
// [x]  = c + [r] + 2 * c * [r]
//为了减少通信使用int8(只转换符号位)

Matrixint64 Boolean_Share::to_additive_share(Matrixint64 &x)
{
    int row = x.rows();
    int col = x.cols();
    Matrix8 r_add_share(row, col), r_bool_share(row, col);
    r_add_share.setZero();
    r_bool_share.setZero();
    Matrix8 x_byte = x.cast<u8>();
    Matrix8 c = Mat::op_Xor(r_bool_share, x_byte);
    c = Boolean_Share::reveal(c);
    Matrix8 add_val_byte(row, col);
    Matrixint64 add_val(row, col);
    add_val_byte.setZero();
    Matrix8 ci = Mat::op_And(1, c);
    if (party == 0)
    {
        Matrix8 temp = ci + r_add_share - 2 * ci.cwiseProduct(r_add_share);
        add_val_byte = add_val_byte + temp;
    }
    else
    {
        Matrix8 temp = r_add_share - 2 * ci.cwiseProduct(r_add_share);
        add_val_byte = add_val_byte + temp;
    }
    add_val = add_val_byte.cast<int64>();
    return add_val;
}

Matrixint64 Boolean_Share::secret_share_for_test(Matrixint64 &share)
{
    Matrixint64 A_plus_mat = Mat::toMatrix(Mat::A_plus);
    // Matrixint64 truth = Mat::randomMatrixint64(B, D);
    Matrixint64 truth(B, D);
    truth << 8112345678912345678ull;
    Matrixint64 temp(B, D);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < D; j++)
        {
            Matrixint64 temp_vector(3, 1);
            temp_vector << truth(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp1 = A_plus_mat.row(party) * temp_vector;
            temp(i, j) = temp1(0, 0);
        }
    }
    share = temp;
    return truth;
}

Matrixint64 add_secret_share(Matrixint64 &share)
{
    vector<Matrixint64> sec_share;
    Matrixint64 temp = Mat::randomMatrixint64(B, D);
    Matrixint64 truth = temp;
    // cout << "The truth:" << endl
    //      << temp << endl;
    for (int i = 0; i < 2; i++)
    {
        Matrixint64 noise = Mat::randomMatrixint64(B, D);
        sec_share.push_back(noise);
        temp -= noise;
    }
    sec_share.push_back(temp);
    share = sec_share[party];
    // cout << "share:" << endl
    //      << share << endl;
    return truth;
}

void Boolean_Share::test()
{
    // // test for byte and byte

    // Matrix8 share1(B, D), share2(B, D);
    // Matrix8 truth1_u8 = Boolean_Share::secret_share(share1);
    // Matrix8 truth2_u8 = Boolean_Share::secret_share(share2);
    // Matrixint64 truth1 = truth1_u8.cast<int64>();
    // Matrixint64 truth2 = truth2_u8.cast<int64>();
    // cout << "The truth1:" << endl
    //      << truth1 << endl;
    // cout << "The truth2:" << endl
    //      << truth2 << endl;
    // Matrix8 truth_u8 = Mat::op_And(truth1_u8, truth2_u8);
    // Matrixint64 truth = truth_u8.cast<int64>();
    // Matrix8 share = Boolean_Share::byte_and_byte(share1, share2);
    // Matrix8 result_u8 = Boolean_Share::reveal(share);
    // Matrixint64 result = result_u8.cast<int64>();
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // cout << "The reveal result:" << endl
    //      << result << endl;
    // if (truth == result)
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    // // test for add
    // Matrixint64 share1(B, D), share2(B, D);
    // Matrixint64 truth1 = Boolean_Share::secret_share(share1);
    // Matrixint64 truth2 = Boolean_Share::secret_share(share2);
    // Matrixint64 truth = truth1 + truth2;
    // Matrixint64 share = Boolean_Share::add(share1, share2);
    // Matrixint64 result = Boolean_Share::reveal(share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // cout << "The reveal result:" << endl
    //      << result << endl;
    // if (truth == result)
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    // // test for B2A(由于只写了bool_share为1bit时的转换 因此秘密分享时真实值只能为0或1)
    // Matrixint64 bool_share(B, D);
    // Matrixint64 truth = Boolean_Share::secret_share(bool_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // // cout << bool_share <<endl;
    // Matrixint64 add_share = Boolean_Share::to_additive_share(bool_share);
    // Matrixint64 result = Boolean_Share::add_reveal(add_share);
    // cout << "The reveal result:" << endl
    //      << result << endl;
    // if (truth == result)
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    // // test for A2B
    // Matrixint64 vector_share(B, D);
    // Matrixint64 truth = Boolean_Share::secret_share_for_test(vector_share);
    // cout << "share:" << vector_share << endl;
    // // Matrixint64 add_share(B, D);
    // // Matrixint64 truth = add_secret_share(add_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // Matrixint64 bool_share = Secret_Cmp::to_Boolean_Share(vector_share);
    // Matrixint64 result = Boolean_Share::reveal(bool_share);
    // // Matrixint64 result = Secret_Mul::reveal(vector_share);
    // cout << "The reveal result:" << endl
    //      << result << endl;
    // if (truth == result)
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    // // test for comparison
    // Matrixint64 vector_share(B, D);
    // Matrixint64 truth = Boolean_Share::secret_share_for_test(vector_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // Matrixint64 sign_share = Secret_Cmp::get_sign(vector_share);
    // // cout << "sign_share:" << sign_share << endl;
    // Matrixint64 sign = Secret_Mul::reveal(sign_share);
    // cout << "The reveal result:" << endl
    //      << sign << endl;

    // // test for relu
    // Matrixint64 vector_share(B, D);
    // Matrixint64 truth = secret_share_for_test(vector_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // Matrixint64 relu_share = Secret_Cmp::Relu(vector_share);
    // Matrixint64 result = Secret_Mul::reveal(relu_share);
    // cout << "The reveal result:" << endl
    //      << result << endl;

    // // test for sigmoid
    // Matrixint64 vector_share(B, D);
    // Matrixint64 truth = secret_share_for_test(vector_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // Matrixint64 relu_share = Secret_Cmp::Sigmoid(vector_share);
    // Matrixint64 result = Secret_Mul::reveal(relu_share);
    // cout << "The reveal result:" << endl
    //      << result << endl;
}