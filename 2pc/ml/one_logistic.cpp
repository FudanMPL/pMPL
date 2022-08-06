#include <iostream>

#include "../util/Mat.h"
#include "../util/IOManager.h"
#include "../util/SocketManager.h"

using namespace std;
using namespace Eigen;

int party = 0;
SocketManager::pMPL tel;

int myrandom(int i) { return rand() % i; }

vector<int> random_perm()
{
    vector<int> temp, perm;
    for (int i = 0; i < N; i++)
        temp.push_back(i);

    for (int i = 0; i < Ep; i++)
    {                                                       // construct the random shuffled indices of every epoch
        random_shuffle(temp.begin(), temp.end(), myrandom); // random permutations of indices between 0 to N-1
        perm.insert(perm.end(), temp.begin(), temp.end());  // append the random permutated indicies
        // cout << "perm:" << perm.size() <<endl;
    }
    return perm;
}

void next_batch(MatrixXu &batch, int start, vector<int> &perm, MatrixXu &data)
{
    // Constant::Clock *clock_train;
    // clock_train = new Constant::Clock(2);
    for (int i = 0; i < B; i++)
    {
        batch.row(i) = data.row(perm[start + i]);
    }
    // cout << clock_train->get() << endl;
}

void sigmoid(MatrixXu &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x(i) >= 9223372036854775808 && x(i) <= 18446744073709027328)
            x(i) = 0;
        else if (x(i) >= 524288 && x(i) < 9223372036854775808)
            x(i) = 1048576;
        else
            x(i) = x(i) + 524288;
    }
}

MatrixXu argmax(MatrixXu &x)
{
    int row = x.rows(), col = x.cols();
    MatrixXu res(row, 1);
    Matrixint64 temp = x.cast<int64>();
    for (int i = 0; i < row; i++)
    {
        int index = 0;
        int64 max = temp(i, 0);
        for (int j = 1; j < col; j++)
        {
            if (temp(i, j) > max)
            {
                max = temp(i, j);
                index = j;
            }
        }

        // SVHN
        res(i, 0) = index % 10;

        //mnist and fashion_mnist
        // res(i, 0) = index;
    }
    return res;
}

int main(int argc, char **argv)
{
    // IOManager::init();
    MatrixXu w(D, numClass);
    MatrixXu x_batch(B, D), y_batch(B, numClass);
    MatrixXu train_data = IOManager::train_data;
    MatrixXu train_label = IOManager::train_label;

    // ifstream intest("data/fashion_mnist/fashion_mnist_train.csv");
    ifstream intest("data/svhn/svhn_train.csv");
    IOManager::load_data(intest, train_data, train_label, N);

    MatrixXu test_data = IOManager::test_data;
    MatrixXu test_label = IOManager::test_label;
    // ifstream intest1("data/fashion_mnist/fashion_mnist_test.csv");
    ifstream intest1("data/svhn/svhn_test.csv");
    IOManager::load_data(intest1, test_data, test_label, testN);

    // static default_random_engine e(time(0));
    // static normal_distribution<double> n(0, 0.05);
    // MatrixXd m = MatrixXd::Zero(D + 1, 1).unaryExpr([](double dummy)
    //                                                 { return n(e); });
    // cout << m << endl;
    // for (int i = 0; i < D + 1; i++)
    // {
    //     w(i, 0) = Constant::Util::double_to_u64(m(i, 0));
    // }
    // cout << w << endl;
    w.setZero();
    cout << "weights initialized" << endl;

    vector<int> perm = random_perm();
    // for(int i=0;i<perm.size();i++)
    // cout<<perm[i]<<endl;

    int start = 0;
    MatrixXu wx(B, numClass), wx_y(B, numClass);
    MatrixXu result;
    for (int j = 0; j < Ep; j++)
    {
        double count = 0;
        double error = 0;
        for (int i = 0; i < N / B; i++)
        {
            // cout << "第" << i << "个batch" << endl;

            next_batch(x_batch, start, perm, train_data);
            next_batch(y_batch, start, perm, train_label); //选出mini batch

            start += B;

            wx = x_batch * w;
            Mat::truncateMatrixXu(wx);
            sigmoid(wx);
            wx_y = wx - y_batch;

            error = error + (wx_y.array() * wx_y.array()).sum();

            MatrixXu x_batch_trans = x_batch.transpose();
            // cout << x_batch_trans<<endl <<endl;
            MatrixXu delta;
            delta = x_batch_trans * wx_y;
            Mat::truncateMatrixXu(delta);
            w = w - Mat::constant_multiply(delta, 0.01 / B);
        }
        cout << "square error" << endl;
        cout << error / N << endl;
        result = test_data * w;
        // cout << result << endl;
        Mat::truncateMatrixXu(result);
        sigmoid(result);
        // cout << result << endl;
        MatrixXu res = argmax(result);
        MatrixXu label = argmax(test_label);
        for (int i = 0; i < testN; i++)
        {
            // double resulttt = Constant::Util::int64_to_double(result(i, 0));
            // if (resulttt > 0.5 && test_label(i, 0) == 1048576)
            //     count++;
            // else if (resulttt < 0.5 && test_label(i, 0) == 0)
            //     count++;
            if (res(i, 0) == label(i, 0))
            {
                count++;
            }
        }
        cout << count / testN << endl;
    }
    // cout <<result <<endl;
    // cout << w << endl;
}