#ifndef SECRET_CMP_H
#define SECRET_CMP_H

#include "../util/Mat.h"
#include "Boolean_Share.h"

extern int party;
extern SocketManager::pMPL tel;

class Secret_Cmp
{
public:
    static Matrixint64 to_Boolean_Share(Matrixint64 &x);
    static Matrixint64 get_sign(Matrixint64 &x);
    static Matrixint64 get_sign_xor_1(Matrixint64 &x);
    static Matrixint64 Relu(Matrixint64 x);
    static Matrixint64 Sigmoid(Matrixint64 x);
};

#endif