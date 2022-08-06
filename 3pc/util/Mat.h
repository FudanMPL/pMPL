
#ifndef MAT_H
#define MAT_H
#include <Eigen/Dense>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#include "../Constant.h"
#include <random>

using namespace std;
using namespace Eigen;

typedef Tensor<u64, 2> TensorRu;
typedef Tensor<u64, 3> TensorRu3;
typedef Tensor<u64, 2, Eigen::RowMajor> TensorRut;
typedef Matrix<u8, Dynamic, Dynamic> Matrix8;
typedef Matrix<u64, Dynamic, Dynamic> MatrixXu;
typedef Matrix<int64, Dynamic, Dynamic> Matrixint64;
typedef Matrix<int128, Dynamic, Dynamic> Matrixint128;
typedef Matrix<u128, Dynamic, Dynamic> Matrix128;
// typedef Matrix<ll, Dynamic, Dynamic> MatrixXu;
// typedef Array<u64, Dynamic, 1> Array;

class Mat
{
    // int r,c;
    // vector<u64> val;
public:
    static TensorRu A, A_plus, A_inv_123, A_inv_124, A_inv_134;
    static void init_public_vector();
    static TensorRu getInverse(const MatrixXu &origin);

    static TensorRu randomTensorRu(int r, int c);
    static TensorRu3 randomTensorRu3(int r, int c);

    static MatrixXu randomMatrixXu(int r, int c);
    static Matrix8 randomMatrix8(int r, int c);

    static TensorRu initFromVector(vector<u64> &data, long rows, long cols);

    static void truncateTensorRu(TensorRu &x);
    static void truncateMatrixXu(MatrixXu &x);
    static void reshape(TensorRu &x, long nrows, long ncols);

    static void randomFill(TensorRu &x);

    static MatrixXu constant_multiply(MatrixXu &x, double d);
    static TensorRu cwiseProduct(TensorRu &a, TensorRu &b);

    static MatrixXu getFrom_pos(char *&p);
    static int toString_pos(char *p, int r, int c, vector<u64> val);

    static vector<u64> toVector(MatrixXu &a);
    static MatrixXu fromVector(vector<u64> val, int r, int c);

    static MatrixXu toMatrix(const TensorRu &a);
    static TensorRu toTensor(const MatrixXu &a);

    static MatrixXd u642Double(const MatrixXu &a);

    static MatrixXu op_Xor(const MatrixXu &a, const MatrixXu &b);
    static Matrix8 op_Xor(const Matrix8 &a, const Matrix8 &b);
    static MatrixXu op_Xor(const u64 &a, const MatrixXu &b);
    static Matrix8 op_Xor(const u64 &a, const Matrix8 &b);
    static MatrixXu op_And(const MatrixXu &a, const MatrixXu &b);
    static Matrix8 op_And(const Matrix8 &a, const Matrix8 &b);
    static MatrixXu op_And(const u64 &a, const MatrixXu &b);
    static Matrix8 op_And(const u64 &a, const Matrix8 &b);
    static MatrixXu op_Or(const MatrixXu &a, const MatrixXu &b);
    static Matrix8 op_Or(const Matrix8 &a, const Matrix8 &b);
    static MatrixXu op_Or(const u64 &a, const MatrixXu &b);
    static Matrix8 op_Or(const u64 &a, const Matrix8 &b);
    static MatrixXu op_shift_left(const MatrixXu &b, const int &a);
    static Matrix8 op_shift_left(const Matrix8 &b, const int &a);
    static MatrixXu op_shift_right(const MatrixXu &b, const int &a);
    static Matrix8 op_shift_right(const Matrix8 &b, const int &a);
};

#endif // MAT_H
