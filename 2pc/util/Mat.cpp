#include "Mat.h"

TensorRu Mat::A = TensorRu(3, 3);
TensorRu Mat::A_plus = TensorRu(4, 3);
TensorRu Mat::A_inv_123 = TensorRu(3, 3);
TensorRu Mat::A_inv_124 = TensorRu(3, 3);
TensorRu Mat::A_inv_134 = TensorRu(3, 3);

TensorRu Mat::getInverse(const Matrixint64 &origin)
{
    TensorRu inv(3, 3);
    // int row = inv.rows(), col = inv.cols();
    int row = inv.dimension(0), col = inv.dimension(1);
    MatrixXd temp(row, col);
    // temp << origin.cast<double>();
    //  for (int i = 0; i < origin.rows(); i++)
    //  {
    //      for (int j = 0; j < origin.cols(); j++)
    //      {
    //          temp(i, j) = Constant::Util::int64_to_double(origin(i, j));
    //      }
    //  }
    temp = temp.inverse();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            inv(i, j) = Constant::Util::double_to_int64(temp(i, j));
        }
    }
    return inv;
}

void Mat::init_public_vector()
{
    Matrixint64 A_plus_temp(4, 3);
    A_plus_temp << 0, 1, 1,
        3, 2, 1,
        1, 1, 0,
        1, 0, 1;
    A_plus.setValues({{0, 1, 1}, {3, 2, 1}, {1, 1, 0}, {1, 0, 1}});
    Matrixint64 temp(3, 3);
    A_inv_123 = Mat::getInverse(A_plus_temp.topRows(3));
    temp << A_plus_temp.row(0), A_plus_temp.row(1), A_plus_temp.row(3);
    A_inv_124 = Mat::getInverse(temp);
    temp << A_plus_temp.row(0), A_plus_temp.row(2), A_plus_temp.row(3);
    A_inv_134 = Mat::getInverse(temp);
    return;
}

TensorRu Mat::randomTensorRu(int rows, int cols)
{
    TensorRu res(rows, cols);
    res.setZero();
    int64 *data = res.data();
    for (int i = 0; i < res.size(); i++)
    {
        *(data + i) = Constant::Util::random_int64();
    }
    return res;
}

TensorRu3 Mat::randomTensorRu3(int rows, int cols)
{
    TensorRu3 res(3, rows, cols);
    // res.setZero();
    int64 *data = res.data();
    for (int i = 0; i < res.size(); i++)
    {
        *(data + i) = Constant::Util::random_int64();
    }
    return res;
}

Matrixint64 Mat::randomMatrixint64(int rows, int cols)
{
    Matrixint64 res(rows, cols);
    res.setZero();
    int64 *data = res.data();
    for (int i = 0; i < res.size(); i++)
    {
        *(data + i) = Constant::Util::random_int64();
    }
    return res;
}

Matrix8 Mat::randomMatrix8(int rows, int cols)
{
    Matrix8 res(rows, cols);
    res.setZero();
    u8 *data = res.data();
    for (int i = 0; i < res.size(); i++)
    {
        *(data + i) = Constant::Util::random_u8();
    }
    return res;
}

TensorRu Mat::initFromVector(vector<int64> &data, long rows, long cols)
{
    assert(data.size() == (ulong)(rows * cols));
    TensorRu res(rows, cols);
    res.setZero();
    int64 *pt = res.data();
    for (long i = 0; i < res.size(); i++)
    {
        *(pt + i) = data[i];
    }
    return res;
}

void Mat::truncateTensorRu(TensorRu &x)
{
    for (long i = 0; i < x.size(); i++)
    {
        x.data()[i] = Constant::Util::truncate(x.data()[i]);
    }
}

void Mat::truncateMatrixint64(Matrixint64 &x)
{
    for (long i = 0; i < x.size(); i++)
    {
        x.data()[i] = Constant::Util::truncate(x.data()[i]);
    }
}

void Mat::reshape(TensorRu &x, long nrows, long ncols)
{
    int row = x.dimension(0);
    int col = x.dimension(1);
    if (row == nrows && col == ncols)
    {
        return;
    }
    else if (row > nrows && col > ncols)
    {
        Matrixint64 temp = toMatrix(x);
        temp = temp.topLeftCorner(nrows, ncols);
        x = toTensor(temp);
    }
    else
    {
        Matrixint64 nx = Matrixint64::Zero(nrows, ncols);
        Matrixint64 temp = toMatrix(x);
        nx.topLeftCorner(row, col) = temp;
        TensorRu temp1 = toTensor(nx);
        x = temp1;
    }
}

void Mat::randomFill(TensorRu &x)
{
    for (long i = 0; i < x.size(); i++)
    {
        x.data()[i] = Constant::Util::random_int64();
    }
}

Matrixint64 Mat::constant_multiply(Matrixint64 &x, double d)
{
    Matrixint64 res(x.rows(), x.cols());
    for (int i = 0; i < x.size(); i++)
    {
        res.data()[i] = (int64)(d * x.data()[i]);
    }
    return res;
}

TensorRu Mat::cwiseProduct(TensorRu &a, TensorRu &b)
{
    int a_row = a.dimension(0);
    int a_col = a.dimension(1);
    int b_row = b.dimension(0);
    int b_col = b.dimension(1);
    assert(a_row == b_row);
    assert(a_col == b_col);
    TensorRu res(a_row, a_col);
    for (int i = 0; i < a.size(); i++)
    {
        res.data()[i] = a.data()[i] * b.data()[i];
    }
    return res;
}

Matrixint64 Mat::getFrom_pos(char *&p)
{
    vector<int64> val;
    int r = Constant::Util::char_to_int(p);
    int c = Constant::Util::char_to_int(p);
    val.resize(r * c);
    int l = r * c;
    for (int i = 0; i < l; i++)
    {
        val[i] = Constant::Util::char_to_int64(p);
    }
    return Mat::fromVector(val, r, c);
}

int Mat::toString_pos(char *p, int r, int c, vector<int64> val)
{
    Constant::Util::int_to_char(p, r);
    Constant::Util::int_to_char(p, c);
    int l = r * c;
    for (int i = 0; i < l; i++)
    {
        Constant::Util::int64_to_char(p, val[i]);
    }
    *p = 0;
    return 2 * 4 + r * c * 8;
}

vector<int64> Mat::toVector(Matrixint64 &a)
{
    vector<int64> val;
    int r = a.rows();
    int c = a.cols();
    int l = r * c;
    val.resize(r * c);
    // cout<<"toVector:"<<endl;
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
        {
            val[(i * r + j) % l] = a(j, i);
            // printf("%lld ", (long long)val[(i * c + j) % l]);
        }
    // printf("\n");
    return val;
}

Matrixint64 Mat::fromVector(vector<int64> val, int r, int c)
{
    Matrixint64 a(r, c);
    int l = r * c;
    // cout<<"fromVector:"<<endl;
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
        {
            a(j, i) = val[(i * r + j) % l];
            // printf("%lld ", (long long)val[(i * c + j) % l]);
        }
    // printf("\n");
    return a;
}

Matrixint64 Mat::toMatrix(const TensorRu &a)
{
    int row = a.dimension(0);
    int col = a.dimension(1);
    Matrixint64 res(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res(i, j) = a(i, j);
        }
    }
    return res;
}

TensorRu Mat::toTensor(const Matrixint64 &a)
{
    int row = a.rows();
    int col = a.cols();
    TensorRu res(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res(i, j) = a(i, j);
        }
    }
    return res;
}

Matrixint64 Mat::op_Xor(const Matrixint64 &a, const Matrixint64 &b)
{
    if (a.rows() == b.rows() && a.cols() == b.cols())
    {
        int row = a.rows();
        int col = a.cols();
        Matrixint64 c(row, col);
        for (int i = 0; i < a.size(); i++)
        {
            c(i) = a(i) ^ b(i);
        }
        return c;
    }
    else
    {
        cout << "The Matrices can not do operator xor" << endl;
    }
}

Matrix8 Mat::op_Xor(const Matrix8 &a, const Matrix8 &b)
{
    if (a.rows() == b.rows() && a.cols() == b.cols())
    {
        int row = a.rows();
        int col = a.cols();
        Matrix8 c(row, col);
        for (int i = 0; i < a.size(); i++)
        {
            c(i) = a(i) ^ b(i);
        }
        return c;
    }
    else
    {
        cout << "The Matrices can not do operator xor" << endl;
    }
}

Matrixint64 Mat::op_Xor(const int64 &a, const Matrixint64 &b)
{
    int row = b.rows();
    int col = b.cols();
    Matrixint64 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = a ^ b(i);
    }
    return c;
}

Matrix8 Mat::op_Xor(const int64 &a, const Matrix8 &b)
{
    int row = b.rows();
    int col = b.cols();
    Matrix8 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = a ^ b(i);
    }
    return c;
}

Matrixint64 Mat::op_And(const Matrixint64 &a, const Matrixint64 &b)
{
    if (a.rows() == b.rows() && a.cols() == b.cols())
    {
        int row = a.rows();
        int col = a.cols();
        Matrixint64 c(row, col);
        for (int i = 0; i < a.size(); i++)
        {
            c(i) = a(i) & b(i);
        }
        return c;
    }
    else
    {
        cout << "The Matrices can not do operator and" << endl;
    }
}

Matrix8 Mat::op_And(const Matrix8 &a, const Matrix8 &b)
{
    if (a.rows() == b.rows() && a.cols() == b.cols())
    {
        int row = a.rows();
        int col = a.cols();
        Matrix8 c(row, col);
        for (int i = 0; i < a.size(); i++)
        {
            c(i) = a(i) & b(i);
        }
        return c;
    }
    else
    {
        cout << "The Matrices can not do operator and" << endl;
    }
}

Matrixint64 Mat::op_And(const int64 &a, const Matrixint64 &b)
{
    int row = b.rows();
    int col = b.cols();
    Matrixint64 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = a & b(i);
    }
    return c;
}

Matrix8 Mat::op_And(const int64 &a, const Matrix8 &b)
{
    int row = b.rows();
    int col = b.cols();
    Matrix8 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = a & b(i);
    }
    return c;
}

Matrixint64 Mat::op_Or(const Matrixint64 &a, const Matrixint64 &b)
{
    if (a.rows() == b.rows() && a.cols() == b.cols())
    {
        int row = a.rows();
        int col = a.cols();
        Matrixint64 c(row, col);
        for (int i = 0; i < a.size(); i++)
        {
            c(i) = a(i) | b(i);
        }
        return c;
    }
    else
    {
        cout << "The Matrices can not do operator and" << endl;
    }
}

Matrix8 Mat::op_Or(const Matrix8 &a, const Matrix8 &b)
{
    if (a.rows() == b.rows() && a.cols() == b.cols())
    {
        int row = a.rows();
        int col = a.cols();
        Matrix8 c(row, col);
        for (int i = 0; i < a.size(); i++)
        {
            c(i) = a(i) | b(i);
        }
        return c;
    }
    else
    {
        cout << "The Matrices can not do operator and" << endl;
    }
}

Matrixint64 Mat::op_Or(const int64 &a, const Matrixint64 &b)
{
    int row = b.rows();
    int col = b.cols();
    Matrixint64 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = a | b(i);
    }
    return c;
}

Matrix8 Mat::op_Or(const int64 &a, const Matrix8 &b)
{
    int row = b.rows();
    int col = b.cols();
    Matrix8 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = a | b(i);
    }
    return c;
}

Matrixint64 Mat::op_shift_left(const Matrixint64 &b, const int &a)
{
    int row = b.rows();
    int col = b.cols();
    Matrixint64 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = b(i) << a;
    }
    return c;
}

Matrix8 Mat::op_shift_left(const Matrix8 &b, const int &a)
{
    int row = b.rows();
    int col = b.cols();
    Matrix8 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = b(i) << a;
    }
    return c;
}

Matrixint64 Mat::op_shift_right(const Matrixint64 &b, const int &a)
{
    int row = b.rows();
    int col = b.cols();
    Matrixint64 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = b(i) >> a;
    }
    return c;
}

Matrix8 Mat::op_shift_right(const Matrix8 &b, const int &a)
{
    int row = b.rows();
    int col = b.cols();
    Matrix8 c(row, col);
    for (int i = 0; i < b.size(); i++)
    {
        c(i) = b(i) >> a;
    }
    return c;
}