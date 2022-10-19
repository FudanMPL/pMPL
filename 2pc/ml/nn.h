#ifndef NN_H
#define NN_H

#include "../util/Mat.h"
#include "../util/IOManager.h"
#include "../core/Secret_Mul.h"
#include "../core/Secret_Cmp.h"

extern int party;

class Layer
{
public:
    MatrixXu input;
    MatrixXu weight;
    virtual MatrixXu forward(MatrixXu &x) = 0;
    virtual MatrixXu backward(MatrixXu &x) = 0;
};

class LinearLayer : public Layer
{
public:
    LinearLayer(int input_size, int output_size, bool first_layer = false);
    // MatrixXu weight;
    // MatrixXu input;
    int input_size;
    int output_size;
    bool first_layer;
    MatrixXu forward(MatrixXu &x);
    MatrixXu backward(MatrixXu &delta);
};

class ReluLayer : public Layer
{
public:
    MatrixXu sign;
    MatrixXu forward(MatrixXu &x);
    MatrixXu backward(MatrixXu &delta);
};

class NN
{
public:
    vector<Layer *> layers;
    static int myrandom(int i);
    static vector<int> random_perm();
    void next_batch(MatrixXu &batch, int start, vector<int> &perm, MatrixXu &data);
    MatrixXu argmax(MatrixXu &x);
    void add_layer(Layer *layer);
    MatrixXu forward(MatrixXu &x);
    void backward(MatrixXu &delta);
    void fit(MatrixXu &x, MatrixXu &y, int epoch);
    static void train_model();
    void test_model();
    void inference(MatrixXu &x, MatrixXu &y);
};

// class NN
// {
// public:

//     static MatrixXu w, y_inf;

//     static int myrandom(int i);
//     static vector<int> random_perm();
//     static void next_batch(MatrixXu &batch, int start, vector<int> &perm, MatrixXu &data);
//     static MatrixXu argmax(MatrixXu &x);
//     static void train_model();
//     static void test_model();
//     static void inference();
// };

#endif // NN_H