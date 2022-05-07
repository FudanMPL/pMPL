#ifndef MAT_H
#define MAT_H
#include <Eigen/Dense>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#include "../Constant.h"
#include <random>

using namespace std;
using namespace Eigen;

typedef Tensor<int64, 2> TensorRu;
typedef Tensor<int64, 2, Eigen::RowMajor> TensorRut;
typedef Tensor<int64, 3> TensorRu3;
typedef Matrix<u8, Dynamic, Dynamic> Matrix8;
typedef Matrix<int64, Dynamic, Dynamic> Matrixint64;
typedef Matrix<int128, Dynamic, Dynamic> Matrixint128;
// typedef Matrix<ll, Dynamic, Dynamic> Matrixint64;
// typedef Array<int64, Dynamic, 1> Array;

class Mat
{
    // int r,c;
    // vector<int64> val;
public:
    static TensorRu A, A_plus, A_inv_123, A_inv_124, A_inv_134;
    static void init_public_vector();
    static TensorRu getInverse(const Matrixint64 &origin);

    static TensorRu randomTensorRu(int r, int c);
    static TensorRu3 randomTensorRu3(int r, int c);
    static Matrixint64 randomMatrixint64(int r, int c);
    static Matrix8 randomMatrix8(int r, int c);

    static TensorRu initFromVector(vector<int64> &data, long rows, long cols);

    static void truncateTensorRu(TensorRu &x);
    static void truncateMatrixint64(Matrixint64 &x);
    static void reshape(TensorRu &x, long nrows, long ncols);

    static void randomFill(TensorRu &x);

    static Matrixint64 constant_multiply(Matrixint64 &x, double d);
    static TensorRu cwiseProduct(TensorRu &a, TensorRu &b);

    static Matrixint64 getFrom_pos(char *&p);
    static int toString_pos(char *p, int r, int c, vector<int64> val);

    static vector<int64> toVector(Matrixint64 &a);
    static Matrixint64 fromVector(vector<int64> val, int r, int c);

    static Matrixint64 toMatrix(const TensorRu &a);
    static TensorRu toTensor(const Matrixint64 &a);

    static Matrixint64 op_Xor(const Matrixint64 &a, const Matrixint64 &b);
    static Matrix8 op_Xor(const Matrix8 &a, const Matrix8 &b);
    static Matrixint64 op_Xor(const int64 &a, const Matrixint64 &b);
    static Matrix8 op_Xor(const int64 &a, const Matrix8 &b);
    static Matrixint64 op_And(const Matrixint64 &a, const Matrixint64 &b);
    static Matrix8 op_And(const Matrix8 &a, const Matrix8 &b);
    static Matrixint64 op_And(const int64 &a, const Matrixint64 &b);
    static Matrix8 op_And(const int64 &a, const Matrix8 &b);
    static Matrixint64 op_Or(const Matrixint64 &a, const Matrixint64 &b);
    static Matrix8 op_Or(const Matrix8 &a, const Matrix8 &b);
    static Matrixint64 op_Or(const int64 &a, const Matrixint64 &b);
    static Matrix8 op_Or(const int64 &a, const Matrix8 &b);
    static Matrixint64 op_shift_left(const Matrixint64 &b, const int &a);
    static Matrix8 op_shift_left(const Matrix8 &b, const int &a);
    static Matrixint64 op_shift_right(const Matrixint64 &b, const int &a);
    static Matrix8 op_shift_right(const Matrix8 &b, const int &a);
};

#endif // MAT_H
