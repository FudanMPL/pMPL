#include "Secret_Mul.h"
#include "Secret_Cmp.h"

// Matrix8 Boolean_Share::a = Matrix8(B, 1);
// Matrix8 Boolean_Share::b = Matrix8(B, 1);
// Matrix8 Boolean_Share::c = Matrix8(B, 1);

// Matrix8 Boolean_Share::r_add_share = Matrix8(B, 1);
// Matrix8 Boolean_Share::r_bool_share = Matrix8(B, 1);

MatrixXu Boolean_Share::r0_0 = MatrixXu(B + B, numClass);
MatrixXu Boolean_Share::r0_1 = MatrixXu(B + B, numClass);
MatrixXu Boolean_Share::r0_2 = MatrixXu(B + B, numClass);
MatrixXu Boolean_Share::r_00 = MatrixXu(B + B, numClass);
MatrixXu Boolean_Share::r_01 = MatrixXu(B + B, numClass);
MatrixXu Boolean_Share::r_02 = MatrixXu(B + B, numClass);

MatrixXu Boolean_Share::r1_0 = MatrixXu(B, hiddenDim);
MatrixXu Boolean_Share::r1_1 = MatrixXu(B, hiddenDim);
MatrixXu Boolean_Share::r1_2 = MatrixXu(B, hiddenDim);
MatrixXu Boolean_Share::r_10 = MatrixXu(B, hiddenDim);
MatrixXu Boolean_Share::r_11 = MatrixXu(B, hiddenDim);
MatrixXu Boolean_Share::r_12 = MatrixXu(B, hiddenDim);

void Boolean_Share::init()
{
    MatrixXu sec_share0[3], sec_share1[3];
    MatrixXu r0 = Mat::randomMatrixXu(B + B, numClass);
    MatrixXu r1 = Mat::randomMatrixXu(B, hiddenDim);
    MatrixXu temp_r0 = r0, temp_r1 = r1;
    for (int i = 0; i < 2; i++)
    {
        MatrixXu noise0 = Mat::randomMatrixXu(B + B, numClass);
        sec_share0[i] = noise0;
        r0 = Mat::op_Xor(r0, noise0);
        MatrixXu noise1 = Mat::randomMatrixXu(B, hiddenDim);
        sec_share1[i] = noise1;
        r1 = Mat::op_Xor(r1, noise1);
    }
    sec_share0[2] = r0;
    sec_share1[2] = r1;
    r0_0 = sec_share0[0];
    r0_1 = sec_share0[1];
    r0_2 = sec_share0[2];
    r1_0 = sec_share1[0];
    r1_1 = sec_share1[1];
    r1_2 = sec_share1[2];

    MatrixXu sec_share_0[3], sec_share_1[3];
    for (int i = 0; i < 2; i++)
    {
        MatrixXu noise0 = Mat::randomMatrixXu(B + B, numClass);
        sec_share_0[i] = noise0;
        temp_r0 = temp_r0 - noise0;
        MatrixXu noise1 = Mat::randomMatrixXu(B, hiddenDim);
        sec_share_1[i] = noise1;
        temp_r1 = temp_r1 - noise1;
    }
    sec_share_0[2] = temp_r0;
    sec_share_1[2] = temp_r1;
    r_00 = sec_share_0[0];
    r_01 = sec_share_0[1];
    r_02 = sec_share_0[2];
    r_10 = sec_share_1[0];
    r_11 = sec_share_1[1];
    r_12 = sec_share_1[2];
}

MatrixXu Boolean_Share::secret_share(MatrixXu &share)
{
    vector<MatrixXu> sec_share;
    MatrixXu temp = Mat::randomMatrixXu(B, D);
    MatrixXu truth = temp;
    // cout << "The truth:" << endl
    //      << temp << endl;
    for (int i = 0; i < 2; i++)
    {
        MatrixXu noise = Mat::randomMatrixXu(B, D);
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

MatrixXu Boolean_Share::reveal(MatrixXu &share)
{
    MatrixXu result;
    if (party == 0)
    {
        MatrixXu share2, share3;
        tel.receive(&share2, 2);
        tel.receive(&share3, 3);
        MatrixXu result1 = Mat::op_Xor(share, share2);
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

MatrixXu Boolean_Share::add_reveal(MatrixXu &share)
{
    MatrixXu result;
    if (party == 0)
    {
        MatrixXu share1, share2;
        tel.receive(&share1, 2);
        tel.receive(&share2, 3);
        result = share + share1 + share2;
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

MatrixXu Boolean_Share::bool_and(MatrixXu &x, MatrixXu &y)
{
    int row = x.rows(), col = x.cols();
    MatrixXu a(row, col), b(row, col), c(row, col);
    a.setZero();
    b.setZero();
    c.setZero();
    MatrixXu s_share = Mat::op_Xor(x, a);
    MatrixXu t_share = Mat::op_Xor(y, b);
    MatrixXu s = Boolean_Share::reveal(s_share);
    MatrixXu t = Boolean_Share::reveal(t_share);
    if (party == 0)
    {
        MatrixXu temp1 = Mat::op_And(s, t);
        MatrixXu temp2 = Mat::op_And(s, b);
        MatrixXu temp3 = Mat::op_And(t, a);
        MatrixXu res1 = Mat::op_Xor(temp1, temp2);
        MatrixXu res2 = Mat::op_Xor(temp3, c);
        return Mat::op_Xor(res1, res2);
    }
    else
    {
        MatrixXu temp1 = Mat::op_And(s, b);
        MatrixXu temp2 = Mat::op_And(t, a);
        MatrixXu temp3 = Mat::op_Xor(temp1, temp2);
        return Mat::op_Xor(temp3, c);
    }
}


MatrixXu Boolean_Share::add(MatrixXu &x, MatrixXu &y)
{
    int row = x.rows();
    int col = x.cols();
    MatrixXu G(row, col), P(row, col), temp(row, col), c_mask(row, col), k_mask(row, col), G1(row, col), P1(row, col), C(row, col);
    temp.setOnes();
    MatrixXu keep_masks(6, 1);
    keep_masks << 0x5555555555555555,
        0x3333333333333333,
        0x0F0F0F0F0F0F0F0F,
        0x00FF00FF00FF00FF,
        0x0000FFFF0000FFFF,
        0x00000000FFFFFFFF;
    MatrixXu copy_masks(6, 1);
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

MatrixXu Boolean_Share::to_additive_share(MatrixXu &x)
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
    MatrixXu add_val(row, col);
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
    add_val = add_val_byte.cast<u64>();
    return add_val;
}

MatrixXu Boolean_Share::secret_share_for_test(MatrixXu &share)
{
    MatrixXu A_plus_mat = Mat::toMatrix(Mat::A_plus);
    // MatrixXu truth = Mat::randomMatrixXu(B, D);
    MatrixXu truth(B, D);
    truth << 8112345678912345678ull;
    MatrixXu temp(B, D);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < D; j++)
        {
            MatrixXu temp_vector(3, 1);
            temp_vector << truth(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp1 = A_plus_mat.row(party) * temp_vector;
            temp(i, j) = temp1(0, 0);
        }
    }
    share = temp;
    return truth;
}

MatrixXu add_secret_share(MatrixXu &share)
{
    vector<MatrixXu> sec_share;
    MatrixXu temp = Mat::randomMatrixXu(B, D);
    MatrixXu truth = temp;
    // cout << "The truth:" << endl
    //      << temp << endl;
    for (int i = 0; i < 2; i++)
    {
        MatrixXu noise = Mat::randomMatrixXu(B, D);
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
    // MatrixXu truth1 = truth1_u8.cast<u64>();
    // MatrixXu truth2 = truth2_u8.cast<u64>();
    // cout << "The truth1:" << endl
    //      << truth1 << endl;
    // cout << "The truth2:" << endl
    //      << truth2 << endl;
    // Matrix8 truth_u8 = Mat::op_And(truth1_u8, truth2_u8);
    // MatrixXu truth = truth_u8.cast<u64>();
    // Matrix8 share = Boolean_Share::byte_and_byte(share1, share2);
    // Matrix8 result_u8 = Boolean_Share::reveal(share);
    // MatrixXu result = result_u8.cast<u64>();
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
    // MatrixXu share1(B, D), share2(B, D);
    // MatrixXu truth1 = Boolean_Share::secret_share(share1);
    // MatrixXu truth2 = Boolean_Share::secret_share(share2);
    // MatrixXu truth = truth1 + truth2;
    // MatrixXu share = Boolean_Share::add(share1, share2);
    // MatrixXu result = Boolean_Share::reveal(share);
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
    // MatrixXu bool_share(B, D);
    // MatrixXu truth = Boolean_Share::secret_share(bool_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // // cout << bool_share <<endl;
    // MatrixXu add_share = Boolean_Share::to_additive_share(bool_share);
    // MatrixXu result = Boolean_Share::add_reveal(add_share);
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
    // MatrixXu vector_share(B, D);
    // MatrixXu truth = Boolean_Share::secret_share_for_test(vector_share);
    // cout << "share:" << vector_share << endl;
    // // MatrixXu add_share(B, D);
    // // MatrixXu truth = add_secret_share(add_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // MatrixXu bool_share = Secret_Cmp::to_Boolean_Share(vector_share);
    // MatrixXu result = Boolean_Share::reveal(bool_share);
    // // MatrixXu result = Secret_Mul::reveal(vector_share);
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
    // MatrixXu vector_share(B, D);
    // MatrixXu truth = Boolean_Share::secret_share_for_test(vector_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // MatrixXu sign_share = Secret_Cmp::get_sign(vector_share);
    // // cout << "sign_share:" << sign_share << endl;
    // MatrixXu sign = Secret_Mul::reveal(sign_share);
    // cout << "The reveal result:" << endl
    //      << sign << endl;

    // // test for relu
    // MatrixXu vector_share(B, D);
    // MatrixXu truth = secret_share_for_test(vector_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // MatrixXu relu_share = Secret_Cmp::Relu(vector_share);
    // MatrixXu result = Secret_Mul::reveal(relu_share);
    // cout << "The reveal result:" << endl
    //      << result << endl;

    // // test for sigmoid
    // MatrixXu vector_share(B, D);
    // MatrixXu truth = secret_share_for_test(vector_share);
    // cout << "The truth result:" << endl
    //      << truth << endl;
    // MatrixXu relu_share = Secret_Cmp::Sigmoid(vector_share);
    // MatrixXu result = Secret_Mul::reveal(relu_share);
    // cout << "The reveal result:" << endl
    //      << result << endl;
}