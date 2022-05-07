#include "nn.h"

// Matrixint64 NN::w = Matrixint64(D, 1);
vector<Matrixint64> W(static_cast<long>(nLayer + 1));
Matrixint64 NN::y_inf = Matrixint64(testN, 1);

// vector<int> read_VT(Matrixint64 &a, Matrixint64 &b_1, Matrixint64 &c_1, Matrixint64 &b_2, Matrixint64 &c_2, int party)
// {

// }

static MatrixXd int642Double(const Matrixint64 &a)
{
    Matrixint64 temp(a.rows(), a.cols());
    MatrixXd res(a.rows(), a.cols());
    int l = a.rows() * a.cols();
    for (int i = 0; i < l; i++)
    {
        temp(i) = (int64)a(i);
    }
    for (int i = 0; i < l; i++)
    {
        res(i) = temp(i) * 1.0 / IE;
    }
    return res;
}

static Matrixint64 secret_share(Matrixint64 &truth)
{
    int row = truth.rows(), col = truth.cols();
    Matrixint64 A_plus_mat = Mat::toMatrix(Mat::A_plus);
    Matrixint64 share(row, col), temp(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            Matrixint64 temp_vector(3, 1);
            temp_vector << truth(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            Matrixint64 temp1 = A_plus_mat.row(party) * temp_vector;
            temp(i, j) = temp1(0, 0);
        }
    }
    share = temp;
    return share;
}

int NN::myrandom(int i) { return rand() % i; }

vector<int> NN::random_perm()
{
    vector<int> temp, perm;
    for (int i = 0; i < N; i++)
        temp.push_back(i);

    for (int i = 0; i < Ep; i++)
    {                                                       // construct the random shuffled indices of every epoch
        random_shuffle(temp.begin(), temp.end(), myrandom); // random permutations of indices between 0 to N-1
        perm.insert(perm.end(), temp.begin(), temp.end());  // append the random permutated indicies
    }
    return perm;
}

void NN::next_batch(Matrixint64 &batch, int start, vector<int> &perm, Matrixint64 &data)
{
    for (int i = 0; i < B; i++)
    {
        batch.row(i) = data.row(perm[start + i]);
    }
}

Matrixint64 relu(Matrixint64 x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x(i) >= 0)
            x(i) = x(i);
        else
            x(i) = 0;
    }
    return x;
}

void NN::train_model()
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

    vector<int> perm = random_perm();

    int start = 0;

    // vector<Matrixint64> W(static_cast<unsigned long>(nLayer + 1));
    Matrixint64 w0(D, hiddenDim), w1(hiddenDim, hiddenDim), w2(hiddenDim, 1);
    Matrixint64 w(D, 1);

    static default_random_engine e(time(0));
    static normal_distribution<double> n(0, 0.05);
    MatrixXd m0 = MatrixXd::Zero(D, hiddenDim).unaryExpr([](double dummy)
                                                         { return n(e); });
    for (int i = 0; i < w0.size(); i++)
    {
        w0(i) = Constant::Util::double_to_int64(m0(i));
    }

    MatrixXd m1 = MatrixXd::Zero(hiddenDim, hiddenDim).unaryExpr([](double dummy)
                                                                 { return n(e); });
    for (int i = 0; i < w1.size(); i++)
    {
        w1(i) = Constant::Util::double_to_int64(m1(i));
    }

    MatrixXd m2 = MatrixXd::Zero(hiddenDim, 1).unaryExpr([](double dummy)
                                                         { return n(e); });
    for (int i = 0; i < w2.size(); i++)
    {
        w2(i) = Constant::Util::double_to_int64(m2(i));
    }

    MatrixXd m = MatrixXd::Zero(D, 1).unaryExpr([](double dummy)
                                                { return n(e); });
    for (int i = 0; i < w.size(); i++)
    {
        w(i) = Constant::Util::double_to_int64(m(i));
    }

    // W[1] = w0;
    // W[2] = w1;
    // W[3] = w2;

    W[1] = secret_share(w0);
    W[2] = secret_share(w1);
    W[3] = secret_share(w2);

    cout << "weights initialized" << endl;

    Matrixint64 result;

    Matrixint64 r00(B, D), q00(D, 1), t00(B, 1);
    r00 = Secret_Mul::r0;
    q00 = Secret_Mul::q0;
    t00 = Secret_Mul::t0;

    Matrixint64 r11(D, B), q11(B, 1), t11(D, 1);
    r11 = Secret_Mul::r1;
    q11 = Secret_Mul::q1;
    t11 = Secret_Mul::t1;

    // 128*784 784*128 -> 128*128
    Matrixint64 r0(B, D), q0(D, hiddenDim), t0(B, hiddenDim);
    r0 = Secret_Mul::r2;
    q0 = Secret_Mul::q2;
    t0 = Secret_Mul::t2;
    // 128*128 128*1 -> 128*1
    Matrixint64 r1(B, hiddenDim), q1(hiddenDim, 1), t1(B, 1);
    r1 = Secret_Mul::r3;
    q1 = Secret_Mul::q3;
    t1 = Secret_Mul::t3;
    // 128*1 1*128 -> 128*128
    Matrixint64 r2(B, 1), q2(1, hiddenDim), t2(B, hiddenDim);
    r2 = Secret_Mul::r4;
    q2 = Secret_Mul::q4;
    t2 = Secret_Mul::t4;

    // 128*128 128*128 -> 128*128
    Matrixint64 r3(B, hiddenDim), q3(hiddenDim, hiddenDim), t3(B, hiddenDim);
    r3 = Secret_Mul::r5;
    q3 = Secret_Mul::q5;
    t3 = Secret_Mul::t5;

    // 128*128 128*1 -> 128*1
    Matrixint64 r4(hiddenDim, B), q4(B, 1), t4(hiddenDim, 1);
    r4 = Secret_Mul::r3;
    q4 = Secret_Mul::q3;
    t4 = Secret_Mul::t3;

    // 784*128 128*128 ->784*128
    Matrixint64 r5(D, B), q5(B, hiddenDim), t5(D, hiddenDim);
    r5 = Secret_Mul::r6;
    q5 = Secret_Mul::q6;
    t5 = Secret_Mul::t6;

    // 128*128 128*128
    Matrixint64 r6(hiddenDim, B), q6(B, hiddenDim), t6(hiddenDim, hiddenDim);
    r6 = Secret_Mul::r5;
    q6 = Secret_Mul::q5;
    t6 = Secret_Mul::t5;

    // 128*1 128*1 ->128*1
    Matrixint64 r7(B, 1), q7(B, 1), t7(B, 1);
    r7.setZero();
    q7.setZero();
    t7.setZero();
    // 128*128
    Matrixint64 r8(B, hiddenDim), q8(B, hiddenDim), t8(B, hiddenDim);
    r8.setZero();
    q8.setZero();
    t8.setZero();

    Constant::Clock *clock_train;
    clock_train = new Constant::Clock(2);
    for (int i = 0; i < Ep; i++)
    {
        double error2 = 0;
        for (int j = 0; j < N / B; j++)
        {
            // cout << "第" << i << "个batch" << endl;
            // cout << __LINE__ <<endl;

            next_batch(x_batch, start, perm, train_data);
            next_batch(y_batch, start, perm, train_label); //选出mini batch

            start += B;

            vector<Matrixint64> A(static_cast<long>(nLayer + 1));
            vector<Matrixint64> Z(static_cast<long>(nLayer + 1));
            vector<Matrixint64> E(static_cast<long>(nLayer + 1));
            vector<Matrixint64> delta(static_cast<long>(nLayer + 1));
            vector<Matrixint64> U(static_cast<long>(nLayer + 1));

            // ------------forward phase---------------
            // two hidden layer
            A[0] = x_batch;
            Z[1] = Secret_Mul::Multiply_nn(A[0], W[1], r0, q0, t0); // 128*784  784*128
            A[1] = Secret_Cmp::Relu(Z[1]);

            Z[2] = Secret_Mul::Multiply_nn(A[1], W[2], r3, q3, t3); // 128*128  128*128
            A[2] = Secret_Cmp::Relu(Z[2]);

            Z[3] = Secret_Mul::Multiply_nn(A[2], W[3], r1, q1, t1); /// 128*128  128*1
            A[3] = Secret_Cmp::Relu(Z[3]);

            // ------------backward phase---------------
            // cout << "backward" <<endl;
            Matrixint64 w_trans, a_trans, z_drelu, error;
            error = (A[nLayer] - y_batch);
            if (party == 0 || party == 2 || party == 3)
            {
                MatrixXd temp = int642Double(Secret_Mul::reveal(error));
                error2 = error2 + (temp.array() * temp.array()).sum();
            }
            // relu
            z_drelu = Secret_Cmp::get_sign_xor_1(Z[3]);                  // 128*1
            E[3] = Secret_Mul::CwiseProduct(error, z_drelu, r7, q7, t7); // 128*1  128*1 ->128*1
            // linear
            w_trans = W[3].transpose();                             // 1*128
            E[2] = Secret_Mul::Multiply_nn(E[3], w_trans, r2, q2, t2); // 128*1 1*128  -> 128*128
            a_trans = A[2].transpose();                             // 128*128
            U[3] = Secret_Mul::Multiply_nn(a_trans, E[3], r4, q4, t4); // 128*128 128*1 -> 128*1
            W[3] = W[3] - Mat::constant_multiply(U[3], 0.01 / B); // 128*1

            // relu
            z_drelu = Secret_Cmp::get_sign_xor_1(Z[2]);                 // 128*1
            E[2] = Secret_Mul::CwiseProduct(E[2], z_drelu, r8, q8, t8); // 128*128

            // linear
            w_trans = W[2].transpose();                             // 128*128
            E[1] = Secret_Mul::Multiply_nn(E[2], w_trans, r6, q6, t6); // 128*128  128*128 ->128*128

            a_trans = A[1].transpose();                             // 128*128
            U[2] = Secret_Mul::Multiply_nn(a_trans, E[2], r6, q6, t6); // 128*128  128*128 ->128*128
            W[2] = W[2] - Mat::constant_multiply(U[2], 0.01 / B); // 128*128
            // relu
            z_drelu = Secret_Cmp::get_sign_xor_1(Z[1]);                 // 128*128
            E[1] = Secret_Mul::CwiseProduct(E[1], z_drelu, r8, q8, t8); // 128*128

            a_trans = A[0].transpose();                             // 784*128
            U[1] = Secret_Mul::Multiply_nn(a_trans, E[1], r5, q5, t5); // 784*128 128*128 ->784*128
            W[1] = W[1] - Mat::constant_multiply(U[1], 0.01 / B);
        }
        if (party == 0 || party == 2 || party == 3)
        {
            cout << "square error" << endl;
            cout << error2 / N << endl;
        }
    }
    cout << "online time:" << clock_train->get() << endl;
    inference();
    // test_model();
}

void NN::test_model()
{
    double count = 0;
    Matrixint64 test_data = IOManager::test_data;
    Matrixint64 test_label = IOManager::test_label;

    vector<Matrixint64> W_(static_cast<unsigned long>(nLayer + 1));
    vector<Matrixint64> A(static_cast<unsigned long>(nLayer + 1));
    vector<Matrixint64> Z(static_cast<unsigned long>(nLayer + 1));
    A[0] = test_data;
    Matrixint64 result;

    if (party == 0)
    {
        W_[1] = Secret_Mul::reveal(W[1]);
        W_[2] = Secret_Mul::reveal(W[2]);
        W_[3] = Secret_Mul::reveal(W[3]);
        for (int l = 1; l <= nLayer; l++)
        {
            Z[l] = A[l - 1] * W_[l];
            Mat::truncateMatrixint64(Z[l]);
            A[l] = relu(Z[l]);
        }
        result = A[nLayer];
        for (int i = 0; i < testN; i++)
        {
            double resulttt = Constant::Util::int64_to_double(result(i, 0));
            if (resulttt > 0.5 && test_label(i, 0) == 1048576)
                count++;
            else if (resulttt < 0.5 && test_label(i, 0) == 0)
                count++;
        }
        cout << "accuracy:" << count / testN << endl;
    }
    else if (party == 2 || party == 3)
    {
        Secret_Mul::reveal(W[1]);
        Secret_Mul::reveal(W[2]);
        Secret_Mul::reveal(W[3]);
    }
}

void NN::inference()
{
    Matrixint64 test_data = IOManager::test_data;
    Matrixint64 test_label = IOManager::test_label;

    Matrixint64 wx;
    double count = 0;
    int it = ceil(testN / B);
    Matrixint64 x_batch, y_batch, y_infer;

    Matrixint64 r0(B, D), q0(D, 1), t0(B, 1);
    r0 = Secret_Mul::r2;
    q0 = Secret_Mul::q2;
    t0 = Secret_Mul::t2;
    Matrixint64 r1(B, hiddenDim), q1(hiddenDim, 1), t1(B, 1);
    r1 = Secret_Mul::r3;
    q1 = Secret_Mul::q3;
    t1 = Secret_Mul::t3;

    Matrixint64 r3(B, hiddenDim), q3(hiddenDim, hiddenDim), t3(B, hiddenDim);
    r3 = Secret_Mul::r5;
    q3 = Secret_Mul::q5;
    t3 = Secret_Mul::t5;

    for (int i = 0; i < it; i++)
    {
        int temp = min(B, testN - i * B);
        x_batch = test_data.middleRows(i * B, temp);
        y_batch = test_label.middleRows(i * B, temp);
        vector<Matrixint64> A(static_cast<unsigned long>(nLayer + 1));
        vector<Matrixint64> Z(static_cast<unsigned long>(nLayer + 1));

        A[0] = x_batch;
        Z[1] = Secret_Mul::Multiply_nn(A[0], W[1], r0, q0, t0); // 128*784  784*128
        A[1] = Secret_Cmp::Relu(Z[1]);

        Z[2] = Secret_Mul::Multiply_nn(A[1], W[2], r3, q3, t3); // 128*128  128*128
        A[2] = Secret_Cmp::Relu(Z[2]);

        Z[3] = Secret_Mul::Multiply_nn(A[2], W[3], r1, q1, t1); /// 128*128  128*1
        A[3] = Secret_Cmp::Relu(Z[3]);
        if (party == 0 || party == 2 || party == 3)
        {
            Matrixint64 y_predict = Secret_Mul::reveal(A[3]);
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