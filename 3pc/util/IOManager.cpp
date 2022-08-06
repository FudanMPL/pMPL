
#include "IOManager.h"

MatrixXu IOManager::train_data = MatrixXu(N, D);
MatrixXu IOManager::train_label = MatrixXu(N, numClass);
MatrixXu IOManager::test_data = MatrixXu(testN, D);
MatrixXu IOManager::test_label = MatrixXu(testN, numClass);

void IOManager::load_data(ifstream &in, MatrixXu &data, MatrixXu &label, int size)
{
    int i = 0;
    while (in)
    {

        string s;
        if (!getline(in, s))
            break;
        char *ch;
        ch = const_cast<char *>(s.c_str());
        int temp;
        // char c;
        temp = Constant::Util::getint(ch);
        // two class for mnist and fashion_mnist
        // if (temp > 1)
        //     temp = 1;

        // two class for svhn
        // if (temp == 10)
        //     temp = 0;
        // else
        //     temp = 1;

        // label(i, 0) = temp * IE;

        // one_hot for svhn
        // if (temp == 10)
        //     label(i, 0) = IE;
        // else
        //     label(i, temp) = IE;

        // one_hot for mnist and fashion_mnist
        label(i, temp) = IE;
        for (int j = 0; j < D; j++)
        {
            temp = Constant::Util::getint(ch);
            data(i, j) = temp * IE / 256;
        }

        i++;
        if (i >= size)
            break;
    }
    cout << label(0, 0) << endl;
    //    cout<<"n= "<<i<<endl;
    // for (i; i < size + B - 1; i++)
    // {
    //     int tmp_r;
    //     tmp_r = data.cols();
    //     for (int j = 0; j < tmp_r; j++)
    //     {
    //         data(i, j) = data(i - size, j);
    //     }
    //     tmp_r = label.cols();
    //     for (int j = 0; j < tmp_r; j++)
    //     {
    //         label(i, j) = label(i - size, j);
    //     }
    // }
    DBGprint("n=%d\n", i);
}

void IOManager::secret_share(MatrixXu &data, MatrixXu &label, string category)
{
    MatrixXu A_plus_mat = Mat::toMatrix(Mat::A_plus);
    vector<ofstream> out_files(M);
    for (int i = 0; i < M; ++i)
    {
        out_files[i].open("data/mnist_" + category + "_" + to_string(i) + ".csv", ios::out);
    }
    srand(time(NULL));

    int r = data.rows();
    int c = data.cols();
    vector<MatrixXu> out_Matrix(M);
    for (int i = 0; i < M; ++i)
    {
        out_Matrix[i].resize(r, c + numClass);
    }
    MatrixXu temp_vec(3, 1);
    cout << r << " : " << c << endl;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < numClass; j++)
        {
            temp_vec << label(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            for (int k = 0; k < M; k++)
            {
                MatrixXu temp = A_plus_mat.row(k) * temp_vec;
                out_Matrix[k](i, j) = temp(0, 0);
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            temp_vec << data(i, j), Constant::Util::random_u64(), Constant::Util::random_u64();
            for (int k = 0; k < M; k++)
            {
                MatrixXu temp = A_plus_mat.row(k) * temp_vec;
                out_Matrix[k](i, j + numClass) = temp(0, 0);
            }
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c + numClass; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                if (j == (c + numClass - 1))
                {
                    out_files[k] << out_Matrix[k](i, j) << "\n";
                }
                else
                {
                    out_files[k] << out_Matrix[k](i, j) << ",";
                }
            }
        }
    }
    for (int k = 0; k < M; ++k)
    {
        out_files[k].close();
    }
}
void IOManager::load_ss(ifstream &in, MatrixXu &data, MatrixXu &label, int size)
{
    int i = 0;
    while (in)
    {
        string s;
        if (!getline(in, s))
            break;
        char *ch;
        ch = const_cast<char *>(s.c_str());
        u64 temp;
        char c;

        for (int j = 0; j < numClass; j++)
        {
            temp = Constant::Util::getu64(ch);
            label(i, j) = temp;
        }

        for (int j = 0; j < D; j++)
        {
            temp = Constant::Util::getu64(ch);
            data(i, j) = temp;
        }
        i++;
        if (i >= size)
            break;
    }
    DBGprint("n=%d\n", i);
}

void IOManager::init()
{
    DBGprint("load training data......\n");

    // ifstream infile("data/mnist_train.csv");
    // load_data(infile, train_data, train_label, N);
    // secret_share(train_data, train_label, "train");

    ifstream infile("data/mnist_train_" + to_string(party) + ".csv");
    load_ss(infile, train_data, train_label, N);
    infile.close();

    ifstream intest("data/mnist_test.csv");
    load_data(intest, test_data, test_label, testN);
    // secret_share(test_data, test_label, "test");

    // ifstream intest("data/mnist_test_" + to_string(party) + ".csv");
    // load_ss(intest, test_data, test_label, testN);
    intest.close();

    // TODO: secret sharing save file

    //    train_data.reoeder();
    //    train_label.reoeder();
    //    test_data.reoeder();
    //    test_label.reoeder();
}