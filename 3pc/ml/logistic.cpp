#include "logistic.h"

Matrixint64 Logistic::w = Matrixint64(D, 1);
Matrixint64 Logistic::y_inf = Matrixint64(testN, 1);

// vector<int> read_VT(Matrixint64 &a, Matrixint64 &b_1, Matrixint64 &c_1, Matrixint64 &b_2, Matrixint64 &c_2, int party)
// {

// }

int Logistic::myrandom(int i) { return rand() % i; }

vector<int> Logistic::random_perm()
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

void Logistic::next_batch(Matrixint64 &batch, int start, vector<int> &perm, Matrixint64 &data)
{
    // Constant::Clock *clock_train;
    // clock_train = new Constant::Clock(2);
    for (int i = 0; i < B; i++)
    {
        batch.row(i) = data.row(perm[start + i]);
    }
    // cout << clock_train->get() << endl;
}

void Logistic::sigmoid(Matrixint64 &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x(i) >= 9223372036854775808 && x(i) <= 18446744073709027328)
            x(i) = 0;
        else if (x(i) >= 1048576 && x(i) < 9223372036854775808)
            x(i) = 1048576;
        else
            x(i) = x(i) + 524288;
    }
}

void Logistic::train_model()
{

    Matrixint64 x_batch(B, D), y_batch(B, 1);
    Matrixint64 train_data = IOManager::train_data;
    Matrixint64 train_label = IOManager::train_label;

    // static default_random_engine e(time(0));
    // static normal_distribution<double> n(0, 0.05);
    // MatrixXd m = MatrixXd::Zero(D, 1).unaryExpr([](double dummy)
    //                                                 { return n(e); });
    // for (int i = 0; i < D; i++)
    // {
    //     w(i, 0) = Constant::Util::double_to_int64(m(i, 0));
    // }
    w.setZero();
    cout << "weights initialized" << endl;

    vector<int> perm = random_perm();

    int start = 0;
    Matrixint64 r0(B, D), q0(D, 1), t0(B, 1), r1(D, B), q1(B, 1), t1(D, 1);
    Matrixint64 wx(B, 1), wx_y(B, 1);
    Constant::Clock *clock_train;
    clock_train = new Constant::Clock(2);
    ofstream F;
    for (int j = 0; j < Ep; j++)
    {
        for (int i = 0; i < N / B; i++)
        {
            // cout << "第" << i << "个batch" << endl;

            next_batch(x_batch, start, perm, train_data);
            next_batch(y_batch, start, perm, train_label); //选出mini batch

            start += B;
            r0 = Secret_Mul::r0;
            r1 = Secret_Mul::r1;
            q0 = Secret_Mul::q0;
            q1 = Secret_Mul::q1;
            t0 = Secret_Mul::t0;
            t1 = Secret_Mul::t1;
            wx = Secret_Mul::Multiply(x_batch, w, r0, q0, t0);
            wx = Secret_Cmp::Sigmoid(wx); // 加入一层sigmoid函数即可
            wx_y = wx - y_batch;

            Matrixint64 x_batch_trans = x_batch.transpose();
            Matrixint64 delta = Secret_Mul::Multiply(x_batch_trans, wx_y, r1, q1, t1);

            w = w - Mat::constant_multiply(delta, R / B);
            F.open("Result/Logistic" + to_string(party) + ".txt", ios::out);
            F << w << endl;
            F.close();
        }
    }
    cout << "online time:" << clock_train->get() << endl;
    // test_model();
    inference();
    F.open("Result/Logistic" + to_string(party) + ".txt", ios::out);
    F << "Finish" << endl
      << w << endl;
    F.close();
}

void Logistic::test_model()
{
    double count = 0;
    Matrixint64 w_(D, 1);
    Matrixint64 test_data = IOManager::test_data;
    Matrixint64 test_label = IOManager::test_label;

    if (party == 0)
    {
        w_ = Secret_Mul::reveal(w);

        Matrixint64 y_ = test_data * w_;

        Mat::truncateMatrixint64(y_);
        Logistic::sigmoid(y_);

        for (int i = 0; i < testN; i++)
        {
            double yyy = Constant::Util::int64_to_double(y_(i, 0));
            if (yyy > 0.5 && test_label(i, 0) == 1048576)
            {
                count++;
            }
            else if (yyy < 0.5 && test_label(i, 0) == 0)
            {
                count++;
            }
        }
        cout << "acurracy:" << count / testN << endl;
    }
    else if (party == 2 || party == 3)
    {
        Secret_Mul::reveal(w);
    }
}

void Logistic::inference()
{
    Matrixint64 test_data = IOManager::test_data;
    Matrixint64 test_label = IOManager::test_label;
    Matrixint64 wx;
    double count = 0;
    int it = ceil(testN / B);
    Matrixint64 x_batch, y_batch, y_infer;

    Matrixint64 r0(B, D), q0(D, 1), t0(B, 1);
    r0 = Secret_Mul::r0;
    q0 = Secret_Mul::q0;
    t0 = Secret_Mul::t0;
    for (int i = 0; i < it; i++)
    {
        int temp = min(B, testN - i * B);
        x_batch = test_data.middleRows(i * B, temp);
        y_batch = test_label.middleRows(i * B, temp);
        wx = Secret_Mul::Multiply(x_batch, w, r0, q0, t0);
        y_infer = Secret_Cmp::Sigmoid(wx);
        if (party == 0 || party == 2 || party == 3)
        {
            Matrixint64 y_predict = Secret_Mul::reveal(y_infer);
            Matrixint64 y_plaintext = Secret_Mul::reveal(y_batch);
            for (int j = 0; j < temp; j++)
            {
                double yyy = Constant::Util::int64_to_double(y_predict(j));
                if (yyy > 0.5)
                    y_predict(j) = IE;
                else
                    y_predict(j) = 0;
                count = count + (y_predict(j) == y_plaintext(j));
            }
        }
    }
    if (party == 0 || party == 2 || party == 3)
    {
        cout << "accuracy of inference:" << count * 1.0 / testN << endl;
    }
}