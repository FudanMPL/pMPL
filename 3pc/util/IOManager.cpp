
#include "IOManager.h"

Matrixint64 IOManager::train_data = Matrixint64(N, D);
Matrixint64 IOManager::train_label = Matrixint64(N, 1);
Matrixint64 IOManager::test_data = Matrixint64(testN, D);
Matrixint64 IOManager::test_label = Matrixint64(testN, 1);

void IOManager::load_data(ifstream &in, Matrixint64 &data, Matrixint64 &label, int size)
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
        if (temp > 1)
            temp = 1;
        // else
        //     temp = 0;
        label(i, 0) = temp * IE;

        // data(i, D) = IE;
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

void IOManager::secret_share(Matrixint64 &data, Matrixint64 &label, string category)
{
    Matrixint64 A_plus_mat = Mat::toMatrix(Mat::A_plus);
    vector<ofstream> out_files(M);
    for (int i = 0; i < M; ++i)
    {
        out_files[i].open("data/mnist_" + category + "_" + to_string(i) + ".csv", ios::out);
    }
    srand(time(NULL));

    int r = data.rows();
    int c = data.cols();
    vector<Matrixint64> out_Matrix(M);
    for (int i = 0; i < M; ++i)
    {
        out_Matrix[i].resize(r, c + 1);
    }
    Matrixint64 temp_vec(3, 1);
    cout << r << " : " << c << endl;
    for (int i = 0; i < r; ++i)
    {
        temp_vec << label(i, 0), Constant::Util::random_int64(), Constant::Util::random_int64();
        for (int k = 0; k < M; k++)
        {
            Matrixint64 temp = A_plus_mat.row(k) * temp_vec;
            out_Matrix[k](i, 0) = temp(0, 0);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            temp_vec << data(i, j), Constant::Util::random_int64(), Constant::Util::random_int64();
            for (int k = 0; k < M; k++)
            {
                Matrixint64 temp = A_plus_mat.row(k) * temp_vec;
                out_Matrix[k](i, j + 1) = temp(0, 0);
            }
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c + 1; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                if (j == c)
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
void IOManager::load_ss(ifstream &in, Matrixint64 &data, Matrixint64 &label, int size)
{
    int i = 0;
    while (in)
    {
        string s;
        if (!getline(in, s))
            break;
        char *ch;
        ch = const_cast<char *>(s.c_str());
        int64 temp;
        char c;

        temp = Constant::Util::getint64(ch);
        //        if (temp > 1)
        //            temp = 1;
        label(i, 0) = temp;

        // data(i, D) = IE;
        for (int j = 0; j < D; j++)
        {
            temp = Constant::Util::getint64(ch);
            data(i, j) = temp;
        }
        i++;
        if (i >= size)
            break;
    }
    for (i; i < size; i++)
    {
        int tmp_r;
        tmp_r = data.cols();
        for (int j = 0; j < tmp_r; j++)
        {
            data(i, j) = data(i - size, j);
        }
        tmp_r = label.cols();
        for (int j = 0; j < tmp_r; j++)
        {
            label(i, j) = label(i - size, j);
        }
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

    // ifstream intest("data/mnist_test.csv");
    // load_data(intest, test_data, test_label, testN);
    // secret_share(test_data, test_label, "test");
    ifstream intest("data/mnist_test_" + to_string(party) + ".csv");
    load_ss(intest, test_data, test_label, testN);
    intest.close();

    // TODO: secret sharing save file

    //    train_data.reoeder();
    //    train_label.reoeder();
    //    test_data.reoeder();
    //    test_label.reoeder();
}