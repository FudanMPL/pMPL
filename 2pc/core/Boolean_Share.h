#ifndef BOOLEAN_SHARE_H
#define BOOLEAN_SHARE_H

#include "../util/SocketManager.h"
#include "../util/Mat.h"

extern SocketManager::pMPL tel;
extern int party;

class Boolean_Share
{
public:
    // static Matrix8 a, b, c;
    // static Matrix8 r_add_share, r_bool_share;
    static Matrixint64 secret_share(Matrixint64 &share);
    static Matrix8 secret_share(Matrix8 &share);
    static Matrixint64 reveal(Matrixint64 &share);
    static Matrix8 reveal(Matrix8 &share);
    static Matrixint64 add_reveal(Matrixint64 &share);
    static void get_byte_and_triplets();                  // offline阶段生成三元组 目前全部设置为0
    static void get_n_dabits();                           // used for B2A
    static Matrix8 byte_and_byte(Matrix8 &x, Matrix8 &y); // 原本只需要对位操作 但最小操作单位为字节
    static Matrixint64 add(Matrixint64 &x, Matrixint64 &y);
    static Matrixint64 bool_and(Matrixint64 &x, Matrixint64 &y);
    static Matrixint64 to_additive_share(Matrixint64 &x);
    static Matrixint64 secret_share_for_test(Matrixint64 &x);
    static void test(); // test
};

#endif