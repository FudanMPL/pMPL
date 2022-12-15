#include "linear.h"

MatrixXu Linear::w = MatrixXu(D, numClass);
MatrixXu Linear::y_inf = MatrixXu(testN, numClass);

int Linear::myrandom(int i) { return rand() % i; }

vector<int> Linear::random_perm()
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

MatrixXu Linear::argmax(MatrixXu &x)
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
        res(i, 0) = index % 10;
    }
    return res;
}

void Linear::next_batch(MatrixXu &batch, int start, vector<int> &perm, MatrixXu &data)
{
    for (int i = 0; i < B; i++)
    {
        batch.row(i) = data.row(perm[start + i]);
    }
}

void Linear::train_model()
{

    MatrixXu x_batch(B, D), y_batch(B, numClass);
    MatrixXu train_data = IOManager::train_data;
    MatrixXu train_label = IOManager::train_label;

    w.setZero();
    // static default_random_engine e(time(0));
    // static normal_distribution<double> n(0, 0.05);
    // MatrixXd m = MatrixXd::Zero(D, 1).unaryExpr([](double dummy)
    //                                                 { return n(e); });
    // for (int i = 0; i < D; i++)
    // {
    //     w(i, 0) = Constant::Util::double_to_u64(m(i, 0));
    // }
    cout << "weights initialized" << endl;

    vector<int> perm = random_perm();

    int start = 0;
    MatrixXu r0(B, D), q0(D, numClass), t0(B, numClass), r1(D, B), q1(B, numClass), t1(D, numClass);
    MatrixXu wx(B, numClass), wx_y(B, numClass);
    Constant::Clock *clock_train;
    clock_train = new Constant::Clock(2);
    // ofstream F;
    for (int j = 0; j < Ep; j++)
    {
        for (int i = 0; i < N/B; i++)
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
            wx_y = wx - y_batch;
            MatrixXu x_batch_trans = x_batch.transpose();
            MatrixXu delta;
            delta = Secret_Mul::Multiply(x_batch_trans, wx_y, r1, q1, t1);
            w = w - Secret_Mul::constant_Mul(delta, R / B);
            // F.open("Result/Linear" + to_string(party) + ".txt", ios::out);
            // F << w << endl;
            // F.close();
        }
    }
    cout << "online time:" << clock_train->get() << endl;
    test_model();
    // // inference();
    // F.open("Result/Linear" + to_string(party) + ".txt", ios::out);
    // F << "Finish" << endl
    //   << w << endl;
    // F.close();
}

void Linear::test_model()
{
    double count = 0;
    MatrixXu w_(D, numClass);
    MatrixXu test_data = IOManager::test_data;
    MatrixXu test_label = IOManager::test_label;
    if (party == 0)
    {
        w_ = Secret_Mul::Mul_reveal(w);
        MatrixXu y_ = test_data * w_;
        Mat::truncateMatrixXu(y_);
        MatrixXu res = argmax(y_);
        MatrixXu label = argmax(test_label);
        for (int i = 0; i < testN; i++)
        {
            // double yyy = Constant::Util::u64_to_double(y_(i, 0));
            // if (yyy > 0.5 && test_label(i, 0) == 1048576)
            // {
            //     count++;
            // }
            // else if (yyy < 0.5 && test_label(i, 0) == 0)
            // {
            //     count++;
            // }
            if (res(i, 0) == label(i, 0))
            {
                count++;
            }
        }
        cout << "accuracy:" << count / testN << endl;
    }
    else if (party == 2 || party == 3)
    {
        Secret_Mul::Mul_reveal(w);
    }
}

void Linear::inference()
{
    MatrixXu test_data = IOManager::test_data;
    MatrixXu test_label = IOManager::test_label;
    double count = 0;
    int it = ceil(testN / B);
    MatrixXu x_batch, y_batch, y_infer;

    MatrixXu r0(B, D), q0(D, numClass), t0(B, numClass);
    r0 = Secret_Mul::r0;
    q0 = Secret_Mul::q0;
    t0 = Secret_Mul::t0;
    for (int i = 0; i < it; i++)
    {
        int temp = min(B, testN - i * B);
        x_batch = test_data.middleRows(i * B, temp);
        y_batch = test_label.middleRows(i * B, temp);
        y_infer = Secret_Mul::Multiply(x_batch, w, r0, q0, t0);
        if (party == 0 || party == 2 || party == 3)
        {
            MatrixXu y_predict = Secret_Mul::Mul_reveal(y_infer);
            MatrixXu y_plaintext = Secret_Mul::Mul_reveal(y_batch);
            // MatrixXu res = argmax(y_predict);
            // MatrixXu label = argmax(y_plaintext);
            for (int j = 0; j < temp; j++)
            {
                double yyy = Constant::Util::u64_to_double(y_predict(j));
                if (yyy > 0.5)
                    y_predict(j) = IE;
                else
                    y_predict(j) = 0;
                count = count + (y_predict(j) == y_plaintext(j));
            }
            // if (res(i, 0) == label(i, 0))
            // {
            //     count++;
            // }
        }
    }
    if (party == 0 || party == 2 || party == 3)
    {
        cout << "accuracy of inference:" << count * 1.0 / testN << endl;
    }
}
