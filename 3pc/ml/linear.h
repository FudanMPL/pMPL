#ifndef LINEAR_H
#define LINEAR_H

#include "../util/Mat.h"
#include "../util/IOManager.h"
#include "../core/Secret_Mul.h"

extern SocketManager::pMPL tel;
extern int party;

class Linear
{
public:
    static MatrixXu w, y_inf;

    static int myrandom(int i);
    static vector<int> random_perm();

    static void next_batch(MatrixXu &batch, int start, vector<int> &perm, MatrixXu &data);
    static MatrixXu argmax(MatrixXu &x);
    static void train_model();
    static void test_model();
    static void inference();
};

#endif // LINEAR_H