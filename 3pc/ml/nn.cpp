#include "nn.h"

// MatrixXu NN::w = MatrixXu(D, 1);
vector<MatrixXu> W(static_cast<long>(nLayer + 1));
MatrixXu NN::y_inf = MatrixXu(testN, numClass);

// vector<int> read_VT(MatrixXu &a, MatrixXu &b_1, MatrixXu &c_1, MatrixXu &b_2, MatrixXu &c_2, int party)
// {

// }

MatrixXd u642Double(const MatrixXu &a)
{
    MatrixXu temp(a.rows(), a.cols());
    MatrixXd res(a.rows(), a.cols());
    int l = a.rows() * a.cols();
    for (int i = 0; i < l; i++)
    {
        temp(i) = (u64)a(i);
    }
    for (int i = 0; i < l; i++)
    {
        res(i) = (long)temp(i) / (double)IE;
    }
    return res;
}

static MatrixXu secret_share(MatrixXu &truth)
{
    int row = truth.rows(), col = truth.cols();
    MatrixXu A_plus_mat = Mat::toMatrix(Mat::A_plus);
    MatrixXu share(row, col), temp(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            MatrixXu temp_vector(3, 1);
            temp_vector << truth(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            MatrixXu temp1 = A_plus_mat.row(party) * temp_vector;
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

void NN::next_batch(MatrixXu &batch, int start, vector<int> &perm, MatrixXu &data)
{
    for (int i = 0; i < B; i++)
    {
        batch.row(i) = data.row(perm[start + i]);
    }
}

MatrixXu relu(MatrixXu &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x(i) >= 0 && x(i) <= 9223372036854775808)
            x(i) = x(i);
        else
            x(i) = 0;
    }
    return x;
}

MatrixXu NN::argmax(MatrixXu &x)
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
        //  res(i, 0) = index % 10;

        // mnist and fashion_mnist
        res(i, 0) = index;
    }
    return res;
}

void NN::train_model()
{

    MatrixXu x_batch(B, D), y_batch(B, numClass);
    MatrixXu train_data = IOManager::train_data;
    MatrixXu train_label = IOManager::train_label;

    // static default_random_engine e(time(0));
    // static normal_distribution<double> n(0, 0.05);
    // MatrixXd m = MatrixXd::Zero(D, 1).unaryExpr([](double dummy)
    //                                                 { return n(e); });
    // for (int i = 0; i < D; i++)
    // {
    //     w(i, 0) = Constant::Util::double_to_u64(m(i, 0));
    // }

    vector<int> perm = random_perm();

    int start = 0;

    // vector<MatrixXu> W(static_cast<unsigned long>(nLayer + 1));
    MatrixXu w0(D, hiddenDim), w1(hiddenDim, hiddenDim), w2(hiddenDim, numClass);
    MatrixXu w(D, numClass);

    static default_random_engine e(time(0));
    static normal_distribution<double> n(0, 0.05);
    MatrixXd m0 = MatrixXd::Zero(D, hiddenDim).unaryExpr([](double dummy)
                                                         { return n(e); });
    for (int i = 0; i < w0.size(); i++)
    {
        w0(i) = Constant::Util::double_to_u64(m0(i));
    }

    MatrixXd m1 = MatrixXd::Zero(hiddenDim, hiddenDim).unaryExpr([](double dummy)
                                                                 { return n(e); });
    for (int i = 0; i < w1.size(); i++)
    {
        w1(i) = Constant::Util::double_to_u64(m1(i));
    }

    MatrixXd m2 = MatrixXd::Zero(hiddenDim, numClass).unaryExpr([](double dummy)
                                                                { return n(e); });
    for (int i = 0; i < w2.size(); i++)
    {
        w2(i) = Constant::Util::double_to_u64(m2(i));
    }

    MatrixXd m = MatrixXd::Zero(D, numClass).unaryExpr([](double dummy)
                                                       { return n(e); });
    for (int i = 0; i < w.size(); i++)
    {
        w(i) = Constant::Util::double_to_u64(m(i));
    }

    // W[1] = w0;
    // W[2] = w1;
    // W[3] = w2;

    W[1] = secret_share(w0);
    W[2] = secret_share(w1);
    W[3] = secret_share(w2);

    cout << "weights initialized" << endl;

    MatrixXu result;

    MatrixXu r00(B, D), q00(D, numClass), t00(B, numClass);
    r00 = Secret_Mul::r0;
    q00 = Secret_Mul::q0;
    t00 = Secret_Mul::t0;

    MatrixXu r11(D, B), q11(B, numClass), t11(D, numClass);
    r11 = Secret_Mul::r1;
    q11 = Secret_Mul::q1;
    t11 = Secret_Mul::t1;

    // 128*784 784*128 -> 128*128
    MatrixXu r0(B, D), q0(D, hiddenDim), t0(B, hiddenDim);
    r0 = Secret_Mul::r2;
    q0 = Secret_Mul::q2;
    t0 = Secret_Mul::t2;
    // 128*128 128*numClass -> 128*numClass
    MatrixXu r1(B, hiddenDim), q1(hiddenDim, numClass), t1(B, numClass);
    r1 = Secret_Mul::r3;
    q1 = Secret_Mul::q3;
    t1 = Secret_Mul::t3;
    // 128*numClass numClass*128 -> 128*128
    MatrixXu r2(B, numClass), q2(numClass, hiddenDim), t2(B, hiddenDim);
    r2 = Secret_Mul::r4;
    q2 = Secret_Mul::q4;
    t2 = Secret_Mul::t4;

    // 128*128 128*128 -> 128*128
    MatrixXu r3(B, hiddenDim), q3(hiddenDim, hiddenDim), t3(B, hiddenDim);
    r3 = Secret_Mul::r5;
    q3 = Secret_Mul::q5;
    t3 = Secret_Mul::t5;

    // 128*128 128*numClass -> 128*numClass
    MatrixXu r4(hiddenDim, B), q4(B, numClass), t4(hiddenDim, numClass);
    r4 = Secret_Mul::r7;
    q4 = Secret_Mul::q7;
    t4 = Secret_Mul::t7;

    // 784*128 128*128 ->784*128
    MatrixXu r5(D, B), q5(B, hiddenDim), t5(D, hiddenDim);
    r5 = Secret_Mul::r6;
    q5 = Secret_Mul::q6;
    t5 = Secret_Mul::t6;

    // 128*128 128*128
    MatrixXu r6(hiddenDim, B), q6(B, hiddenDim), t6(hiddenDim, hiddenDim);
    r6 = Secret_Mul::r8;
    q6 = Secret_Mul::q8;
    t6 = Secret_Mul::t8;

    // 128*1 128*1 ->128*1
    MatrixXu r7(B, numClass), q7(B, numClass), t7(B, numClass);
    r7.setZero();
    q7.setZero();
    t7.setZero();
    // 128*128
    MatrixXu r8(B, hiddenDim), q8(B, hiddenDim), t8(B, hiddenDim);
    r8.setZero();
    q8.setZero();
    t8.setZero();

    Constant::Clock *clock_train;
    clock_train = new Constant::Clock(2);
    // for (int i = 0; i < Ep; i++)
    // {
        // double error2 = 0;
        for (int j = 0; j < 10; j++)
        {
            // cout << "第" << i << "个batch" << endl;
            // cout << __LINE__ <<endl;

            next_batch(x_batch, start, perm, train_data);
            next_batch(y_batch, start, perm, train_label); //选出mini batch

            start += B;

            vector<MatrixXu> A(static_cast<long>(nLayer + 1));
            vector<MatrixXu> Z(static_cast<long>(nLayer + 1));
            vector<MatrixXu> E(static_cast<long>(nLayer + 1));
            vector<MatrixXu> delta(static_cast<long>(nLayer + 1));
            vector<MatrixXu> U(static_cast<long>(nLayer + 1));

            // ------------forward phase---------------
            // two hidden layer

            A[0] = x_batch;
            Z[1] = Secret_Mul::Multiply(A[0], W[1], r0, q0, t0); // 128*784  784*128  B*D D*H -> B*H
            A[1] = Secret_Cmp::Relu(Z[1]);

            Z[2] = Secret_Mul::Multiply(A[1], W[2], r3, q3, t3); // 128*128  128*128 B*H H*H -> B*H
            A[2] = Secret_Cmp::Relu(Z[2]);

            Z[3] = Secret_Mul::Multiply(A[2], W[3], r1, q1, t1); /// 128*128  128*numClass B*H H*numClass-> B*numClass
            // A[3] = Secret_Cmp::Relu(Z[3]);
            A[3] = Z[3];

            // ------------backward phase---------------
            // cout << "backward" <<endl;
            MatrixXu w_trans, a_trans, z_drelu, error;
            error = (A[nLayer] - y_batch);
            // MatrixXd temp = Mat::u642Double(Secret_Mul::Mul_reveal(error));
            // error2 = error2 + (temp.array() * temp.array()).sum();
            // relu
            // z_drelu = Secret_Cmp::get_sign_xor_1(Z[3]);                  // 128*numClass
            // E[3] = Secret_Mul::CwiseProduct(error, z_drelu, r7, q7, t7); // 128*numClass  128*numClass ->128*numClass  B*numClass

            // linear
            w_trans = W[3].transpose();                             // numClass*128   numClass*H
            E[2] = Secret_Mul::Multiply(error, w_trans, r2, q2, t2); // 128*numClass numClass*128  -> 128*128 B*numClass numClass*H ->B*H
            a_trans = A[2].transpose();                             // 128*128 H*B
            U[3] = Secret_Mul::Multiply(a_trans, error, r4, q4, t4); // 128*128 128*numClass -> 128*numClass H*B B*numClass->H*numClass
            W[3] = W[3] - Secret_Mul::constant_Mul(U[3], 0.005 / B); // 128*numClass

            // relu
            z_drelu = Secret_Cmp::get_sign_xor_1(Z[2]);                 // 128*128
            E[2] = Secret_Mul::CwiseProduct(E[2], z_drelu, r8, q8, t8); // 128*128 B*H

            // linear
            w_trans = W[2].transpose();                             // 128*128 H*H
            E[1] = Secret_Mul::Multiply(E[2], w_trans, r3, q3, t3); // 128*128  128*128 ->128*128 B*H H*H-> B*H
            a_trans = A[1].transpose();                             // 128*128 H*B
            U[2] = Secret_Mul::Multiply(a_trans, E[2], r6, q6, t6); // 128*128  128*128 ->128*128 H*B B*H -> H*H
            W[2] = W[2] - Secret_Mul::constant_Mul(U[2], 0.005 / B); // 128*128

            // relu
            z_drelu = Secret_Cmp::get_sign_xor_1(Z[1]);                 // 128*128 B*H
            E[1] = Secret_Mul::CwiseProduct(E[1], z_drelu, r8, q8, t8); // 128*128 B*H

            a_trans = A[0].transpose();                             // 784*128 D*B
            U[1] = Secret_Mul::Multiply(a_trans, E[1], r5, q5, t5); // 784*128 128*128 ->784*128 D*B B*H-> D*H
            W[1] = W[1] - Secret_Mul::constant_Mul(U[1], 0.005 / B);
        }
        // if (party == 0 || party == 2 || party == 3)
        // {
        //     cout << "square error" << endl;
        //     cout << error2 / N << endl;
        // }
        // test_model();
    // }
    cout << "online time:" << clock_train->get() << endl;
    cout << "it/s:" << 10 / clock_train->get() << endl;
    // inference();
    // test_model();
}

void NN::test_model()
{
    double count = 0;
    MatrixXu test_data = IOManager::test_data;
    MatrixXu test_label = IOManager::test_label;

    vector<MatrixXu> W_(static_cast<unsigned long>(nLayer + 1));
    vector<MatrixXu> A(static_cast<unsigned long>(nLayer + 1));
    vector<MatrixXu> Z(static_cast<unsigned long>(nLayer + 1));
    A[0] = test_data;
    MatrixXu result;

    if (party == 0)
    {
        W_[1] = Secret_Mul::Mul_reveal(W[1]);
        W_[2] = Secret_Mul::Mul_reveal(W[2]);
        W_[3] = Secret_Mul::Mul_reveal(W[3]);
        for (int l = 1; l <= nLayer; l++)
        {
            Z[l] = A[l - 1] * W_[l];
            Mat::truncateMatrixXu(Z[l]);
            A[l] = relu(Z[l]);
        }
        result = A[nLayer];
        MatrixXu res = argmax(result);
        MatrixXu label = argmax(test_label);
        for (int i = 0; i < testN; i++)
        {
            // double resulttt = Constant::Util::u64_to_double(result(i, 0));
            // if (resulttt > 0.5 && test_label(i, 0) == 1048576)
            //     count++;
            // else if (resulttt < 0.5 && test_label(i, 0) == 0)
            //     count++;
            if (res(i, 0) == label(i, 0))
            {
                count++;
            }
        }
        cout << "accuracy:" << count / testN << endl;
    }
    else if (party == 2 || party == 3)
    {
        Secret_Mul::Mul_reveal(W[1]);
        Secret_Mul::Mul_reveal(W[2]);
        Secret_Mul::Mul_reveal(W[3]);
    }
}

void NN::inference()
{
    MatrixXu test_data = IOManager::test_data;
    MatrixXu test_label = IOManager::test_label;

    MatrixXu wx;
    double count = 0;
    int it = ceil(testN / B);
    MatrixXu x_batch, y_batch, y_infer;

    MatrixXu r0(B, D), q0(D, numClass), t0(B, numClass);
    r0 = Secret_Mul::r2;
    q0 = Secret_Mul::q2;
    t0 = Secret_Mul::t2;
    MatrixXu r1(B, hiddenDim), q1(hiddenDim, numClass), t1(B, numClass);
    r1 = Secret_Mul::r3;
    q1 = Secret_Mul::q3;
    t1 = Secret_Mul::t3;

    MatrixXu r3(B, hiddenDim), q3(hiddenDim, hiddenDim), t3(B, hiddenDim);
    r3 = Secret_Mul::r5;
    q3 = Secret_Mul::q5;
    t3 = Secret_Mul::t5;

    for (int i = 0; i < it; i++)
    {
        int temp = min(B, testN - i * B);
        x_batch = test_data.middleRows(i * B, temp);
        y_batch = test_label.middleRows(i * B, temp);
        vector<MatrixXu> A(static_cast<unsigned long>(nLayer + 1));
        vector<MatrixXu> Z(static_cast<unsigned long>(nLayer + 1));

        A[0] = x_batch;
        Z[1] = Secret_Mul::Multiply(A[0], W[1], r0, q0, t0); // 128*784  784*128
        A[1] = Secret_Cmp::Relu(Z[1]);

        Z[2] = Secret_Mul::Multiply(A[1], W[2], r3, q3, t3); // 128*128  128*128
        A[2] = Secret_Cmp::Relu(Z[2]);

        Z[3] = Secret_Mul::Multiply(A[2], W[3], r1, q1, t1); /// 128*128  128*1
        A[3] = Secret_Cmp::Relu(Z[3]);
        if (party == 0 || party == 2 || party == 3)
        {
            MatrixXu y_predict = Secret_Mul::Mul_reveal(A[3]);
            MatrixXu y_plaintext = Secret_Mul::Mul_reveal(y_batch);
            MatrixXu res = argmax(y_predict);
            MatrixXu label = argmax(y_plaintext);
            for (int j = 0; j < temp; j++)
            {
                // double yyy = Constant::Util::u64_to_double(y_predict(j));
                // if (yyy > 0.5)
                //     y_predict(j) = IE;
                // else
                //     y_predict(j) = 0;
                // count = count + (y_predict(j) == y_plaintext(j));
                if (res(i, 0) == label(i, 0))
                {
                    count++;
                }
            }
        }
    }
    if (party == 0 || party == 2 || party == 3)
    {
        cout << "accuracy of inference:" << count * 1.0 / testN << endl;
    }
}