#ifndef NN_H
#define NN_H

#include "../util/Mat.h"
#include "../util/IOManager.h"
#include "../core/Secret_Mul.h"
#include "../core/Secret_Cmp.h"

extern SocketManager::pMPL tel;
extern int party;

class NN
{
public:

    static Matrixint64 w, y_inf;

    static int myrandom(int i);
    static vector<int> random_perm();
    static void next_batch(Matrixint64 &batch, int start, vector<int> &perm, Matrixint64 &data);
    static void train_model();
    static void test_model();
    static void inference();
};

#endif // NN_H