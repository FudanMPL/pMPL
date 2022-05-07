#ifndef SECRET_MUL_H
#define SECRET_MUL_H

#include "../util/SocketManager.h"
#include "../util/Mat.h"

extern SocketManager::pMPL tel;
extern int party;

class Secret_Mul
{
public:
    // Multiply_Triplets(for(B, D)X(D, 1))
    static Matrixint64 b0_1, b0_2, b0_3, c0_1, c0_2, c0_3, d0_1, d0_2, d0_3, r0, q0, t0;
    // Multiply_Triplets(for(D, B)X(B, 1))
    static Matrixint64 b1_1, b1_2, b1_3, c1_1, c1_2, c1_3, d1_1, d1_2, d1_3, r1, q1, t1;
    // Multiply_Triplets(for(B, D)X(D, hiddenDim))
    static Matrixint64 b2_1, b2_2, b2_3, c2_1, c2_2, c2_3, d2_1, d2_2, d2_3, r2, q2, t2;
    // Multiply_Triplets(for(B, hiddenDim)X(hiddenDim, 1))
    static Matrixint64 b3_1, b3_2, b3_3, c3_1, c3_2, c3_3, d3_1, d3_2, d3_3, r3, q3, t3;
    // Multiply_Triplets(for(B, 1)X(1, hiddenDim))
    static Matrixint64 b4_1, b4_2, b4_3, c4_1, c4_2, c4_3, d4_1, d4_2, d4_3, r4, q4, t4;
    // Multiply_Triplets(for(B, hiddenDim)X(hiddenDim, hiddenDim))
    static Matrixint64 b5_1, b5_2, b5_3, c5_1, c5_2, c5_3, d5_1, d5_2, d5_3, r5, q5, t5;
    // Multiply_Triplets(for(D, B)X(B, hiddenDim))
    static Matrixint64 b6_1, b6_2, b6_3, c6_1, c6_2, c6_3, d6_1, d6_2, d6_3, r6, q6, t6;
    // random for truncation
    static Matrixint64 m0_0, m0_1, m0_2, m0_3, m1_0, m1_1, m1_2, m1_3, m2_0, m2_1, m2_2, m2_3, m3_0, m3_1, m3_2, m3_3;
    // truncation(m0_0,m0_1,……,m1_3);
    static Matrixint64 m_00, m_01, m_02, m_03, m_10, m_11, m_12, m_13, m_20, m_21, m_22, m_23, m_30, m_31, m_32, m_33;

    static void init();                                                                        // genetate Multiply Triplets
    static void get_Triplets();                                                                // get Triplets  0:(128,785)X(785,1)  1:(785,128)X(128,1)
    static void Mul_truncation(Matrixint64 &z);                                                   // for Truncation
    static Matrixint64 Multiply(Matrixint64 &x, Matrixint64 &y, Matrixint64 &r, Matrixint64 &q, Matrixint64 &t); // element-wise multiply
    static Matrixint64 Multiply_nn(Matrixint64 &x, Matrixint64 &y, Matrixint64 &r, Matrixint64 &q, Matrixint64 &t);
    static Matrixint64 Mul_reveal(Matrixint64 &data);
    static Matrixint64 Mul_reveal_nn(Matrixint64 &data);
    static Matrixint64 reveal(Matrixint64 &data);
    static Matrixint64 CwiseProduct(Matrixint64 &x, Matrixint64 &y, Matrixint64 &r, Matrixint64 &q, Matrixint64 &t); //
    static Matrixint64 constant_Mul(Matrixint64 &x, double d);
    static int64 Generate_triplets_Bob(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first);
    static int64 Generate_triplets_Alice(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first);
    static int64 Generate_triplets_Bob_improve(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first);
    static int64 Generate_triplets_Alice_improve(Matrixint64 &mul_mat, int length, int party, int i, bool is_ui, bool send_first);
};

#endif