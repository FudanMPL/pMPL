#include "Secret_Mul.h"
// Multiply_Triplets(for(B, D)X(D, numClass))
MatrixXu Secret_Mul::b0_1 = MatrixXu(B, D);
MatrixXu Secret_Mul::b0_2 = MatrixXu(B, D);
MatrixXu Secret_Mul::b0_3 = MatrixXu(B, D);
MatrixXu Secret_Mul::c0_1 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::c0_2 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::c0_3 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::d0_1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::d0_2 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::d0_3 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::r0 = MatrixXu(B, D);
MatrixXu Secret_Mul::q0 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::t0 = MatrixXu(B, numClass);

// Multiply_Triplets(for(D, B)X(B, numClass))
MatrixXu Secret_Mul::b1_1 = MatrixXu(D, B);
MatrixXu Secret_Mul::b1_2 = MatrixXu(D, B);
MatrixXu Secret_Mul::b1_3 = MatrixXu(D, B);
MatrixXu Secret_Mul::c1_1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::c1_2 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::c1_3 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::d1_1 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::d1_2 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::d1_3 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::r1 = MatrixXu(D, B);
MatrixXu Secret_Mul::q1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::t1 = MatrixXu(D, numClass);

// Multiply_Triplets(for(B, D)X(D, hiddenDim))
MatrixXu Secret_Mul::b2_1 = MatrixXu(B, D);
MatrixXu Secret_Mul::b2_2 = MatrixXu(B, D);
MatrixXu Secret_Mul::b2_3 = MatrixXu(B, D);
MatrixXu Secret_Mul::c2_1 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::c2_2 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::c2_3 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::d2_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d2_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d2_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::r2 = MatrixXu(B, D);
MatrixXu Secret_Mul::q2 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::t2 = MatrixXu(B, hiddenDim);

// Multiply_Triplets(for(B, hiddenDim)X(hiddenDim, numClass))
MatrixXu Secret_Mul::b3_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::b3_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::b3_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::c3_1 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::c3_2 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::c3_3 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::d3_1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::d3_2 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::d3_3 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::r3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::q3 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::t3 = MatrixXu(B, numClass);

// Multiply_Triplets(for(B, 1)X(1, hiddenDim))
MatrixXu Secret_Mul::b4_1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::b4_2 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::b4_3 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::c4_1 = MatrixXu(numClass, hiddenDim);
MatrixXu Secret_Mul::c4_2 = MatrixXu(numClass, hiddenDim);
MatrixXu Secret_Mul::c4_3 = MatrixXu(numClass, hiddenDim);
MatrixXu Secret_Mul::d4_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d4_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d4_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::r4 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::q4 = MatrixXu(numClass, hiddenDim);
MatrixXu Secret_Mul::t4 = MatrixXu(B, hiddenDim);

// Multiply_Triplets(for(B, hiddenDim)X(hiddenDim, hiddenDim))
MatrixXu Secret_Mul::b5_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::b5_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::b5_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::c5_1 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::c5_2 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::c5_3 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::d5_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d5_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d5_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::r5 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::q5 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::t5 = MatrixXu(B, hiddenDim);

// Multiply_Triplets(for(D, B)X(B, hiddenDim))
MatrixXu Secret_Mul::b6_1 = MatrixXu(D, B);
MatrixXu Secret_Mul::b6_2 = MatrixXu(D, B);
MatrixXu Secret_Mul::b6_3 = MatrixXu(D, B);
MatrixXu Secret_Mul::c6_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::c6_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::c6_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d6_1 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::d6_2 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::d6_3 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::r6 = MatrixXu(D, B);
MatrixXu Secret_Mul::q6 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::t6 = MatrixXu(D, hiddenDim);

// Multiply_Triplets(for(hiddenDim, B)X(B, 1))
MatrixXu Secret_Mul::b7_1 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::b7_2 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::b7_3 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::c7_1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::c7_2 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::c7_3 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::d7_1 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::d7_2 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::d7_3 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::r7 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::q7 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::t7 = MatrixXu(hiddenDim, numClass);

// Multiply_Triplets(for(hiddenDim, B)X(B, hiddenDim))
MatrixXu Secret_Mul::b8_1 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::b8_2 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::b8_3 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::c8_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::c8_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::c8_3 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::d8_1 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::d8_2 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::d8_3 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::r8 = MatrixXu(hiddenDim, B);
MatrixXu Secret_Mul::q8 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::t8 = MatrixXu(hiddenDim, hiddenDim);

MatrixXu Secret_Mul::m0_0 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::m0_1 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::m0_2 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::m0_3 = MatrixXu(B, numClass);

MatrixXu Secret_Mul::m_00 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::m_01 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::m_02 = MatrixXu(B, numClass);
MatrixXu Secret_Mul::m_03 = MatrixXu(B, numClass);

MatrixXu Secret_Mul::m1_0 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::m1_1 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::m1_2 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::m1_3 = MatrixXu(D, numClass);

MatrixXu Secret_Mul::m_10 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::m_11 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::m_12 = MatrixXu(D, numClass);
MatrixXu Secret_Mul::m_13 = MatrixXu(D, numClass);

MatrixXu Secret_Mul::m2_0 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::m2_1 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::m2_2 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::m2_3 = MatrixXu(B, hiddenDim);

MatrixXu Secret_Mul::m_20 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::m_21 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::m_22 = MatrixXu(B, hiddenDim);
MatrixXu Secret_Mul::m_23 = MatrixXu(B, hiddenDim);

MatrixXu Secret_Mul::m3_0 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::m3_1 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::m3_2 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::m3_3 = MatrixXu(D, hiddenDim);

MatrixXu Secret_Mul::m_30 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::m_31 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::m_32 = MatrixXu(D, hiddenDim);
MatrixXu Secret_Mul::m_33 = MatrixXu(D, hiddenDim);

MatrixXu Secret_Mul::m4_0 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::m4_1 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::m4_2 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::m4_3 = MatrixXu(hiddenDim, numClass);

MatrixXu Secret_Mul::m_40 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::m_41 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::m_42 = MatrixXu(hiddenDim, numClass);
MatrixXu Secret_Mul::m_43 = MatrixXu(hiddenDim, numClass);

MatrixXu Secret_Mul::m5_0 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::m5_1 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::m5_2 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::m5_3 = MatrixXu(hiddenDim, hiddenDim);

MatrixXu Secret_Mul::m_50 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::m_51 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::m_52 = MatrixXu(hiddenDim, hiddenDim);
MatrixXu Secret_Mul::m_53 = MatrixXu(hiddenDim, hiddenDim);

void Secret_Mul::init()
{
    // for (B, D)X(D, numClass)
    b0_1 = Mat::randomMatrixXu(B, D);
    b0_2 = Mat::randomMatrixXu(B, D);
    b0_3 = Mat::randomMatrixXu(B, D);
    c0_1 = Mat::randomMatrixXu(D, numClass);
    c0_2 = Mat::randomMatrixXu(D, numClass);
    c0_3 = Mat::randomMatrixXu(D, numClass);
    d0_1 = b0_1 * c0_1;
    d0_2 = Mat::randomMatrixXu(B, numClass);
    d0_3 = Mat::randomMatrixXu(B, numClass);
    Tensor<u64, 3> b0(3, B, D);
    for (int j = 0; j < D; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b0(0, i, j) = b0_1(i, j);
            b0(1, i, j) = b0_2(i, j);
            b0(2, i, j) = b0_3(i, j);
        }
    }
    Tensor<u64, 3> c0(3, D, numClass);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            c0(0, i, j) = c0_1(i, j);
            c0(1, i, j) = c0_2(i, j);
            c0(2, i, j) = c0_3(i, j);
        }
    }
    Tensor<u64, 3> d0(3, B, numClass);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            d0(0, i, j) = d0_1(i, j);
            d0(1, i, j) = d0_2(i, j);
            d0(2, i, j) = d0_3(i, j);
        }
    }
    Tensor<u64, 3> r0, q0, t0;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims1 = {Eigen::IndexPair<u64>(1, 0)};
    r0 = Mat::A_plus.contract(b0, product_dims1);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims2 = {Eigen::IndexPair<u64>(1, 0)};
    q0 = Mat::A_plus.contract(c0, product_dims2);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims3 = {Eigen::IndexPair<u64>(1, 0)};
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
        for (int j = 0; j < numClass; j++)
        {
            F0_0 << q0(0, i, j) << ',';
            F0_1 << q0(1, i, j) << ',';
            F0_2 << q0(2, i, j) << ',';
            F0_3 << q0(3, i, j) << ',';
        }
        F0_0 << std::endl;
        F0_1 << std::endl;
        F0_2 << std::endl;
        F0_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            F0_0 << t0(0, i, j) << ',';
            F0_1 << t0(1, i, j) << ',';
            F0_2 << t0(2, i, j) << ',';
            F0_3 << t0(3, i, j) << ',';
        }
        F0_0 << std::endl;
        F0_1 << std::endl;
        F0_2 << std::endl;
        F0_3 << std::endl;
    }
    F0_0.close();
    F0_1.close();
    F0_2.close();
    F0_3.close();

    // for (D, B)X(B, numClass)
    b1_1 = Mat::randomMatrixXu(D, B);
    b1_2 = Mat::randomMatrixXu(D, B);
    b1_3 = Mat::randomMatrixXu(D, B);
    c1_1 = Mat::randomMatrixXu(B, numClass);
    c1_2 = Mat::randomMatrixXu(B, numClass);
    c1_3 = Mat::randomMatrixXu(B, numClass);
    d1_1 = b1_1 * c1_1;
    d1_2 = Mat::randomMatrixXu(D, numClass);
    d1_3 = Mat::randomMatrixXu(D, numClass);
    Tensor<u64, 3> b1(3, D, B);
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < D; i++)
        {
            b1(0, i, j) = b1_1(i, j);
            b1(1, i, j) = b1_2(i, j);
            b1(2, i, j) = b1_3(i, j);
        }
    }
    Tensor<u64, 3> c1(3, B, numClass);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            c1(0, i, j) = c1_1(i, j);
            c1(1, i, j) = c1_2(i, j);
            c1(2, i, j) = c1_3(i, j);
        }
    }
    Tensor<u64, 3> d1(3, D, numClass);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            d1(0, i, j) = d1_1(i, j);
            d1(1, i, j) = d1_2(i, j);
            d1(2, i, j) = d1_3(i, j);
        }
    }
    Tensor<u64, 3> r1, q1, t1;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims4 = {Eigen::IndexPair<u64>(1, 0)};
    r1 = Mat::A_plus.contract(b1, product_dims4);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims5 = {Eigen::IndexPair<u64>(1, 0)};
    q1 = Mat::A_plus.contract(c1, product_dims5);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims6 = {Eigen::IndexPair<u64>(1, 0)};
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
        for (int j = 0; j < numClass; j++)
        {
            F1_0 << q1(0, i, j) << ',';
            F1_1 << q1(1, i, j) << ',';
            F1_2 << q1(2, i, j) << ',';
            F1_3 << q1(3, i, j) << ',';
        }
        F1_0 << std::endl;
        F1_1 << std::endl;
        F1_2 << std::endl;
        F1_3 << std::endl;
    }
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            F1_0 << t1(0, i, j) << ',';
            F1_1 << t1(1, i, j) << ',';
            F1_2 << t1(2, i, j) << ',';
            F1_3 << t1(3, i, j) << ',';
        }
        F1_0 << std::endl;
        F1_1 << std::endl;
        F1_2 << std::endl;
        F1_3 << std::endl;
    }
    F1_0.close();
    F1_1.close();
    F1_2.close();
    F1_3.close();

    // for(B, D)X(D, hiddenDim)
    b2_1 = Mat::randomMatrixXu(B, D);
    b2_2 = Mat::randomMatrixXu(B, D);
    b2_3 = Mat::randomMatrixXu(B, D);
    c2_1 = Mat::randomMatrixXu(D, hiddenDim);
    c2_2 = Mat::randomMatrixXu(D, hiddenDim);
    c2_3 = Mat::randomMatrixXu(D, hiddenDim);
    d2_1 = b2_1 * c2_1;
    d2_2 = Mat::randomMatrixXu(B, hiddenDim);
    d2_3 = Mat::randomMatrixXu(B, hiddenDim);
    Tensor<u64, 3> b2(3, B, D);
    for (int j = 0; j < D; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b2(0, i, j) = b2_1(i, j);
            b2(1, i, j) = b2_2(i, j);
            b2(2, i, j) = b2_3(i, j);
        }
    }
    Tensor<u64, 3> c2(3, D, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < D; i++)
        {
            c2(0, i, j) = c2_1(i, j);
            c2(1, i, j) = c2_2(i, j);
            c2(2, i, j) = c2_3(i, j);
        }
    }
    Tensor<u64, 3> d2(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            d2(0, i, j) = d2_1(i, j);
            d2(1, i, j) = d2_2(i, j);
            d2(2, i, j) = d2_3(i, j);
        }
    }

    Tensor<u64, 3> r2, q2, t2;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims7 = {Eigen::IndexPair<u64>(1, 0)};
    r2 = Mat::A_plus.contract(b2, product_dims7);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims8 = {Eigen::IndexPair<u64>(1, 0)};
    q2 = Mat::A_plus.contract(c2, product_dims8);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims9 = {Eigen::IndexPair<u64>(1, 0)};
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

    // for(B, hiddenDim)X(hiddenDim, numClass)
    b3_1 = Mat::randomMatrixXu(B, hiddenDim);
    b3_2 = Mat::randomMatrixXu(B, hiddenDim);
    b3_3 = Mat::randomMatrixXu(B, hiddenDim);
    c3_1 = Mat::randomMatrixXu(hiddenDim, numClass);
    c3_2 = Mat::randomMatrixXu(hiddenDim, numClass);
    c3_3 = Mat::randomMatrixXu(hiddenDim, numClass);
    d3_1 = b3_1 * c3_1;
    d3_2 = Mat::randomMatrixXu(B, numClass);
    d3_3 = Mat::randomMatrixXu(B, numClass);

    Tensor<u64, 3> b3(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b3(0, i, j) = b3_1(i, j);
            b3(1, i, j) = b3_2(i, j);
            b3(2, i, j) = b3_3(i, j);
        }
    }
    Tensor<u64, 3> c3(3, hiddenDim, numClass);
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            c3(0, i, j) = c3_1(i, j);
            c3(1, i, j) = c3_2(i, j);
            c3(2, i, j) = c3_3(i, j);
        }
    }
    Tensor<u64, 3> d3(3, B, numClass);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            d3(0, i, j) = d3_1(i, j);
            d3(1, i, j) = d3_2(i, j);
            d3(2, i, j) = d3_3(i, j);
        }
    }

    Tensor<u64, 3> r3, q3, t3;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims10 = {Eigen::IndexPair<u64>(1, 0)};
    r3 = Mat::A_plus.contract(b3, product_dims10);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims11 = {Eigen::IndexPair<u64>(1, 0)};
    q3 = Mat::A_plus.contract(c3, product_dims11);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims12 = {Eigen::IndexPair<u64>(1, 0)};
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
        for (int j = 0; j < numClass; j++)
        {
            F3_0 << q3(0, i, j) << ',';
            F3_1 << q3(1, i, j) << ',';
            F3_2 << q3(2, i, j) << ',';
            F3_3 << q3(3, i, j) << ',';
        }
        F3_0 << std::endl;
        F3_1 << std::endl;
        F3_2 << std::endl;
        F3_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            F3_0 << t3(0, i, j) << ',';
            F3_1 << t3(1, i, j) << ',';
            F3_2 << t3(2, i, j) << ',';
            F3_3 << t3(3, i, j) << ',';
        }
        F3_0 << std::endl;
        F3_1 << std::endl;
        F3_2 << std::endl;
        F3_3 << std::endl;
    }
    F3_0.close();
    F3_1.close();
    F3_2.close();
    F3_3.close();

    // for(B, numClass)X(numClass, hiddenDim)
    b4_1 = Mat::randomMatrixXu(B, numClass);
    b4_2 = Mat::randomMatrixXu(B, numClass);
    b4_3 = Mat::randomMatrixXu(B, numClass);
    c4_1 = Mat::randomMatrixXu(numClass, hiddenDim);
    c4_2 = Mat::randomMatrixXu(numClass, hiddenDim);
    c4_3 = Mat::randomMatrixXu(numClass, hiddenDim);
    d4_1 = b4_1 * c4_1;
    d4_2 = Mat::randomMatrixXu(B, hiddenDim);
    d4_3 = Mat::randomMatrixXu(B, hiddenDim);
    Tensor<u64, 3> b4(3, B, numClass);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            b4(0, i, j) = b4_1(i, j);
            b4(1, i, j) = b4_2(i, j);
            b4(2, i, j) = b4_3(i, j);
        }
    }
    Tensor<u64, 3> c4(3, numClass, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < numClass; i++)
        {
            c4(0, i, j) = c4_1(i, j);
            c4(1, i, j) = c4_2(i, j);
            c4(2, i, j) = c4_3(i, j);
        }
    }
    Tensor<u64, 3> d4(3, B, hiddenDim);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            d4(0, i, j) = d4_1(i, j);
            d4(1, i, j) = d4_2(i, j);
            d4(2, i, j) = d4_3(i, j);
        }
    }

    Tensor<u64, 3> r4, q4, t4;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims13 = {Eigen::IndexPair<u64>(1, 0)};
    r4 = Mat::A_plus.contract(b4, product_dims13);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims14 = {Eigen::IndexPair<u64>(1, 0)};
    q4 = Mat::A_plus.contract(c4, product_dims14);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims15 = {Eigen::IndexPair<u64>(1, 0)};
    t4 = Mat::A_plus.contract(d4, product_dims15);
    ofstream F4_0, F4_1, F4_2, F4_3;
    F4_0.open("Mul_Triplets/MT4_0.txt");
    F4_1.open("Mul_Triplets/MT4_1.txt");
    F4_2.open("Mul_Triplets/MT4_2.txt");
    F4_3.open("Mul_Triplets/MT4_3.txt");
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            F4_0 << r4(0, i, j) << ',';
            F4_1 << r4(1, i, j) << ',';
            F4_2 << r4(2, i, j) << ',';
            F4_3 << r4(3, i, j) << ',';
        }
        F4_0 << std::endl;
        F4_1 << std::endl;
        F4_2 << std::endl;
        F4_3 << std::endl;
    }
    for (int i = 0; i < numClass; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F4_0 << q4(0, i, j) << ',';
            F4_1 << q4(1, i, j) << ',';
            F4_2 << q4(2, i, j) << ',';
            F4_3 << q4(3, i, j) << ',';
        }
        F4_0 << std::endl;
        F4_1 << std::endl;
        F4_2 << std::endl;
        F4_3 << std::endl;
    }
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
    b5_1 = Mat::randomMatrixXu(B, hiddenDim);
    b5_2 = Mat::randomMatrixXu(B, hiddenDim);
    b5_3 = Mat::randomMatrixXu(B, hiddenDim);
    c5_1 = Mat::randomMatrixXu(hiddenDim, hiddenDim);
    c5_2 = Mat::randomMatrixXu(hiddenDim, hiddenDim);
    c5_3 = Mat::randomMatrixXu(hiddenDim, hiddenDim);
    d5_1 = b5_1 * c5_1;
    d5_2 = Mat::randomMatrixXu(B, hiddenDim);
    d5_3 = Mat::randomMatrixXu(B, hiddenDim);
    Tensor<u64, 3> b5(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            b5(0, i, j) = b5_1(i, j);
            b5(1, i, j) = b5_2(i, j);
            b5(2, i, j) = b5_3(i, j);
        }
    }
    Tensor<u64, 3> c5(3, hiddenDim, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < hiddenDim; i++)
        {
            c5(0, i, j) = c5_1(i, j);
            c5(1, i, j) = c5_2(i, j);
            c5(2, i, j) = c5_3(i, j);
        }
    }
    Tensor<u64, 3> d5(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            d5(0, i, j) = d5_1(i, j);
            d5(1, i, j) = d5_2(i, j);
            d5(2, i, j) = d5_3(i, j);
        }
    }

    Tensor<u64, 3> r5, q5, t5;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims16 = {Eigen::IndexPair<u64>(1, 0)};
    r5 = Mat::A_plus.contract(b5, product_dims16);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims17 = {Eigen::IndexPair<u64>(1, 0)};
    q5 = Mat::A_plus.contract(c5, product_dims17);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims18 = {Eigen::IndexPair<u64>(1, 0)};
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
    b6_1 = Mat::randomMatrixXu(D, B);
    b6_2 = Mat::randomMatrixXu(D, B);
    b6_3 = Mat::randomMatrixXu(D, B);
    c6_1 = Mat::randomMatrixXu(B, hiddenDim);
    c6_2 = Mat::randomMatrixXu(B, hiddenDim);
    c6_3 = Mat::randomMatrixXu(B, hiddenDim);
    d6_1 = b6_1 * c6_1;
    d6_2 = Mat::randomMatrixXu(D, hiddenDim);
    d6_3 = Mat::randomMatrixXu(D, hiddenDim);
    Tensor<u64, 3> b6(3, D, B);
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < D; i++)
        {
            b6(0, i, j) = b6_1(i, j);
            b6(1, i, j) = b6_2(i, j);
            b6(2, i, j) = b6_3(i, j);
        }
    }
    Tensor<u64, 3> c6(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            c6(0, i, j) = c6_1(i, j);
            c6(1, i, j) = c6_2(i, j);
            c6(2, i, j) = c6_3(i, j);
        }
    }
    Tensor<u64, 3> d6(3, D, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < D; i++)
        {
            d6(0, i, j) = d6_1(i, j);
            d6(1, i, j) = d6_2(i, j);
            d6(2, i, j) = d6_3(i, j);
        }
    }

    Tensor<u64, 3> r6, q6, t6;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims19 = {Eigen::IndexPair<u64>(1, 0)};
    r6 = Mat::A_plus.contract(b6, product_dims19);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims20 = {Eigen::IndexPair<u64>(1, 0)};
    q6 = Mat::A_plus.contract(c6, product_dims20);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims21 = {Eigen::IndexPair<u64>(1, 0)};
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

    // for(hiddenDim，B)X(B, numClass)
    b7_1 = Mat::randomMatrixXu(hiddenDim, B);
    b7_2 = Mat::randomMatrixXu(hiddenDim, B);
    b7_3 = Mat::randomMatrixXu(hiddenDim, B);
    c7_1 = Mat::randomMatrixXu(B, numClass);
    c7_2 = Mat::randomMatrixXu(B, numClass);
    c7_3 = Mat::randomMatrixXu(B, numClass);
    d7_1 = b7_1 * c7_1;
    d7_2 = Mat::randomMatrixXu(hiddenDim, numClass);
    d7_3 = Mat::randomMatrixXu(hiddenDim, numClass);
    Tensor<u64, 3> b7(3, hiddenDim, B);
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < hiddenDim; i++)
        {
            b7(0, i, j) = b7_1(i, j);
            b7(1, i, j) = b7_2(i, j);
            b7(2, i, j) = b7_3(i, j);
        }
    }
    Tensor<u64, 3> c7(3, B, numClass);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            c7(0, i, j) = c7_1(i, j);
            c7(1, i, j) = c7_2(i, j);
            c7(2, i, j) = c7_3(i, j);
        }
    }
    Tensor<u64, 3> d7(3, hiddenDim, numClass);
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            d7(0, i, j) = d7_1(i, j);
            d7(1, i, j) = d7_2(i, j);
            d7(2, i, j) = d7_3(i, j);
        }
    }

    Tensor<u64, 3> r7, q7, t7;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims22 = {Eigen::IndexPair<u64>(1, 0)};
    r7 = Mat::A_plus.contract(b7, product_dims22);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims23 = {Eigen::IndexPair<u64>(1, 0)};
    q7 = Mat::A_plus.contract(c7, product_dims23);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims24 = {Eigen::IndexPair<u64>(1, 0)};
    t7 = Mat::A_plus.contract(d7, product_dims24);
    ofstream F7_0, F7_1, F7_2, F7_3;
    F7_0.open("Mul_Triplets/MT7_0.txt");
    F7_1.open("Mul_Triplets/MT7_1.txt");
    F7_2.open("Mul_Triplets/MT7_2.txt");
    F7_3.open("Mul_Triplets/MT7_3.txt");
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < B; j++)
        {
            F7_0 << r7(0, i, j) << ',';
            F7_1 << r7(1, i, j) << ',';
            F7_2 << r7(2, i, j) << ',';
            F7_3 << r7(3, i, j) << ',';
        }
        F7_0 << std::endl;
        F7_1 << std::endl;
        F7_2 << std::endl;
        F7_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            F7_0 << q7(0, i, j) << ',';
            F7_1 << q7(1, i, j) << ',';
            F7_2 << q7(2, i, j) << ',';
            F7_3 << q7(3, i, j) << ',';
        }
        F7_0 << std::endl;
        F7_1 << std::endl;
        F7_2 << std::endl;
        F7_3 << std::endl;
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            F7_0 << t7(0, i, j) << ',';
            F7_1 << t7(1, i, j) << ',';
            F7_2 << t7(2, i, j) << ',';
            F7_3 << t7(3, i, j) << ',';
        }
        F7_0 << std::endl;
        F7_1 << std::endl;
        F7_2 << std::endl;
        F7_3 << std::endl;
    }
    F7_0.close();
    F7_1.close();
    F7_2.close();
    F7_3.close();

    // for(hiddenDim, B)X(B, hiddenDim)
    b8_1 = Mat::randomMatrixXu(hiddenDim, B);
    b8_2 = Mat::randomMatrixXu(hiddenDim, B);
    b8_3 = Mat::randomMatrixXu(hiddenDim, B);
    c8_1 = Mat::randomMatrixXu(B, hiddenDim);
    c8_2 = Mat::randomMatrixXu(B, hiddenDim);
    c8_3 = Mat::randomMatrixXu(B, hiddenDim);
    d8_1 = b8_1 * c8_1;
    d8_2 = Mat::randomMatrixXu(hiddenDim, hiddenDim);
    d8_3 = Mat::randomMatrixXu(hiddenDim, hiddenDim);
    Tensor<u64, 3> b8(3, hiddenDim, B);
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < hiddenDim; i++)
        {
            b8(0, i, j) = b8_1(i, j);
            b8(1, i, j) = b8_2(i, j);
            b8(2, i, j) = b8_3(i, j);
        }
    }
    Tensor<u64, 3> c8(3, B, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < B; i++)
        {
            c8(0, i, j) = c8_1(i, j);
            c8(1, i, j) = c8_2(i, j);
            c8(2, i, j) = c8_3(i, j);
        }
    }
    Tensor<u64, 3> d8(3, hiddenDim, hiddenDim);
    for (int j = 0; j < hiddenDim; j++)
    {
        for (int i = 0; i < hiddenDim; i++)
        {
            d8(0, i, j) = d8_1(i, j);
            d8(1, i, j) = d8_2(i, j);
            d8(2, i, j) = d8_3(i, j);
        }
    }

    Tensor<u64, 3> r8, q8, t8;
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims25 = {Eigen::IndexPair<u64>(1, 0)};
    r8 = Mat::A_plus.contract(b8, product_dims25);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims26 = {Eigen::IndexPair<u64>(1, 0)};
    q8 = Mat::A_plus.contract(c8, product_dims26);
    Eigen::array<Eigen::IndexPair<u64>, 1> product_dims27 = {Eigen::IndexPair<u64>(1, 0)};
    t8 = Mat::A_plus.contract(d8, product_dims27);
    ofstream F8_0, F8_1, F8_2, F8_3;
    F8_0.open("Mul_Triplets/MT8_0.txt");
    F8_1.open("Mul_Triplets/MT8_1.txt");
    F8_2.open("Mul_Triplets/MT8_2.txt");
    F8_3.open("Mul_Triplets/MT8_3.txt");
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < B; j++)
        {
            F8_0 << r8(0, i, j) << ',';
            F8_1 << r8(1, i, j) << ',';
            F8_2 << r8(2, i, j) << ',';
            F8_3 << r8(3, i, j) << ',';
        }
        F8_0 << std::endl;
        F8_1 << std::endl;
        F8_2 << std::endl;
        F8_3 << std::endl;
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F8_0 << q8(0, i, j) << ',';
            F8_1 << q8(1, i, j) << ',';
            F8_2 << q8(2, i, j) << ',';
            F8_3 << q8(3, i, j) << ',';
        }
        F8_0 << std::endl;
        F8_1 << std::endl;
        F8_2 << std::endl;
        F8_3 << std::endl;
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            F8_0 << t8(0, i, j) << ',';
            F8_1 << t8(1, i, j) << ',';
            F8_2 << t8(2, i, j) << ',';
            F8_3 << t8(3, i, j) << ',';
        }
        F8_0 << std::endl;
        F8_1 << std::endl;
        F8_2 << std::endl;
        F8_3 << std::endl;
    }
    F8_0.close();
    F8_1.close();
    F8_2.close();
    F8_3.close();

    MatrixXu m0 = Mat::randomMatrixXu(B, numClass);
    MatrixXu temp_vec(3, 1);
    MatrixXu A_plus_mat = Mat::toMatrix(Mat::A_plus);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << m0(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m0_0(i, j) = temp(0, 0);
            m0_1(i, j) = temp(1, 0);
            m0_2(i, j) = temp(2, 0);
            m0_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixXu(m0);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << m0(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m_00(i, j) = temp(0, 0);
            m_01(i, j) = temp(1, 0);
            m_02(i, j) = temp(2, 0);
            m_03(i, j) = temp(3, 0);
        }
    }

    MatrixXu m1 = Mat::randomMatrixXu(D, numClass);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << m1(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m1_0(i, j) = temp(0, 0);
            m1_1(i, j) = temp(1, 0);
            m1_2(i, j) = temp(2, 0);
            m1_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixXu(m1);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << m1(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m_10(i, j) = temp(0, 0);
            m_11(i, j) = temp(1, 0);
            m_12(i, j) = temp(2, 0);
            m_13(i, j) = temp(3, 0);
        }
    }

    MatrixXu m2 = Mat::randomMatrixXu(B, hiddenDim);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m2(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m2_0(i, j) = temp(0, 0);
            m2_1(i, j) = temp(1, 0);
            m2_2(i, j) = temp(2, 0);
            m2_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixXu(m2);
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m2(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m_20(i, j) = temp(0, 0);
            m_21(i, j) = temp(1, 0);
            m_22(i, j) = temp(2, 0);
            m_23(i, j) = temp(3, 0);
        }
    }

    MatrixXu m3 = Mat::randomMatrixXu(D, hiddenDim);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m3(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m3_0(i, j) = temp(0, 0);
            m3_1(i, j) = temp(1, 0);
            m3_2(i, j) = temp(2, 0);
            m3_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixXu(m3);
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m3(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m_30(i, j) = temp(0, 0);
            m_31(i, j) = temp(1, 0);
            m_32(i, j) = temp(2, 0);
            m_33(i, j) = temp(3, 0);
        }
    }

    MatrixXu m4 = Mat::randomMatrixXu(hiddenDim, numClass);
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << m4(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m4_0(i, j) = temp(0, 0);
            m4_1(i, j) = temp(1, 0);
            m4_2(i, j) = temp(2, 0);
            m4_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixXu(m4);
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << m4(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m_40(i, j) = temp(0, 0);
            m_41(i, j) = temp(1, 0);
            m_42(i, j) = temp(2, 0);
            m_43(i, j) = temp(3, 0);
        }
    }

    MatrixXu m5 = Mat::randomMatrixXu(hiddenDim, hiddenDim);
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m5(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m5_0(i, j) = temp(0, 0);
            m5_1(i, j) = temp(1, 0);
            m5_2(i, j) = temp(2, 0);
            m5_3(i, j) = temp(3, 0);
        }
    }

    Mat::truncateMatrixXu(m5);
    for (int i = 0; i < hiddenDim; i++)
    {
        for (int j = 0; j < hiddenDim; j++)
        {
            temp_vec << m5(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp = A_plus_mat * temp_vec;
            m_50(i, j) = temp(0, 0);
            m_51(i, j) = temp(1, 0);
            m_52(i, j) = temp(2, 0);
            m_53(i, j) = temp(3, 0);
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
            r0(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile0, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            q0(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile0, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            t0(i, j) = Constant::Util::getu64(ch);
        }
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
            r1(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile1, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            q1(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < D; i++)
    {
        string s;
        getline(infile1, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            t1(i, j) = Constant::Util::getu64(ch);
        }
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
            r2(i, j) = Constant::Util::getu64(ch);
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
            q2(i, j) = Constant::Util::getu64(ch);
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
            t2(i, j) = Constant::Util::getu64(ch);
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
            r3(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile3, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            q3(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile3, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            t3(i, j) = Constant::Util::getu64(ch);
        }
    }
    ifstream infile4("Mul_Triplets/MT4_" + to_string(party) + ".txt");
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile4, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            r4(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < numClass; i++)
    {
        string s;
        getline(infile4, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            q4(i, j) = Constant::Util::getu64(ch);
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
            t4(i, j) = Constant::Util::getu64(ch);
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
            r5(i, j) = Constant::Util::getu64(ch);
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
            q5(i, j) = Constant::Util::getu64(ch);
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
            t5(i, j) = Constant::Util::getu64(ch);
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
            r6(i, j) = Constant::Util::getu64(ch);
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
            q6(i, j) = Constant::Util::getu64(ch);
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
            t6(i, j) = Constant::Util::getu64(ch);
        }
    }
    ifstream infile7("Mul_Triplets/MT7_" + to_string(party) + ".txt");
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile7, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < B; j++)
        {
            r7(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile7, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            q7(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile7, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < numClass; j++)
        {
            t7(i, j) = Constant::Util::getu64(ch);
        }
    }

    ifstream infile8("Mul_Triplets/MT8_" + to_string(party) + ".txt");
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile8, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < B; j++)
        {
            r8(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < B; i++)
    {
        string s;
        getline(infile8, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            q8(i, j) = Constant::Util::getu64(ch);
        }
    }
    for (int i = 0; i < hiddenDim; i++)
    {
        string s;
        getline(infile8, s);
        char *ch;
        ch = const_cast<char *>(s.c_str());
        for (int j = 0; j < hiddenDim; j++)
        {
            t8(i, j) = Constant::Util::getu64(ch);
        }
    }

    cout << "get triplets" << endl;
}

void Secret_Mul::Mul_truncation(MatrixXu &z)
{
    int row = z.rows();
    int col = z.cols();
    MatrixXu r0(row, col), r1(row, col), r2(row, col), r3(row, col);
    MatrixXu r_0(row, col), r_1(row, col), r_2(row, col), r_3(row, col);

    if (row == B && col == numClass)
    {
        r0 = Secret_Mul::m0_0;
        r1 = Secret_Mul::m0_1;
        r2 = Secret_Mul::m0_2;
        r3 = Secret_Mul::m0_3;
        r_0 = Secret_Mul::m_00;
        r_1 = Secret_Mul::m_01;
        r_2 = Secret_Mul::m_02;
        r_3 = Secret_Mul::m_03;
    }
    else if (row == D && col == numClass)
    {

        r0 = Secret_Mul::m1_0;
        r1 = Secret_Mul::m1_1;
        r2 = Secret_Mul::m1_2;
        r3 = Secret_Mul::m1_3;
        r_0 = Secret_Mul::m_10;
        r_1 = Secret_Mul::m_11;
        r_2 = Secret_Mul::m_12;
        r_3 = Secret_Mul::m_13;
    }
    else if (row == B && col == B)
    {
        r0 = Secret_Mul::m2_0;
        r1 = Secret_Mul::m2_1;
        r2 = Secret_Mul::m2_2;
        r3 = Secret_Mul::m2_3;
        r_0 = Secret_Mul::m_20;
        r_1 = Secret_Mul::m_21;
        r_2 = Secret_Mul::m_22;
        r_3 = Secret_Mul::m_23;
    }
    else if (row == D && col == B)
    {
        r0 = Secret_Mul::m3_0;
        r1 = Secret_Mul::m3_1;
        r2 = Secret_Mul::m3_2;
        r3 = Secret_Mul::m3_3;
        r_0 = Secret_Mul::m_30;
        r_1 = Secret_Mul::m_31;
        r_2 = Secret_Mul::m_32;
        r_3 = Secret_Mul::m_33;
    }
    else if (row == hiddenDim && col == numClass)
    {
        r0 = Secret_Mul::m4_0;
        r1 = Secret_Mul::m4_1;
        r2 = Secret_Mul::m4_2;
        r3 = Secret_Mul::m4_3;
        r_0 = Secret_Mul::m_40;
        r_1 = Secret_Mul::m_41;
        r_2 = Secret_Mul::m_42;
        r_3 = Secret_Mul::m_43;
    }
    else if (row == hiddenDim && col == hiddenDim)
    {
        r0 = Secret_Mul::m5_0;
        r1 = Secret_Mul::m5_1;
        r2 = Secret_Mul::m5_2;
        r3 = Secret_Mul::m5_3;
        r_0 = Secret_Mul::m_50;
        r_1 = Secret_Mul::m_51;
        r_2 = Secret_Mul::m_52;
        r_3 = Secret_Mul::m_53;
    }

    if (party == 0)
    {
        MatrixXu z0_sub_r0 = z - r0;
        MatrixXu reveal = Secret_Mul::Mul_reveal(z0_sub_r0);
        MatrixXu z_sub_r = reveal;
        Mat::truncateMatrixXu(z_sub_r);
        z = z_sub_r + r_0;
    }
    else if (party == 2)
    {
        MatrixXu z1_sub_r1 = z - r2;
        Secret_Mul::Mul_reveal(z1_sub_r1);
        z = r_2;
    }
    else if (party == 3)
    {
        MatrixXu z2_sub_r2 = z - r3;
        Secret_Mul::Mul_reveal(z2_sub_r2);
        z = r_3;
    }
    else if (party == 1)
    {
        z = r_1;
    }
}

MatrixXu Secret_Mul::Multiply(MatrixXu &x, MatrixXu &y, MatrixXu &r, MatrixXu &q, MatrixXu &t)
{
    MatrixXu result;
    MatrixXu y_plus_q = y + q;
    MatrixXu x_plus_r = x + r;

    MatrixXu Y_plus_Q, X_plus_R, combination, rev_combine;
    // (B, D)*(D, numClass)
    if (party == 0 || party == 2 || party == 3)
    {
        if (x.rows() == B && x.cols() == D && y.rows() == D && y.cols() == numClass)
        {
            // cout << "q:" <<Secret_Mul::reveal(q)<<endl;
            // cout << "r:" <<Secret_Mul::reveal(r)<<endl;
            combination.resize(B + numClass, D);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(numClass).transpose();
            X_plus_R = rev_combine.topRows(B);
        }
        // (D, B)*(B, numClass)
        else if (x.rows() == D && x.cols() == B && y.rows() == B && y.cols() == numClass)
        {
            combination.resize(D + numClass, B);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(numClass).transpose();
            X_plus_R = rev_combine.topRows(D);
        }
        // (B, D)*(D, hiddenDim)
        else if (x.rows() == B && x.cols() == D && y.rows() == D && y.cols() == hiddenDim)
        {
            combination.resize(B + hiddenDim, D);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
            X_plus_R = rev_combine.topRows(B);
        }
        // (B, hiddenDim)*(hiddenDim, numClass)
        else if (x.rows() == B && x.cols() == hiddenDim && y.rows() == hiddenDim && y.cols() == numClass)
        {
            combination.resize(B + numClass, hiddenDim);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(numClass).transpose();
            X_plus_R = rev_combine.topRows(B);
        }
        // (B, numClass)*(numClass, hiddenDim)
        else if (x.rows() == B && x.cols() == numClass && y.rows() == numClass && y.cols() == hiddenDim)
        {
            combination.resize(B + hiddenDim, numClass);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
            X_plus_R = rev_combine.topRows(B);
        }
        // (B, hiddenDim)*(hiddenDim, hiddenDim)
        else if (x.rows() == B && x.cols() == hiddenDim && y.rows() == hiddenDim && y.cols() == hiddenDim)
        {
            combination.resize(B + hiddenDim, hiddenDim);
            combination << x_plus_r,
                y_plus_q;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(hiddenDim);
            X_plus_R = rev_combine.topRows(B);
        }
        // (hiddenDim, B)*(B, numClass)
        else if (x.rows() == hiddenDim && x.cols() == B && y.rows() == B && y.cols() == numClass)
        {
            combination.resize(hiddenDim + numClass, B);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(numClass).transpose();
            X_plus_R = rev_combine.topRows(hiddenDim);
        }
        // (D, B)*(B, hiddenDim)
        else if (x.rows() == D && x.cols() == B && y.rows() == B && y.cols() == hiddenDim)
        {
            combination.resize(D + hiddenDim, B);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
            X_plus_R = rev_combine.topRows(D);
        }
        // (hiddenDim, B)*(B, hiddenDim)
        else if (x.rows() == hiddenDim && x.cols() == B && y.rows() == B && y.cols() == hiddenDim)
        {
            combination.resize(hiddenDim + hiddenDim, B);
            MatrixXu y_plus_q_trans = y_plus_q.transpose();
            combination << x_plus_r,
                y_plus_q_trans;
            rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.bottomRows(hiddenDim).transpose();
            X_plus_R = rev_combine.topRows(hiddenDim);
        }
        result = x * Y_plus_Q - X_plus_R * q + t;
        Secret_Mul::Mul_truncation(result);
    }
    if (party == 0)
    {
        MatrixXu temp;
        if (x.rows() == B && y.cols() == numClass)
        {
            temp = Secret_Mul::m_01;
        }
        else if (x.rows() == D && y.cols() == numClass)
        {
            temp = Secret_Mul::m_11;
        }
        else if (x.rows() == B && y.cols() == hiddenDim)
        {
            temp = Secret_Mul::m_21;
        }
        else if (x.rows() == D && y.cols() == hiddenDim)
        {
            temp = Secret_Mul::m_31;
        }
        else if (x.rows() == hiddenDim && y.cols() == numClass)
        {
            temp = Secret_Mul::m_41;
        }
        else if (x.rows() == hiddenDim && y.cols() == hiddenDim)
        {
            temp = Secret_Mul::m_51;
        }
        tel.send(&temp, 1);
    }
    if (party == 1)
    {
        tel.receive(&result, 0);
    }
    return result;
}

// todo:三元组的生成 目前全部设置为0
MatrixXu Secret_Mul::CwiseProduct(MatrixXu &x, MatrixXu &y, MatrixXu &r, MatrixXu &q, MatrixXu &t)
{
    r.setZero();
    q.setZero();
    t.setZero();
    MatrixXu result;
    MatrixXu y_plus_q = y + q;
    MatrixXu x_plus_r = x + r;

    MatrixXu Y_plus_Q, X_plus_R, combination, rev_combine;
    if (party == 0 || party == 2 || party == 3)
    {
        if (x.rows() == B && x.cols() == numClass)
        {
            combination.resize(B, numClass * 2);
            combination << y_plus_q, x_plus_r;
            MatrixXu rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.leftCols(numClass);
            X_plus_R = rev_combine.rightCols(numClass);
        }
        else if (x.rows() == B && x.cols() == hiddenDim)
        {
            combination.resize(B, hiddenDim + hiddenDim);
            combination << y_plus_q, x_plus_r;
            MatrixXu rev_combine = Secret_Mul::Mul_reveal(combination);
            Y_plus_Q = rev_combine.leftCols(hiddenDim);
            X_plus_R = rev_combine.rightCols(hiddenDim);
        }
        result = x.cwiseProduct(Y_plus_Q) - X_plus_R.cwiseProduct(q) + t;
        Secret_Mul::Mul_truncation(result);
    }
    else if (party == 1)
    {
        if (x.rows() == B && x.cols() == numClass)
        {
            result = Secret_Mul::m_01;
        }
        else if (x.rows() == B && x.cols() == hiddenDim)
        {
            result = Secret_Mul::m_21;
        }
    }
    return result;
}

MatrixXu Secret_Mul::constant_Mul(MatrixXu &x, double d)
{
    MatrixXu result = x * (Constant::Util::double_to_u64(d));
    Secret_Mul::Mul_truncation(result);
    return result;
}

MatrixXu Secret_Mul::Mul_reveal(MatrixXu &data)
{
    int row = data.rows();
    int col = data.cols();
    MatrixXu res;
    if (party == 0)
    {
        MatrixXu data1, data2;
        tel.receive(&data1, 2);
        tel.receive(&data2, 3);

        res = (data + data1 * 3 + data2 * (UINT64_MAX - 1));
        tel.send(&res, 2);
        tel.send(&res, 3);
    }
    else if (party == 2 || party == 3)
    {
        tel.send(&data, 0);
        tel.receive(&res, 0);
    }
    return res;
}

MatrixXu Secret_Mul::reveal2(MatrixXu &data)
{
    int row = data.rows();
    int col = data.cols();
    MatrixXu res;
    if (party == 0)
    {
        MatrixXu data1, data2;
        tel.receive(&data1, 1);
        tel.receive(&data2, 2);

        res = (-data + data1 - data2) / 2;
        tel.send(&res, 1);
        tel.send(&res, 2);
    }
    else if (party == 1 || party == 2)
    {
        tel.send(&data, 0);
        tel.receive(&res, 0);
    }
    return res;
}

u64 Secret_Mul::Generate_triplets_Bob(MatrixXu &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    MatrixXu message_send(3, 1), message_recv(3, 1);
    if (length % 2 != 0)
    {
        std::cout << "D should be an even number!" << std::endl;
    }
    u64 temp = 0;
    u64 b_j = Constant::Util::random_u64();
    u64 d_j = Constant::Util::random_u64();

    // make sure that a_i + c_i != 0
    while (b_j - d_j == 0)
    {
        b_j = Constant::Util::random_u64();
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
            }
            temp += message_recv(1, 0) * (2 * mul_mat(i, j * 2 + 1) - b_j) + message_recv(2, 0) * (2 * mul_mat(i, j * 2) - d_j) + message_recv(0, 0) * (d_j - 2 * b_j);
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

u64 Secret_Mul::Generate_triplets_Alice(MatrixXu &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    MatrixXu message_send(3, 1), message_recv(3, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    u64 temp = 0;
    u64 a_i = Constant::Util::random_u64();
    u64 c_i = Constant::Util::random_u64();

    // make sure that a_i + c_i != 0
    while (a_i + c_i == 0)
    {
        a_i = Constant::Util::random_u64();
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

u64 Secret_Mul::Generate_triplets_Bob_improve(MatrixXu &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    MatrixXu message_send(1 + length, 1), message_recv(1 + length, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    u64 temp = 0;
    u64 b_j = Constant::Util::random_u64();
    u64 d_j = Constant::Util::random_u64();

    // make sure that a_i + c_i != 0
    while (b_j - d_j == 0)
    {
        b_j = Constant::Util::random_u64();
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

u64 Secret_Mul::Generate_triplets_Alice_improve(MatrixXu &mul_mat, int length, int party, int i, bool is_ui, bool send_first)
{
    MatrixXu message_send(1 + length, 1), message_recv(1 + length, 1);
    if (length % 2 != 0)
    {
        std::cout << "D+1 should be an even number!" << std::endl;
    }
    u64 temp = 0;
    u64 a_i = Constant::Util::random_u64();
    u64 c_i = Constant::Util::random_u64();

    // make sure that a_i + c_i != 0
    while (a_i + c_i == 0)
    {
        a_i = Constant::Util::random_u64();
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
