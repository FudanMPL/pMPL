#ifndef SECRET_CMP_H
#define SECRET_CMP_H

#include "../util/Mat.h"
#include "Boolean_Share.h"

extern int party;

class Secret_Cmp
{
public:
    static MatrixXu to_Boolean_Share(MatrixXu &x);
    static MatrixXu get_bool_share_bit(MatrixXu &x);
    static MatrixXu get_sign(MatrixXu &x);
    static MatrixXu get_sign_xor_1(MatrixXu x);
    static MatrixXu Relu(MatrixXu x);
    static MatrixXu Sigmoid(MatrixXu x);
};

#endif