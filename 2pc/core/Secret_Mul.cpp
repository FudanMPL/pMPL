#include "Secret_Mul.h"
// Multiply_Triplets(for(B, D)X(D, 1))
Matrixint64 Secret_Mul::b0_1 = Matrixint64(B, D);
Matrixint64 Secret_Mul::b0_2 = Matrixint64(B, D);
Matrixint64 Secret_Mul::b0_3 = Matrixint64(B, D);
Matrixint64 Secret_Mul::c0_1 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::c0_2 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::c0_3 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::d0_1 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::d0_2 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::d0_3 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::r0 = Matrixint64(B, D);
Matrixint64 Secret_Mul::q0 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::t0 = Matrixint64(B, 1);

// Multiply_Triplets(for(D, B)X(B, 1))
Matrixint64 Secret_Mul::b1_1 = Matrixint64(D, B);
Matrixint64 Secret_Mul::b1_2 = Matrixint64(D, B);
Matrixint64 Secret_Mul::b1_3 = Matrixint64(D, B);
Matrixint64 Secret_Mul::c1_1 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::c1_2 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::c1_3 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::d1_1 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::d1_2 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::d1_3 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::r1 = Matrixint64(D, B);
Matrixint64 Secret_Mul::q1 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::t1 = Matrixint64(D, 1);

// Multiply_Triplets(for(B, D)X(D, hiddenDim))
Matrixint64 Secret_Mul::b2_1 = Matrixint64(B, D);
Matrixint64 Secret_Mul::b2_2 = Matrixint64(B, D);
Matrixint64 Secret_Mul::b2_3 = Matrixint64(B, D);
Matrixint64 Secret_Mul::c2_1 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::c2_2 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::c2_3 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::d2_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d2_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d2_3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::r2 = Matrixint64(B, D);
Matrixint64 Secret_Mul::q2 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::t2 = Matrixint64(B, hiddenDim);

// Multiply_Triplets(for(B, hiddenDim)X(hiddenDim, 1))
Matrixint64 Secret_Mul::b3_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::b3_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::b3_3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::c3_1 = Matrixint64(hiddenDim, 1);
Matrixint64 Secret_Mul::c3_2 = Matrixint64(hiddenDim, 1);
Matrixint64 Secret_Mul::c3_3 = Matrixint64(hiddenDim, 1);
Matrixint64 Secret_Mul::d3_1 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::d3_2 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::d3_3 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::r3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::q3 = Matrixint64(hiddenDim, 1);
Matrixint64 Secret_Mul::t3 = Matrixint64(B, 1);

// Multiply_Triplets(for(B, 1)X(1, hiddenDim))
Matrixint64 Secret_Mul::b4_1 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::b4_2 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::b4_3 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::c4_1 = Matrixint64(1, hiddenDim);
Matrixint64 Secret_Mul::c4_2 = Matrixint64(1, hiddenDim);
Matrixint64 Secret_Mul::c4_3 = Matrixint64(1, hiddenDim);
Matrixint64 Secret_Mul::d4_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d4_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d4_3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::r4 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::q4 = Matrixint64(1, hiddenDim);
Matrixint64 Secret_Mul::t4 = Matrixint64(B, hiddenDim);

// Multiply_Triplets(for(B, hiddenDim)X(hiddenDim, hiddenDim))
Matrixint64 Secret_Mul::b5_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::b5_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::b5_3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::c5_1 = Matrixint64(hiddenDim, hiddenDim);
Matrixint64 Secret_Mul::c5_2 = Matrixint64(hiddenDim, hiddenDim);
Matrixint64 Secret_Mul::c5_3 = Matrixint64(hiddenDim, hiddenDim);
Matrixint64 Secret_Mul::d5_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d5_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d5_3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::r5 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::q5 = Matrixint64(hiddenDim, hiddenDim);
Matrixint64 Secret_Mul::t5 = Matrixint64(B, hiddenDim);

// Multiply_Triplets(for(D, B)X(B, hiddenDim))
Matrixint64 Secret_Mul::b6_1 = Matrixint64(D, B);
Matrixint64 Secret_Mul::b6_2 = Matrixint64(D, B);
Matrixint64 Secret_Mul::b6_3 = Matrixint64(D, B);
Matrixint64 Secret_Mul::c6_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::c6_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::c6_3 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::d6_1 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::d6_2 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::d6_3 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::r6 = Matrixint64(D, B);
Matrixint64 Secret_Mul::q6 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::t6 = Matrixint64(D, hiddenDim);

Matrixint64 Secret_Mul::m0_0 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::m0_1 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::m0_2 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::m0_3 = Matrixint64(B, 1);

Matrixint64 Secret_Mul::m_00 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::m_01 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::m_02 = Matrixint64(B, 1);
Matrixint64 Secret_Mul::m_03 = Matrixint64(B, 1);

Matrixint64 Secret_Mul::m1_0 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::m1_1 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::m1_2 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::m1_3 = Matrixint64(D, 1);

Matrixint64 Secret_Mul::m_10 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::m_11 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::m_12 = Matrixint64(D, 1);
Matrixint64 Secret_Mul::m_13 = Matrixint64(D, 1);

Matrixint64 Secret_Mul::m2_0 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::m2_1 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::m2_2 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::m2_3 = Matrixint64(B, hiddenDim);

Matrixint64 Secret_Mul::m_20 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::m_21 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::m_22 = Matrixint64(B, hiddenDim);
Matrixint64 Secret_Mul::m_23 = Matrixint64(B, hiddenDim);

Matrixint64 Secret_Mul::m3_0 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::m3_1 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::m3_2 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::m3_3 = Matrixint64(D, hiddenDim);

Matrixint64 Secret_Mul::m_30 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::m_31 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::m_32 = Matrixint64(D, hiddenDim);
Matrixint64 Secret_Mul::m_33 = Matrixint64(D, hiddenDim);

void Secret_Mul::init()
{
    // for (B, D)X(D, 1)
    b0_1 = Mat::randomMatrixint64(B, D);
    b0_2 = Mat::randomMatrixint64(B, D);
    b0_3 = Mat::randomMatrixint64(B, D);
    c0_1 = Mat::randomMatrixint64(D, 1);
    c0_2 = Mat::randomMatrixint64(D, 1);
    c0_3 = Mat::randomMatrixint64(D, 1);
    d0_1 = b0_1 * c0_1;

    d0_2 = Mat::randomMatrixint64(B, 1);
    d0_3 = Mat::randomMatrixint64(B, 1);
    Tensor<int64, 3> b0(3, B, D);
    for (int j = 0; j < D; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b0(0, i, j) = b0_1(i, j);
            b0(1, i, j) = b0_2(i, j);
            b0(2, i, j) = b0_3(i, j);
        }
    }
    Tensor<int64, 3> c0(3, D, 1);
    for (int i = 0; i < D; i++)
    {
        c0(0, i, 0) = c0_1(i, 0);
        c0(1, i, 0) = c0_2(i, 0);
        c0(2, i, 0) = c0_3(i, 0);
    }
    Tensor<int64, 3> d0(3, B, 1);
    for (int i = 0; i < B; i++)
    {
        d0(0, i, 0) = d0_1(i, 0);
        d0(1, i, 0) = d0_2(i, 0);
        d0(2, i, 0) = d0_3(i, 0);
    }
    Tensor<int64, 3> r0, q0, t0;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims1 = {Eigen::IndexPair<int64>(1, 0)};
    r0 = Mat::A_plus.contract(b0, product_dims1);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims2 = {Eigen::IndexPair<int64>(1, 0)};
    q0 = Mat::A_plus.contract(c0, product_dims2);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims3 = {Eigen::IndexPair<int64>(1, 0)};
    t0 = Mat::A_plus.contract(d0, product_dims3);

    ofstream F0_0, F0_1, F0_2, F0_3;
    F0_0.open("Mul_Triplets/MT0_0.txt");
    F0_1.open("Mul_Triplets/MT0_1.txt");
    F0_2.open("Mul_Triplets/MT0_2.txt");
    F0_3.open("Mul_Triplets/MT0_3.txt");
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < D; j++)
        {
            F0_0 << r0(0, i, j) << ',';
            F0_1 << r0(1, i, j) << ',';
            F0_2 << r0(2, i, j) << ',';
            F0_3 << r0(3, i, j) << ',';
        }
        F0_0 << std::endl;
        F0_1 << std::endl;
        F0_2 << std::endl;
        F0_3 << std::endl;
    }
    for (int i = 0; i < D; i++)
    {
        F0_0 << q0(0, i, 0) << ',' << endl;
        F0_1 << q0(1, i, 0) << ',' << endl;
        F0_2 << q0(2, i, 0) << ',' << endl;
        F0_3 << q0(3, i, 0) << ',' << endl;
    }
    for (int i = 0; i < B; i++)
    {
        F0_0 << t0(0, i, 0) << ',' << endl;
        F0_1 << t0(1, i, 0) << ',' << endl;
        F0_2 << t0(2, i, 0) << ',' << endl;
        F0_3 << t0(3, i, 0) << ',' << endl;
    }
    F0_0.close();
    F0_1.close();
    F0_2.close();
    F0_3.close();

    // for (D, B)X(B, 1)
    b1_1 = Mat::randomMatrixint64(D, B);
    b1_2 = Mat::randomMatrixint64(D, B);
    b1_3 = Mat::randomMatrixint64(D, B);
    c1_1 = Mat::randomMatrixint64(B, 1);
    c1_2 = Mat::randomMatrixint64(B, 1);
    c1_3 = Mat::randomMatrixint64(B, 1);
    d1_1 = b1_1 * c1_1;
    d1_2 = Mat::randomMatrixint64(D, 1);
    d1_3 = Mat::randomMatrixint64(D, 1);
    Tensor<int64, 3> b1(3, D, B);
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < D; i++)
        {
            b1(0, i, j) = b1_1(i, j);
            b1(1, i, j) = b1_2(i, j);
            b1(2, i, j) = b1_3(i, j);
        }
    }
    Tensor<int64, 3> c1(3, B, 1);
    for (int i = 0; i < B; i++)
    {
        c1(0, i, 0) = c1_1(i, 0);
        c1(1, i, 0) = c1_2(i, 0);
        c1(2, i, 0) = c1_3(i, 0);
    }
    Tensor<int64, 3> d1(3, D, 1);
    for (int i = 0; i < D; i++)
    {
        d1(0, i, 0) = d1_1(i, 0);
        d1(1, i, 0) = d1_2(i, 0);
        d1(2, i, 0) = d1_3(i, 0);
    }
    Tensor<int64, 3> r1, q1, t1;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims4 = {Eigen::IndexPair<int64>(1, 0)};
    r1 = Mat::A_plus.contract(b1, product_dims4);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims5 = {Eigen::IndexPair<int64>(1, 0)};
    q1 = Mat::A_plus.contract(c1, product_dims5);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims6 = {Eigen::IndexPair<int64>(1, 0)};
    t1 = Mat::A_plus.contract(d1, product_dims6);
    ofstream F1_0, F1_1, F1_2, F1_3;
    F1_0.open("Mul_Triplets/MT1_0.txt");
    F1_1.open("Mul_Triplets/MT1_1.txt");
    F1_2.open("Mul_Triplets/MT1_2.txt");
    F1_3.open("Mul_Triplets/MT1_3.txt");
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < B; j++)
        {
            F1_0 << r1(0, i, j) << ',';
            F1_1 << r1(1, i, j) << ',';
            F1_2 << r1(2, i, j) << ',';
            F1_3 << r1(3, i, j) << ',';
        }
        F1_0 << std::endl;
        F1_1 << std::endl;
        F1_2 << std::endl;
        F1_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        F1_0 << q1(0, i, 0) << ',' << endl;
        F1_1 << q1(1, i, 0) << ',' << endl;
        F1_2 << q1(2, i, 0) << ',' << endl;
        F1_3 << q1(3, i, 0) << ',' << endl;
    }
    for (int i = 0; i < D; i++)
    {
        F1_0 << t1(0, i, 0) << ',' << endl;
        F1_1 << t1(1, i, 0) << ',' << endl;
        F1_2 << t1(2, i, 0) << ',' << endl;
        F1_3 << t1(3, i, 0) << ',' << endl;
    }
    F1_0.close();
    F1_1.close();
    F1_2.close();
    F1_3.close();

    // for(B, D)X(D, hiddenDim)
    b2_1 = Mat::randomMatrixint64(B, D);
    b2_2 = Mat::randomMatrixint64(B, D);
    b2_3 = Mat::randomMatrixint64(B, D);
    c2_1 = Mat::randomMatrixint64(D, hiddenDim);
    c2_2 = Mat::randomMatrixint64(D, hiddenDim);
    c2_3 = Mat::randomMatrixint64(D, hiddenDim);
    d2_1 = b2_1 * c2_1;
    d2_2 = Mat::randomMatrixint64(B, hiddenDim);
    d2_3 = Mat::randomMatrixint64(B, hiddenDim);
    Tensor<int64, 3> b2(3, B, D);
    for (int j = 0; j < D; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b2(0, i, j) = b2_1(i, j);
            b2(1, i, j) = b2_2(i, j);
            b2(2, i, j) = b2_3(i, j);
        }
    }
    Tensor<int64, 3> c2(3, D, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < D; i++)
        {
            c2(0, i, j) = c2_1(i, j);
            c2(1, i, j) = c2_2(i, j);
            c2(2, i, j) = c2_3(i, j);
        }
    }
    Tensor<int64, 3> d2(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            d2(0, i, j) = d2_1(i, j);
            d2(1, i, j) = d2_2(i, j);
            d2(2, i, j) = d2_3(i, j);
        }
    }

    Tensor<int64, 3> r2, q2, t2;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims7 = {Eigen::IndexPair<int64>(1, 0)};
    r2 = Mat::A_plus.contract(b2, product_dims7);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims8 = {Eigen::IndexPair<int64>(1, 0)};
    q2 = Mat::A_plus.contract(c2, product_dims8);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims9 = {Eigen::IndexPair<int64>(1, 0)};
    t2 = Mat::A_plus.contract(d2, product_dims9);
    ofstream F2_0, F2_1, F2_2, F2_3;
    F2_0.open("Mul_Triplets/MT2_0.txt");
    F2_1.open("Mul_Triplets/MT2_1.txt");
    F2_2.open("Mul_Triplets/MT2_2.txt");
    F2_3.open("Mul_Triplets/MT2_3.txt");
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < D; j++)
        {
            F2_0 << r2(0, i, j) << ',';
            F2_1 << r2(1, i, j) << ',';
            F2_2 << r2(2, i, j) << ',';
            F2_3 << r2(3, i, j) << ',';
        }
        F2_0 << std::endl;
        F2_1 << std::endl;
        F2_2 << std::endl;
        F2_3 << std::endl;
    }
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F2_0 << q2(0, i, j) << ',';
            F2_1 << q2(1, i, j) << ',';
            F2_2 << q2(2, i, j) << ',';
            F2_3 << q2(3, i, j) << ',';
        }
        F2_0 << std::endl;
        F2_1 << std::endl;
        F2_2 << std::endl;
        F2_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F2_0 << t2(0, i, j) << ',';
            F2_1 << t2(1, i, j) << ',';
            F2_2 << t2(2, i, j) << ',';
            F2_3 << t2(3, i, j) << ',';
        }
        F2_0 << std::endl;
        F2_1 << std::endl;
        F2_2 << std::endl;
        F2_3 << std::endl;
    }
    F2_0.close();
    F2_1.close();
    F2_2.close();
    F2_3.close();

    // for(B, hiddenDim)X(hiddenDim, 1)
    b3_1 = Mat::randomMatrixint64(B, hiddenDim);
    b3_2 = Mat::randomMatrixint64(B, hiddenDim);
    b3_3 = Mat::randomMatrixint64(B, hiddenDim);
    c3_1 = Mat::randomMatrixint64(hiddenDim, 1);
    c3_2 = Mat::randomMatrixint64(hiddenDim, 1);
    c3_3 = Mat::randomMatrixint64(hiddenDim, 1);
    d3_1 = b3_1 * c3_1;
    d3_2 = Mat::randomMatrixint64(B, 1);
    d3_3 = Mat::randomMatrixint64(B, 1);
    // cout <<"b3_1:"<<b3_1<<endl;
    // cout <<"b3_2:"<<b3_2<<endl;
    // cout <<"b3_3:"<<b3_3<<endl;
    // cout <<"c3_1:"<<c3_1<<endl;
    // cout <<"c3_2:"<<c3_2<<endl;
    // cout <<"c3_3:"<<c3_3<<endl;
    // cout <<"d3_1:"<<d3_1<<endl;
    // cout <<"d3_2:"<<d3_2<<endl;
    // cout <<"d3_3:"<<d3_3<<endl;
    Tensor<int64, 3> b3(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b3(0, i, j) = b3_1(i, j);
            b3(1, i, j) = b3_2(i, j);
            b3(2, i, j) = b3_3(i, j);
        }
    }
    Tensor<int64, 3> c3(3, hiddenDim, 1);
    for (int i = 0; i < hiddenDim; i++)
    {
        c3(0, i, 0) = c3_1(i, 0);
        c3(1, i, 0) = c3_2(i, 0);
        c3(2, i, 0) = c3_3(i, 0);
    }
    Tensor<int64, 3> d3(3, B, 1);
    for (int i = 0; i < B; i++)
    {
        d3(0, i, 0) = d3_1(i, 0);
        d3(1, i, 0) = d3_2(i, 0);
        d3(2, i, 0) = d3_3(i, 0);
    }

    Tensor<int64, 3> r3, q3, t3;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims10 = {Eigen::IndexPair<int64>(1, 0)};
    r3 = Mat::A_plus.contract(b3, product_dims10);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims11 = {Eigen::IndexPair<int64>(1, 0)};
    q3 = Mat::A_plus.contract(c3, product_dims11);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims12 = {Eigen::IndexPair<int64>(1, 0)};
    t3 = Mat::A_plus.contract(d3, product_dims12);
    ofstream F3_0, F3_1, F3_2, F3_3;
    F3_0.open("Mul_Triplets/MT3_0.txt");
    F3_1.open("Mul_Triplets/MT3_1.txt");
    F3_2.open("Mul_Triplets/MT3_2.txt");
    F3_3.open("Mul_Triplets/MT3_3.txt");
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F3_0 << r3(0, i, j) << ',';
            F3_1 << r3(1, i, j) << ',';
            F3_2 << r3(2, i, j) << ',';
            F3_3 << r3(3, i, j) << ',';
        }
        F3_0 << std::endl;
        F3_1 << std::endl;
        F3_2 << std::endl;
        F3_3 << std::endl;
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        F3_0 << q3(0, i, 0) << ',' << endl;
        F3_1 << q3(1, i, 0) << ',' << endl;
        F3_2 << q3(2, i, 0) << ',' << endl;
        F3_3 << q3(3, i, 0) << ',' << endl;
    }
    for (int i = 0; i < B; i++)
    {

        F3_0 << t3(0, i, 0) << ',' << endl;
        F3_1 << t3(1, i, 0) << ',' << endl;
        F3_2 << t3(2, i, 0) << ',' << endl;
        F3_3 << t3(3, i, 0) << ',' << endl;
    }
    F3_0.close();
    F3_1.close();
    F3_2.close();
    F3_3.close();

    // for(B, 1)X(1, hiddenDim)
    b4_1 = Mat::randomMatrixint64(B, 1);
    b4_2 = Mat::randomMatrixint64(B, 1);
    b4_3 = Mat::randomMatrixint64(B, 1);
    c4_1 = Mat::randomMatrixint64(1, hiddenDim);
    c4_2 = Mat::randomMatrixint64(1, hiddenDim);
    c4_3 = Mat::randomMatrixint64(1, hiddenDim);
    d4_1 = b4_1 * c4_1;
    d4_2 = Mat::randomMatrixint64(B, hiddenDim);
    d4_3 = Mat::randomMatrixint64(B, hiddenDim);
    Tensor<int64, 3> b4(3, B, 1);
    for (int i = 0; i < B; i++)
    {
        b4(0, i, 0) = b4_1(i, 0);
        b4(1, i, 0) = b4_2(i, 0);
        b4(2, i, 0) = b4_3(i, 0);
    }
    Tensor<int64, 3> c4(3, 1, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        c4(0, 0, j) = c4_1(0, j);
        c4(1, 0, j) = c4_2(0, j);
        c4(2, 0, j) = c4_3(0, j);
    }
    Tensor<int64, 3> d4(3, B, hiddenDim);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            d4(0, i, j) = d4_1(i, j);
            d4(1, i, j) = d4_2(i, j);
            d4(2, i, j) = d4_3(i, j);
        }
    }

    Tensor<int64, 3> r4, q4, t4;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims13 = {Eigen::IndexPair<int64>(1, 0)};
    r4 = Mat::A_plus.contract(b4, product_dims13);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims14 = {Eigen::IndexPair<int64>(1, 0)};
    q4 = Mat::A_plus.contract(c4, product_dims14);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims15 = {Eigen::IndexPair<int64>(1, 0)};
    t4 = Mat::A_plus.contract(d4, product_dims15);
    ofstream F4_0, F4_1, F4_2, F4_3;
    F4_0.open("Mul_Triplets/MT4_0.txt");
    F4_1.open("Mul_Triplets/MT4_1.txt");
    F4_2.open("Mul_Triplets/MT4_2.txt");
    F4_3.open("Mul_Triplets/MT4_3.txt");
    for (int i = 0; i < B; i++)
    {
        F4_0 << r4(0, i, 0) << ',' << endl;
        F4_1 << r4(1, i, 0) << ',' << endl;
        F4_2 << r4(2, i, 0) << ',' << endl;
        F4_3 << r4(3, i, 0) << ',' << endl;
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        F4_0 << q4(0, 0, i) << ',';
        F4_1 << q4(1, 0, i) << ',';
        F4_2 << q4(2, 0, i) << ',';
        F4_3 << q4(3, 0, i) << ',';
    }
    F4_0 << std::endl;
    F4_1 << std::endl;
    F4_2 << std::endl;
    F4_3 << std::endl;
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F4_0 << t4(0, i, j) << ',';
            F4_1 << t4(1, i, j) << ',';
            F4_2 << t4(2, i, j) << ',';
            F4_3 << t4(3, i, j) << ',';
        }
        F4_0 << std::endl;
        F4_1 << std::endl;
        F4_2 << std::endl;
        F4_3 << std::endl;
    }
    F4_0.close();
    F4_1.close();
    F4_2.close();
    F4_3.close();

    // for(B, hiddenDim)X(hiddenDim, hiddenDim)
    b5_1 = Mat::randomMatrixint64(B, hiddenDim);
    b5_2 = Mat::randomMatrixint64(B, hiddenDim);
    b5_3 = Mat::randomMatrixint64(B, hiddenDim);
    c5_1 = Mat::randomMatrixint64(hiddenDim, hiddenDim);
    c5_2 = Mat::randomMatrixint64(hiddenDim, hiddenDim);
    c5_3 = Mat::randomMatrixint64(hiddenDim, hiddenDim);
    d5_1 = b5_1 * c5_1;
    d5_2 = Mat::randomMatrixint64(B, hiddenDim);
    d5_3 = Mat::randomMatrixint64(B, hiddenDim);
    Tensor<int64, 3> b5(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b5(0, i, j) = b5_1(i, j);
            b5(1, i, j) = b5_2(i, j);
            b5(2, i, j) = b5_3(i, j);
        }
    }
    Tensor<int64, 3> c5(3, hiddenDim, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < hiddenDim; i++)
        {
            c5(0, i, j) = c5_1(i, j);
            c5(1, i, j) = c5_2(i, j);
            c5(2, i, j) = c5_3(i, j);
        }
    }
    Tensor<int64, 3> d5(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            d5(0, i, j) = d5_1(i, j);
            d5(1, i, j) = d5_2(i, j);
            d5(2, i, j) = d5_3(i, j);
        }
    }

    Tensor<int64, 3> r5, q5, t5;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims16 = {Eigen::IndexPair<int64>(1, 0)};
    r5 = Mat::A_plus.contract(b5, product_dims16);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims17 = {Eigen::IndexPair<int64>(1, 0)};
    q5 = Mat::A_plus.contract(c5, product_dims17);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims18 = {Eigen::IndexPair<int64>(1, 0)};
    t5 = Mat::A_plus.contract(d5, product_dims18);
    ofstream F5_0, F5_1, F5_2, F5_3;
    F5_0.open("Mul_Triplets/MT5_0.txt");
    F5_1.open("Mul_Triplets/MT5_1.txt");
    F5_2.open("Mul_Triplets/MT5_2.txt");
    F5_3.open("Mul_Triplets/MT5_3.txt");
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F5_0 << r5(0, i, j) << ',';
            F5_1 << r5(1, i, j) << ',';
            F5_2 << r5(2, i, j) << ',';
            F5_3 << r5(3, i, j) << ',';
        }
        F5_0 << std::endl;
        F5_1 << std::endl;
        F5_2 << std::endl;
        F5_3 << std::endl;
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F5_0 << q5(0, i, j) << ',';
            F5_1 << q5(1, i, j) << ',';
            F5_2 << q5(2, i, j) << ',';
            F5_3 << q5(3, i, j) << ',';
        }
        F5_0 << std::endl;
        F5_1 << std::endl;
        F5_2 << std::endl;
        F5_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F5_0 << t5(0, i, j) << ',';
            F5_1 << t5(1, i, j) << ',';
            F5_2 << t5(2, i, j) << ',';
            F5_3 << t5(3, i, j) << ',';
        }
        F5_0 << std::endl;
        F5_1 << std::endl;
        F5_2 << std::endl;
        F5_3 << std::endl;
    }
    F5_0.close();
    F5_1.close();
    F5_2.close();
    F5_3.close();

    // for(D, B)X(B, hiddenDim)
    b6_1 = Mat::randomMatrixint64(D, B);
    b6_2 = Mat::randomMatrixint64(D, B);
    b6_3 = Mat::randomMatrixint64(D, B);
    c6_1 = Mat::randomMatrixint64(B, hiddenDim);
    c6_2 = Mat::randomMatrixint64(B, hiddenDim);
    c6_3 = Mat::randomMatrixint64(B, hiddenDim);
    d6_1 = b6_1 * c6_1;
    d6_2 = Mat::randomMatrixint64(D, hiddenDim);
    d6_3 = Mat::randomMatrixint64(D, hiddenDim);
    Tensor<int64, 3> b6(3, D, B);
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < D; i++)
        {
            b6(0, i, j) = b6_1(i, j);
            b6(1, i, j) = b6_2(i, j);
            b6(2, i, j) = b6_3(i, j);
        }
    }
    Tensor<int64, 3> c6(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            c6(0, i, j) = c6_1(i, j);
            c6(1, i, j) = c6_2(i, j);
            c6(2, i, j) = c6_3(i, j);
        }
    }
    Tensor<int64, 3> d6(3, D, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < D; i++)
        {
            d6(0, i, j) = d6_1(i, j);
            d6(1, i, j) = d6_2(i, j);
            d6(2, i, j) = d6_3(i, j);
        }
    }

    Tensor<int64, 3> r6, q6, t6;
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims19 = {Eigen::IndexPair<int64>(1, 0)};
    r6 = Mat::A_plus.contract(b6, product_dims19);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims20 = {Eigen::IndexPair<int64>(1, 0)};
    q6 = Mat::A_plus.contract(c6, product_dims20);
    Eigen::array<Eigen::IndexPair<int64>, 1> product_dims21 = {Eigen::IndexPair<int64>(1, 0)};
    t6 = Mat::A_plus.contract(d6, product_dims21);
    ofstream F6_0, F6_1, F6_2, F6_3;
    F6_0.open("Mul_Triplets/MT6_0.txt");
    F6_1.open("Mul_Triplets/MT6_1.txt");
    F6_2.open("Mul_Triplets/MT6_2.txt");
    F6_3.open("Mul_Triplets/MT6_3.txt");
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < B; j++)
        {
            F6_0 << r6(0, i, j) << ',';
            F6_1 << r6(1, i, j) << ',';
            F6_2 << r6(2, i, j) << ',';
            F6_3 << r6(3, i, j) << ',';
        }
        F6_0 << std::endl;
        F6_1 << std::endl;
        F6_2 << std::endl;
        F6_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F6_0 << q6(0, i, j) << ',';
            F6_1 << q6(1, i, j) << ',';
            F6_2 << q6(2, i, j) << ',';
            F6_3 << q6(3, i, j) << ',';
        }
        F6_0 << std::endl;
        F6_1 << std::endl;
        F6_2 << std::endl;
        F6_3 << std::endl;
    }
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F6_0 << t6(0, i, j) << ',';
            F6_1 << t6(1, i, j) << ',';
            F6_2 << t6(2, i, j) << ',';
            F6_3 << t6(3, i, j) << ',';
        }
        F6_0 << std::endl;
        F6_1 << std::endl;
        F6_2 << std::endl;
        F6_3 << std::endl;
    }
    F6_0.close();
    F6_1.close();
    F6_2.close();
    F6_3.close();

    Matrixint64 m0 = Mat::randomMatrixint64(B, 1);
    Matrixint64 temp_vec(3, 1);
    Matrixint64 A_plus_mat = Mat::toMatrix(Mat::A_plus);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            temp_vec << m0(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m0_0(i, j) = temp(0, 0);
            m0_1(i, j) = temp(1, 0);
            m0_2(i, j) = temp(2, 0);
            m0_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixint64(m0);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            temp_vec << m0(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m_00(i, j) = temp(0, 0);
            m_01(i, j) = temp(1, 0);
            m_02(i, j) = temp(2, 0);
            m_03(i, j) = temp(3, 0);
        }
    }

    Matrixint64 m1 = Mat::randomMatrixint64(D, 1);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            temp_vec << m1(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m1_0(i, j) = temp(0, 0);
            m1_1(i, j) = temp(1, 0);
            m1_2(i, j) = temp(2, 0);
            m1_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixint64(m1);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            temp_vec << m1(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m_10(i, j) = temp(0, 0);
            m_11(i, j) = temp(1, 0);
            m_12(i, j) = temp(2, 0);
            m_13(i, j) = temp(3, 0);
        }
    }

    Matrixint64 m2 = Mat::randomMatrixint64(B, hiddenDim);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m2(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m2_0(i, j) = temp(0, 0);
            m2_1(i, j) = temp(1, 0);
            m2_2(i, j) = temp(2, 0);
            m2_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixint64(m2);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m2(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m_20(i, j) = temp(0, 0);
            m_21(i, j) = temp(1, 0);
            m_22(i, j) = temp(2, 0);
            m_23(i, j) = temp(3, 0);
        }
    }

    Matrixint64 m3 = Mat::randomMatrixint64(D, hiddenDim);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m3(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m3_0(i, j) = temp(0, 0);
            m3_1(i, j) = temp(1, 0);
            m3_2(i, j) = temp(2, 0);
            m3_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixint64(m3);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m3(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp = A_plus_mat * temp_vec;
            m_30(i, j) = temp(0, 0);
            m_31(i, j) = temp(1, 0);
            m_32(i, j) = temp(2, 0);
            m_33(i, j) = temp(3, 0);
        }
    }
}

void Secret_Mul::get_Triplets() //  0:(128,785)X(785,1)  1:(785,128)X(128,1)
{
    ifstream infile0("Mul_Triplets/MT0_" + to_string(party) + ".txt");
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile0, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < D; j++)
        {
            r0(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile0, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        q0(i, 0) = Constant::Util::getint64(ch);
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile0, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        t0(i, 0) = Constant::Util::getint64(ch);
    }

    ifstream infile1("Mul_Triplets/MT1_" + to_string(party) + ".txt");
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile1, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < B; j++)
        {
            r1(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile1, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        q1(i, 0) = Constant::Util::getint64(ch);
    }
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile1, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        t1(i, 0) = Constant::Util::getint64(ch);
    }
    ifstream infile2("Mul_Triplets/MT2_" + to_string(party) + ".txt");
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile2, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < D; j++)
        {
            r2(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile2, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            q2(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile2, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            t2(i, j) = Constant::Util::getint64(ch);
        }
    }
    ifstream infile3("Mul_Triplets/MT3_" + to_string(party) + ".txt");
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile3, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            r3(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile3, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        q3(i, 0) = Constant::Util::getint64(ch);
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile3, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        t3(i, 0) = Constant::Util::getint64(ch);
    }
    ifstream infile4("Mul_Triplets/MT4_" + to_string(party) + ".txt");
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile4, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        r4(i, 0) = Constant::Util::getint64(ch);
    }
    for (int i = 0; i < 1; i++)
    {
        string s;
        getline(infile4, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            q4(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile4, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            t4(i, j) = Constant::Util::getint64(ch);
        }
    }
    ifstream infile5("Mul_Triplets/MT5_" + to_string(party) + ".txt");
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile5, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            r5(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile5, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            q5(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile5, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            t5(i, j) = Constant::Util::getint64(ch);
        }
    }
    ifstream infile6("Mul_Triplets/MT6_" + to_string(party) + ".txt");
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile6, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < B; j++)
        {
            r6(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile6, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            q6(i, j) = Constant::Util::getint64(ch);
        }
    }
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile6, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            t6(i, j) = Constant::Util::getint64(ch);
        }
    }
    cout << "get triplets" << endl;
}

void Secret_Mul::Mul_truncation(Matrixint64 &z)
{
    int row = z.rows();
    int col = z.cols();
    Matrixint64 r0(row, col), r1(row, col), r2(row, col);
    Matrixint64 r_0(row, col), r_1(row, col), r_2(row, col);

    if (row == B && col == 1)
    {

        r0 = Secret_Mul::m0_0;
        r1 = Secret_Mul::m0_1;
        r2 = Secret_Mul::m0_2;
        r_0 = Secret_Mul::m_00;
        r_1 = Secret_Mul::m_01;
        r_2 = Secret_Mul::m_02;
    }
    else if (row == D && col == 1)
    {

        r0 = Secret_Mul::m1_0;
        r1 = Secret_Mul::m1_1;
        r2 = Secret_Mul::m1_2;
        r_0 = Secret_Mul::m_10;
        r_1 = Secret_Mul::m_11;
        r_2 = Secret_Mul::m_12;
    }
    else if (row == B && col == B)
    {
        r0 = Secret_Mul::m2_0;
        r1 = Secret_Mul::m2_1;
        r2 = Secret_Mul::m2_2;
        r_0 = Secret_Mul::m_20;
        r_1 = Secret_Mul::m_21;
        r_2 = Secret_Mul::m_22;
    }
    else if (row == D && col == B)
    {
        r0 = Secret_Mul::m3_0;
        r1 = Secret_Mul::m3_1;
        r2 = Secret_Mul::m3_2;
        r_0 = Secret_Mul::m_30;
        r_1 = Secret_Mul::m_31;
        r_2 = Secret_Mul::m_32;
    }
    if (party == 0)
    {
        Matrixint64 z0_sub_r0 = z - r0;
        Matrixint64 reveal = Secret_Mul::reveal(z0_sub_r0);
        Matrixint64 z_sub_r = reveal * (-2);
        Mat::truncateMatrixint64(z_sub_r);
        z = z_sub_r + r_0;
    }
    else if (party == 1)
    {
        Matrixint64 z1_sub_r1 = z - r1;
        Secret_Mul::reveal(z1_sub_r1);
        z = r_1;
    }
    else if (party == 2)
    {
        Matrixint64 z2_sub_r2 = z - r2;
        Secret_Mul::reveal(z2_sub_r2);
        z = r_2;
    }
}

Matrixint64 Secret_Mul::Multiply(Matrixint64 &x, Matrixint64 &y, Matrixint64 &r, Matrixint64 &q, Matrixint64 &t)
{
    Matrixint64 result;
    Matrixint64 y_plus_q = y + q;
    Matrixint64 x_plus_r = x + r;

    Matrixint64 Y_plus_Q, X_plus_R, combination, rev_combine;
    // (B, D)*(D, 1)
    if (x.rows() == B && x.cols() == D && y.rows() == D && y.cols() == 1)
    {
        combination.resize(B + 1, D);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(B);
    }
        // (D, B)*(B, 1)
    else if (x.rows() == D && x.cols() == B && y.rows() == B && y.cols() == 1)
    {
        combination.resize(D + 1, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(D);
    }
        // (B, D)*(D, hiddenDim)
    else if (x.rows() == B && x.cols() == D && y.rows() == D && y.cols() == hiddenDim)
    {
        combination.resize(B + hiddenDim, D);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(B);
    }
        // (B, hiddenDim)*(hiddenDim, 1)
    else if (x.rows() == B && x.cols() == hiddenDim && y.rows() == hiddenDim && y.cols() == 1)
    {
        combination.resize(B + 1, hiddenDim);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(B);
    }
        // (B, 1)*(1, hiddenDim)
    else if (x.rows() == B && x.cols() == 1 && y.rows() == 1 && y.cols() == hiddenDim)
    {
        combination.resize(B + hiddenDim, 1);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(B);
    }
        // (B, hiddenDim)*(hiddenDim, hiddenDim)
    else if (x.rows() == B && x.cols() == hiddenDim && y.rows() == hiddenDim && y.cols() == hiddenDim)
    {
        combination.resize(B + hiddenDim, hiddenDim);
        combination << x_plus_r,
                y_plus_q;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(hiddenDim);
        X_plus_R = rev_combine.topRows(B);
    }
        // (hiddenDim, B)*(B, 1)
    else if (x.rows() == hiddenDim && x.cols() == B && y.rows() == B && y.cols() == 1)
    {
        combination.resize(hiddenDim + 1, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(hiddenDim);
    }
        // (D, B)*(B, hiddenDim)
    else if (x.rows() == D && x.cols() == B && y.rows() == B && y.cols() == hiddenDim)
    {
        combination.resize(D + hiddenDim, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(D);
    }
        // (hiddenDim, B)*(B, hiddenDim)
    else if (x.rows() == hiddenDim && x.cols() == B && y.rows() == B && y.cols() == hiddenDim)
    {
        combination.resize(hiddenDim + hiddenDim, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
                y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal(combination);
        Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(hiddenDim);
    }else{
        cout << "no multiply for " << x.rows() << "*" << x.cols() <<"  " << y.rows() << " " <<  y.cols() << endl;
    }
    result = x * Y_plus_Q - X_plus_R * q + t;
    Secret_Mul::Mul_truncation(result);
    return result;
}

Matrixint64 Secret_Mul::Multiply_nn(Matrixint64 &x, Matrixint64 &y, Matrixint64 &r, Matrixint64 &q, Matrixint64 &t)
{
    Matrixint64 result;
    Matrixint64 y_plus_q = y + q;

    Matrixint64 x_plus_r = x + r;
    Matrixint64 Y_plus_Q, X_plus_R, Y_plus_Q_mod, X_plus_R_mod, combination, rev_combine;
    // (B, D)*(D, 1)
    if (x.rows() == B && x.cols() == D && y.rows() == D && y.cols() == 1)
    {
        combination.resize(B + 1, D);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(B, 1).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(B);
        X_plus_R_mod = rev_combine.middleRows(B + 1, B);
    }
    // (D, B)*(B, 1)
    else if (x.rows() == D && x.cols() == B && y.rows() == B && y.cols() == 1)
    {
        combination.resize(D + 1, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(D, 1).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(D);
        X_plus_R_mod = rev_combine.middleRows(D + 1, D);
    }
    // (B, D)*(D, hiddenDim)
    else if (x.rows() == B && x.cols() == D && y.rows() == D && y.cols() == hiddenDim)
    {
        combination.resize(B + hiddenDim, D);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(B, hiddenDim).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(B);
        X_plus_R_mod = rev_combine.middleRows(B + hiddenDim, B);
    }
    // (B, hiddenDim)*(hiddenDim, 1)
    else if (x.rows() == B && x.cols() == hiddenDim && y.rows() == hiddenDim && y.cols() == 1)
    {
        combination.resize(B + 1, hiddenDim);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(B, 1).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(B);
        X_plus_R_mod = rev_combine.middleRows(B + 1, B);
    }
    // (B, 1)*(1, hiddenDim)
    else if (x.rows() == B && x.cols() == 1 && y.rows() == 1 && y.cols() == hiddenDim)
    {
        combination.resize(B + hiddenDim, 1);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(B, hiddenDim).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(B);
        X_plus_R_mod = rev_combine.middleRows(B + hiddenDim, B);
    }
    // (B, hiddenDim)*(hiddenDim, hiddenDim)
    else if (x.rows() == B && x.cols() == hiddenDim && y.rows() == hiddenDim && y.cols() == hiddenDim)
    {
        combination.resize(B + hiddenDim, hiddenDim);
        combination << x_plus_r,
            y_plus_q;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(B, hiddenDim);
        Y_plus_Q_mod = rev_combine.bottomRows(hiddenDim);
        X_plus_R = rev_combine.topRows(B);
        X_plus_R_mod = rev_combine.middleRows(B + hiddenDim, B);
    }
    // (hiddenDim, B)*(B, 1)
    else if (x.rows() == hiddenDim && x.cols() == B && y.rows() == B && y.cols() == 1)
    {
        combination.resize(hiddenDim + 1, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(hiddenDim, 1).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(1).transpose();
        X_plus_R = rev_combine.topRows(hiddenDim);
        X_plus_R_mod = rev_combine.middleRows(hiddenDim + 1, hiddenDim);
    }
    // (D, B)*(B, hiddenDim)
    else if (x.rows() == D && x.cols() == B && y.rows() == B && y.cols() == hiddenDim)
    {
        combination.resize(D + hiddenDim, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(D, hiddenDim).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(D);
        X_plus_R_mod = rev_combine.middleRows(D + hiddenDim, D);
    }
    // (hiddenDim, B)*(B, hiddenDim)
    else if (x.rows() == hiddenDim && x.cols() == B && y.rows() == B && y.cols() == hiddenDim)
    {
        combination.resize(hiddenDim + hiddenDim, B);
        Matrixint64 y_plus_q_trans = y_plus_q.transpose();
        combination << x_plus_r,
            y_plus_q_trans;
        Matrixint64 rev_combine = Secret_Mul::Mul_reveal_nn(combination);
        Y_plus_Q = rev_combine.middleRows(hiddenDim, hiddenDim).transpose();
        Y_plus_Q_mod = rev_combine.bottomRows(hiddenDim).transpose();
        X_plus_R = rev_combine.topRows(hiddenDim);
        X_plus_R_mod = rev_combine.middleRows(hiddenDim + hiddenDim, hiddenDim);
    }
    else
    {
        cout << "no mul" << endl;
        exit(0);
    }
    Matrixint128 a = X_plus_R_mod.cast<int128>(), b = q.cast<int128>();
    Matrixint128 d = x.cast<int128>(), e = Y_plus_Q_mod.cast<int128>();
    Matrixint128 c = a * b;
    Matrixint128 f = d * e;
    for (int i = 0; i < c.size(); i++)
    {
        c(i) = c(i) / 2;
        f(i) = f(i) / 2;
    }
    Matrixint64 mod1 = f.cast<int64>();
    Matrixint64 mod2 = c.cast<int64>();
    result = (x * Y_plus_Q + mod1) - (X_plus_R * q + mod2) + t;
    Secret_Mul::Mul_truncation(result);
    return result;
}

// todo:三元组的生成 目前全部设置为0
Matrixint64 Secret_Mul::CwiseProduct(Matrixint64 &x, Matrixint64 &y, Matrixint64 &r, Matrixint64 &q, Matrixint64 &t)
{
    r.setZero();
    q.setZero();
    t.setZero();
    Matrixint64 result;
    Matrixint64 y_plus_q = y + q;
    Matrixint64 x_plus_r = x + r;

    Matrixint64 Y_plus_Q, X_plus_R, combination, rev_combine;
    if (x.rows() == B && x.cols() == 1)
    {
        combination.resize(B, 2);
        combination << y_plus_q, x_plus_r;
        Matrixint64 rev_combine = Secret_Mul::reveal(combination);
        Y_plus_Q = rev_combine.leftCols(1);
        X_plus_R = rev_combine.rightCols(1);
    }
    else if (x.rows() == B && x.cols() == hiddenDim)
    {
        combination.resize(B, hiddenDim + hiddenDim);
        combination << y_plus_q, x_plus_r;
        Matrixint64 rev_combine = Secret_Mul::reveal(combination);
        Y_plus_Q = rev_combine.leftCols(hiddenDim);
        X_plus_R = rev_combine.rightCols(hiddenDim);
    }
    result = x.cwiseProduct(Y_plus_Q) - X_plus_R.cwiseProduct(q) + t;
    Secret_Mul::Mul_truncation(result);
    return result;
}

Matrixint64 Secret_Mul::constant_Mul(Matrixint64 &x, double d)
{
    Matrixint64 result = x * (Constant::Util::double_to_int64(d));
    Secret_Mul::Mul_truncation(result);
    return result;
}

Matrixint64 Secret_Mul::Mul_reveal(Matrixint64 &data)
{
    int row = data.rows();
    int col = data.cols();
    Matrixint64 res;
    if (party == 0)
    {
        Matrixint64 data1, data2;
        tel.receive(&data1, 1);
        tel.receive(&data2, 2);

        res = (-data + data1 - data2) / 2;
        tel.send(&res, 1);
        tel.send(&res, 2);
    }
    else
    {
        tel.send(&data, 0);
        tel.receive(&res, 0);
    }
    return res;
}

Matrixint64 Secret_Mul::Mul_reveal_nn(Matrixint64 &data)
{
    int row = data.rows();
    int col = data.cols();
    Matrixint64 res(row * 2, col);
    if (party == 0)
    {
        Matrixint64 data1, data2;
        tel.receive(&data1, 1);
        tel.receive(&data2, 2);
        Matrixint64 res1, res2(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ((-data(i, j) + data1(i, j) - data2(i, j)) % 2 != 0)
                {
                    res2(i, j) = (-data(i, j) + data1(i, j) - data2(i, j)) % 2;
                }
                else
                {
                    res2(i, j) = 0;
                }
            }
        }
        res1 = (-data + data1 - data2) / 2;
        res << res1,
            res2;
        tel.send(&res, 1);
        tel.send(&res, 2);
    }
    else
    {
        tel.send(&data, 0);
        tel.receive(&res, 0);
    }
    return res;
}

Matrixint64 Secret_Mul::reveal(Matrixint64 &data)
{
    int row = data.rows();
    int col = data.cols();
    Matrixint64 res;
    if (party == 0)
    {
        Matrixint64 data1, data2;
        tel.receive(&data1, 1);
        tel.receive(&data2, 2);

        res = (-data + data1 - data2) / 2;
        tel.send(&res, 1);
        tel.send(&res, 2);
    }
    else
    {
        tel.send(&data, 0);
        tel.receive(&res, 0);
    }
    return res;
}

int64 Secret_Mul::Generate_triplets_Bob(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    Matrixint64 message_send(3, 1), message_recv(3, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    int64 temp = 0;
    int64 b_j = Constant::Util::random_int64();
    int64 d_j = Constant::Util::random_int64();

    // make sure that a_i + c_i != 0
    while (b_j - d_j == 0)
    {
        b_j = Constant::Util::random_int64();
    }

    // std::cout<<"b_j is :" << b_j << "d_j is :" << d_j << std::endl;

    if (is_ui)
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(0, 0) = b_j - d_j;
            message_send(1, 0) = b_j - mul_mat(i, j * 2 + 1);
            message_send(2, 0) = d_j - mul_mat(i, j * 2);
            if (send_first)
            {
                tel.send(&message_send, party);
                tel.receive(&message_recv, party);
                // std::cout<<"message u_i have been sent to party " << party <<std::endl << message_send << std::endl;
                // std::cout<<"message v_i have been recieved party " << party <<std::endl << message_recv << std::endl;
            }
            else
            {
                tel.receive(&message_recv, party);
                tel.send(&message_send, party);
                // std::cout<<"message v_i have been recieved party "  << party <<  std::endl << message_recv << std::endl;
                // std::cout<<"message u_i have been sent to party " << party <<  std::endl << message_send << std::endl;
                temp += message_recv(1, 0) * (2 * mul_mat(i, j * 2 + 1) - b_j) + message_recv(2, 0) * (2 * mul_mat(i, j * 2) - d_j) + message_recv(0, 0) * (d_j - 2 * b_j);
            }
        }
    }
    else
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(0, 0) = b_j - d_j;
            message_send(1, 0) = b_j - mul_mat(j * 2 + 1, 0);
            message_send(2, 0) = d_j - mul_mat(j * 2, 0);
            if (send_first)
            {
                tel.send(&message_send, party);
                tel.receive(&message_recv, party);
                // std::cout<<"message v_i have been sent to party " << party <<std::endl << message_send << std::endl;
                // std::cout<<"message u_i have been recieved party " << party <<std::endl << message_recv << std::endl;
            }
            else
            {
                tel.receive(&message_recv, party);
                tel.send(&message_send, party);
                // std::cout<<"message u_i have been recieved party " << party <<  std::endl << message_recv << std::endl;
                // std::cout<<"message v_i have been sent to party " << party <<  std::endl << message_send << std::endl;
            }
            temp += message_recv(1, 0) * (2 * mul_mat(j * 2 + 1, 0) - b_j) + message_recv(2, 0) * (2 * mul_mat(j * 2, 0) - d_j) + message_recv(0, 0) * (d_j - 2 * b_j);
        }
    }
    // std::cout<<"temp is : " << temp<<std::endl;
    return temp;
}

int64 Secret_Mul::Generate_triplets_Alice(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    Matrixint64 message_send(3, 1), message_recv(3, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    int64 temp = 0;
    int64 a_i = Constant::Util::random_int64();
    int64 c_i = Constant::Util::random_int64();

    // make sure that a_i + c_i != 0
    while (a_i + c_i == 0)
    {
        a_i = Constant::Util::random_int64();
    }

    // std::cout<<"a_i is :" << a_i << "c_i is :" << c_i << std::endl;
    if (is_ui)
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(0, 0) = a_i + c_i;
            message_send(1, 0) = mul_mat(i, j * 2 + 1) + a_i;
            message_send(2, 0) = mul_mat(i, j * 2) + c_i;
            if (send_first)
            {
                tel.send(&message_send, party);
                tel.receive(&message_recv, party);
                // std::cout<<"message u_i have been sent to party " << party <<std::endl << message_send << std::endl;
                // std::cout<<"message v_i have been recieved from party " << party <<std::endl << message_recv << std::endl;
            }
            else
            {
                tel.receive(&message_recv, party);
                tel.send(&message_send, party);
                // std::cout<<"message v_i have been recieved from party " << party <<std::endl << message_recv << std::endl;
                // std::cout<<"message u_i have been sent to party " << party <<std::endl << message_send << std::endl;
            }
            temp += message_recv(1, 0) * (mul_mat(i, j * 2 + 1) + 2 * a_i) + message_recv(2, 0) * (mul_mat(i, j * 2) + 2 * c_i) + message_recv(0, 0) * (a_i + 2 * c_i);
        }
    }
    else
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(0, 0) = a_i + c_i;
            message_send(1, 0) = mul_mat(j * 2 + 1, 0) + a_i;
            message_send(2, 0) = mul_mat(j * 2, 0) + c_i;
            if (send_first)
            {
                // std::cout<<"message v_i have been sent to party "  << party  << std::endl << message_send << std::endl;
                tel.send(&message_send, party);
                // std::cout<<"message u_i have been recieved from party " << party  << std::endl << message_recv << std::endl;
                tel.receive(&message_recv, party);
            }
            else
            {
                // std::cout<<"message u_i have been recieved from party" << party << std::endl << message_recv << std::endl;
                tel.receive(&message_recv, party);
                // std::cout<<"message v_i have been sent to party" << party << std::endl << message_send << std::endl;
                tel.send(&message_send, party);
            }
            temp += message_recv(1, 0) * (mul_mat(j * 2 + 1, 0) + 2 * a_i) + message_recv(2, 0) * (mul_mat(j * 2, 0) + 2 * c_i) + message_recv(0, 0) * (a_i + 2 * c_i);
        }
    }
    // std::cout<<"temp is : " << temp <<std::endl;
    return temp;
}

int64 Secret_Mul::Generate_triplets_Bob_improve(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    Matrixint64 message_send(1 + length, 1), message_recv(1 + length, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    int64 temp = 0;
    int64 b_j = Constant::Util::random_int64();
    int64 d_j = Constant::Util::random_int64();

    // make sure that a_i + c_i != 0
    while (b_j - d_j == 0)
    {
        b_j = Constant::Util::random_int64();
    }

    message_send(0, 0) = b_j - d_j;
    if (is_ui)
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(2 * j + 1, 0) = b_j - mul_mat(i, j * 2 + 1);
            message_send(2 * j + 2, 0) = d_j - mul_mat(i, j * 2);
        }
        if (send_first)
        {
            tel.send(&message_send, party);
            tel.receive(&message_recv, party);
        }
        else
        {
            tel.receive(&message_recv, party);
            tel.send(&message_send, party);
        }
        for (int j = 0; j < length / 2; j++)
        {
            temp += message_recv(2 * j + 1, 0) * (2 * mul_mat(i, j * 2 + 1) - b_j) + message_recv(2 * j + 2, 0) * (2 * mul_mat(i, j * 2) - d_j) + message_recv(0, 0) * (d_j - 2 * b_j);
        }
    }
    else
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(2 * j + 1, 0) = b_j - mul_mat(j * 2 + 1, 0);
            message_send(2 * j + 2, 0) = d_j - mul_mat(j * 2, 0);
        }

        if (send_first)
        {
            tel.send(&message_send, party);
            tel.receive(&message_recv, party);
        }
        else
        {
            tel.receive(&message_recv, party);
            tel.send(&message_send, party);
        }
        for (int j = 0; j < length / 2; j++)
        {
            temp += message_recv(2 * j + 1, 0) * (2 * mul_mat(j * 2 + 1, 0) - b_j) + message_recv(2 * j + 2, 0) * (2 * mul_mat(j * 2, 0) - d_j) + message_recv(0, 0) * (d_j - 2 * b_j);
        }
    }
    return temp;
}

int64 Secret_Mul::Generate_triplets_Alice_improve(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    Matrixint64 message_send(1 + length, 1), message_recv(1 + length, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    int64 temp = 0;
    int64 a_i = Constant::Util::random_int64();
    int64 c_i = Constant::Util::random_int64();

    // make sure that a_i + c_i != 0
    while (a_i + c_i == 0)
    {
        a_i = Constant::Util::random_int64();
    }

    message_send(0, 0) = a_i + c_i;
    // std::cout<<"a_i is :" << a_i << "c_i is :" << c_i << std::endl;
    if (is_ui)
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(2 * j + 1, 0) = mul_mat(i, j * 2 + 1) + a_i;
            message_send(2 * j + 2, 0) = mul_mat(i, j * 2) + c_i;
        }
        if (send_first)
        {
            tel.send(&message_send, party);
            tel.receive(&message_recv, party);
        }
        else
        {
            tel.receive(&message_recv, party);
            tel.send(&message_send, party);
        }
        for (int j = 0; j < length / 2; j++)
        {
            temp += message_recv(2 * j + 1, 0) * (mul_mat(i, j * 2 + 1) + 2 * a_i) + message_recv(2 * j + 2, 0) * (mul_mat(i, j * 2) + 2 * c_i) + message_recv(0, 0) * (a_i + 2 * c_i);
        }
    }
    else
    {
        for (int j = 0; j < length / 2; j++)
        {
            message_send(2 * j + 1, 0) = mul_mat(j * 2 + 1, 0) + a_i;
            message_send(2 * j + 2, 0) = mul_mat(j * 2, 0) + c_i;
        }
        if (send_first)
        {
            tel.send(&message_send, party);
            tel.receive(&message_recv, party);
        }
        else
        {
            tel.receive(&message_recv, party);
            tel.send(&message_send, party);
        }
        for (int j = 0; j < length / 2; j++)
        {
            temp += message_recv(2 * j + 1, 0) * (mul_mat(j * 2 + 1, 0) + 2 * a_i) + message_recv(2 * j + 2, 0) * (mul_mat(j * 2, 0) + 2 * c_i) + message_recv(0, 0) * (a_i + 2 * c_i);
        }
    }
    return temp;
}
// std