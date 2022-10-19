#include "nn.h"


int NN::myrandom(int i)
{
    return rand() % i;
}

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

MatrixXu relu(MatrixXu x)
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

        res(i, 0) = index % 10;
    }
    return res;
}

MatrixXu NN::forward(MatrixXu &x)
{
    int l = this->layers.size();
    MatrixXu output = x;
    for (int i = 0; i < l; i++)
    {
        output = this->layers[i]->forward(output);
    }
    return output;
}

void NN::backward(MatrixXu &delta)
{
    int l = this->layers.size();
    for (int i = l - 1; i >= 0; i--)
    {
        delta = this->layers[i]->backward(delta);
    }
}

void NN::fit(MatrixXu &x, MatrixXu &y, int epoch)
{
    vector<int> perm = random_perm();
    int start = 0;
    MatrixXu x_batch(B, D), y_batch(B, numClass);
    Constant::Clock *clock_train;
    clock_train = new Constant::Clock(2);
    for (int i = 0; i < epoch; i++)
    {
        double error = 0;
        for (int j = 0; j < N / B; j++)
        {
            next_batch(x_batch, start, perm, x);
            next_batch(y_batch, start, perm, y);
            start += B;

            MatrixXu output = this->forward(x_batch);
            MatrixXu delta = output - y_batch;
            MatrixXd temp = Mat::u642Double(Secret_Mul::Mul_reveal(delta));
            error = error + (temp.array() * temp.array()).sum();
            this->backward(delta);
        }
        cout << "square error" << endl;
        cout << error / N << endl;
        this->test_model();
    }
    cout << "online time:" << clock_train->get() << endl;
    // cout << "IT/s:" << 10/clock_train->get() << endl;
}

void NN::add_layer(Layer *layer)
{
    this->layers.push_back(layer);
}

LinearLayer::LinearLayer(int input_size, int output_size, bool first_layer)
{
    this->input_size = input_size;
    this->output_size = output_size;
    this->first_layer = first_layer;
    this->weight = MatrixXu(input_size, output_size);
    MatrixXu w = MatrixXu(input_size, output_size);
    static default_random_engine e(time(0));
    static normal_distribution<double> n(0, 0.05);
    MatrixXd m = MatrixXd::Zero(input_size, output_size).unaryExpr([](double dummy)
                                                                   { return n(e); });
    for (int i = 0; i < m.size(); i++)
        w(i) = Constant::Util::double_to_u64(m(i));
    this->weight = IOManager::secret_share(w);
    // this->weight.setZero();
}

MatrixXu LinearLayer::forward(MatrixXu &x)
{
    MatrixXu r, q, t;
    this->input = x;
    // 这里暂时只能硬编码了
    if (this->input_size == D && this->output_size == hiddenDim)
    {
        r = Secret_Mul::r2; // B * D
        q = Secret_Mul::q2; // D * hiddenDim
        t = Secret_Mul::t2; // B * hiddenDim
    }
    if (this->input_size == hiddenDim && this->output_size == hiddenDim)
    {
        r = Secret_Mul::r5; // B * hiddenDim
        q = Secret_Mul::q5; // hiddenDim * hiddenDim
        t = Secret_Mul::t5; // B * hiddenDim
    }
    if (this->input_size == hiddenDim && this->output_size == numClass)
    {
        r = Secret_Mul::r3; // B * hiddenDim
        q = Secret_Mul::q3; // hiddenDim * numClass
        t = Secret_Mul::t3; // B * numClass
    }
    if (this->input_size == D && this->output_size == numClass)
    {
        r = Secret_Mul::r0; // B * hiddenDim
        q = Secret_Mul::q0; // hiddenDim * numClass
        t = Secret_Mul::t0; // B * numClass
    }

    MatrixXu output = Secret_Mul::Multiply(x, this->weight, r, q, t);

    return output;
}

MatrixXu LinearLayer::backward(MatrixXu &delta)
{
    MatrixXu r, q, t, rr, qq, tt;
    if (this->input_size == hiddenDim && this->output_size == numClass)
    {
        r = Secret_Mul::r7;  // hiddenDim * B
        q = Secret_Mul::q7;  // B * numClass
        t = Secret_Mul::t7;  // hiddenDim * numClass
        rr = Secret_Mul::r4; // B * numClass
        qq = Secret_Mul::q4; // numClass * hiddenDim
        tt = Secret_Mul::t4; // B * hiddenDim
    }
    if (this->input_size == hiddenDim && this->output_size == hiddenDim)
    {
        r = Secret_Mul::r8;  // hiddenDim * B
        q = Secret_Mul::q8;  // B * hiddenDim
        t = Secret_Mul::t8;  // hiddenDim * hiddenDim
        rr = Secret_Mul::r5; // B * hiddenDim
        qq = Secret_Mul::q5; // hiddenDim * hiddenDim
        tt = Secret_Mul::t5; // B * hiddenDim
    }
    if (this->input_size == D && this->output_size == hiddenDim)
    {
        r = Secret_Mul::r6; // D * B
        q = Secret_Mul::q6; // B * hiddenDim
        t = Secret_Mul::t6; // D * hiddenDim
    }
    if (this->input_size == D && this->output_size == numClass)
    {
        r = Secret_Mul::r1; // D * B
        q = Secret_Mul::q1; // B * hiddenDim
        t = Secret_Mul::t1; // D * hiddenDim
    }
    MatrixXu input_trans = this->input.transpose();

    MatrixXu w_gradients = Secret_Mul::Multiply(input_trans, delta, r, q, t);
    w_gradients = Secret_Mul::constant_Mul(w_gradients, R / B);
    this->weight = this->weight - w_gradients;
    MatrixXu weight_trans = this->weight.transpose();
    if (!first_layer)
    {
        MatrixXu next_delta = Secret_Mul::Multiply(delta, weight_trans, rr, qq, tt);
        return next_delta;
    }
    else
    {
        MatrixXu temp;
        return temp;
    }
}

MatrixXu ReluLayer::forward(MatrixXu &x)
{
    MatrixXu bool_share_bit = Secret_Cmp::get_bool_share_bit(x);
    this->sign = Secret_Cmp::get_sign_xor_1(bool_share_bit);
    int row = x.rows(), col = x.cols();
    MatrixXu r(row, col), q(row, col), t(row, col);
    MatrixXu result = Secret_Mul::CwiseProduct(x, this->sign, r, q, t);
    return result;
}

MatrixXu ReluLayer::backward(MatrixXu &delta)
{
    int row = delta.rows(), col = delta.cols();
    MatrixXu r(row, col), q(row, col), t(row, col);
    MatrixXu result = Secret_Mul::CwiseProduct(delta, this->sign, r, q, t);
    return result;
}

void NN::train_model()
{
    MatrixXu train_data = IOManager::train_data;
    MatrixXu train_label = IOManager::train_label;

    MatrixXu test_data = IOManager::test_data;
    MatrixXu test_label = IOManager::test_label;

    NN net;
    Layer *linearLayer0 = new LinearLayer(D, hiddenDim, true);
    net.add_layer(linearLayer0);
    Layer *reluLayer0 = new ReluLayer();
    net.add_layer(reluLayer0);
    Layer *linearLayer1 = new LinearLayer(hiddenDim, hiddenDim);
    net.add_layer(linearLayer1);
    Layer *reluLayer1 = new ReluLayer();
    net.add_layer(reluLayer1);
    Layer *linearLayer2 = new LinearLayer(hiddenDim, numClass);
    net.add_layer(linearLayer2);
    net.fit(train_data, train_label, Ep);
    // net.inference(test_data, test_label);
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
        W_[1] = Secret_Mul::Mul_reveal(this->layers[0]->weight);
        W_[2] = Secret_Mul::Mul_reveal(this->layers[2]->weight);
        W_[3] = Secret_Mul::Mul_reveal(this->layers[4]->weight);

        for (int l = 1; l <= nLayer; l++)
        {
            Z[l] = A[l - 1] * W_[l];
            Mat::truncateMatrixXu(Z[l]);
            if (l == nLayer)
                A[l] = Z[l];
            else
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
    else if (party == 1 || party == 2)
    {
        W_[1] = Secret_Mul::Mul_reveal(this->layers[0]->weight);
        W_[2] = Secret_Mul::Mul_reveal(this->layers[2]->weight);
        W_[3] = Secret_Mul::Mul_reveal(this->layers[4]->weight);
        // W_[4] = Secret_Mul::Mul_reveal(this->layers[6]->weight);
    }
}

void NN::inference(MatrixXu &x, MatrixXu &y)
{
    int l = y.rows();
    int batch_len = ceil(l / B);
    MatrixXu x_batch, y_batch, y_batch_plaintext;
    int count = 0;

    for (int j = 0; j < batch_len; j++)
    {
        int temp = min(B, l - j * B);
        x_batch = x.middleRows(j * B, temp);
        y_batch = y.middleRows(j * B, temp);
        MatrixXu predict = this->forward(x_batch);
        predict = Secret_Mul::Mul_reveal(predict);
        y_batch_plaintext = Secret_Mul::Mul_reveal(y_batch);
        MatrixXu res = argmax(predict);
        MatrixXu label = argmax(y_batch_plaintext);
        for (int i = 0; i < temp; i++)
        {
            // if (predict(i) > IE / 2)
            //     predict(i) = IE;
            // else
            //     predict(i) = 0;
            // count = count + (predict(i) == y_batch_plaintext(i));
            if (res(i, 0) == label(i, 0))
            {
                count++;
            }
        }
    }
    cout << "accuracy of inference:" << count * 1.0 / l << endl;
}