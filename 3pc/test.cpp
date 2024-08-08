#include <iostream>
#include "ml/linear.h"
#include "ml/logistic.h"
#include "ml/nn.h"
#include "core/Offline.h"
#include <omp.h>

using namespace std;
using namespace Eigen;

int party = 0;

u128 send_size = 0;
u128 receive_size = 0;

double total_time = 0;

void test_Offline_Mul()
{
     cout << "test Offline_Mul" << endl;
     if (party != 1)
     {
          MatrixXu a = Mat::randomMatrixXu(2, 4);
          cout << "a:" << endl
               << a << endl;
          MatrixXu b = Mat::randomMatrixXu(4, 2);
          cout << "b:" << endl
               << b << endl;
          MatrixXu c = a * b;
          cout << "c:" << endl
               << 3 * c << endl;
          for (int i = 0; i < NUM_SHARES; i++)
          {
               for (int j = i + 1; j < NUM_SHARES; j++)
               {
                    if ((party == i || party == j) && i != 1 && j != 1)
                    {
                         c += Offline_Mul(a, b, i, j);
                    }
               }
          }
          cout << "c:" << endl
               << c << endl;
     }
}

void test_mul_triple()
{
     MatrixXu x(2, 4), y(4, 4), z(2, 4);
     Mul_triple(x, y, z);
     MatrixXu x_raw, y_raw, z_raw;
     x_raw = Secret_Mul::Mul_reveal(x);
     y_raw = Secret_Mul::Mul_reveal(y);
     z_raw = Secret_Mul::Mul_reveal(z);
     cout << "x:" << endl
          << x_raw << endl;
     cout << "y:" << endl
          << y_raw << endl;
     cout << "x*y:" << endl
          << x_raw * y_raw << endl;
     cout << "z:" << endl
          << z_raw << endl;
}

void test_cwise_triple()
{
     MatrixXu x(128, 1), y(128, 1), z(128, 1);
     CwiseProduct_triple(x, y, z);
     MatrixXu x_raw, y_raw, z_raw;
     x_raw = Secret_Mul::Mul_reveal(x);
     y_raw = Secret_Mul::Mul_reveal(y);
     z_raw = Secret_Mul::Mul_reveal(z);
     cout << "x:" << endl
          << x_raw << endl;
     cout << "y:" << endl
          << y_raw << endl;
     cout << "x*y:" << endl
          << x_raw.cwiseProduct(y_raw) << endl;
     cout << "z:" << endl
          << z_raw << endl;
}

void test_bool_triple()
{
     MatrixXu x(2, 3), y(2, 3), z(2, 3);
     Bool_triple(x, y, z);
     MatrixXu x_raw, y_raw, z_raw;
     x_raw = Boolean_Share::reveal(x);
     y_raw = Boolean_Share::reveal(y);
     z_raw = Boolean_Share::reveal(z);
     cout << "x:" << endl
          << x_raw << endl;
     cout << "y:" << endl
          << y_raw << endl;
     cout << "x*y:" << endl
          << Mat::op_Xor(x_raw, y_raw) << endl;
     cout << "z:" << endl
          << z_raw << endl;
}

void test_bool_triple_B2A()
{
     Matrix8 x(2, 3), y(2, 3), z(2, 3);
     Bool_triple_B2A(x, y, z);
     Matrix8 x_raw, y_raw, z_raw, x_y_raw;
     x_raw = Boolean_Share::reveal(x);
     y_raw = Boolean_Share::reveal(y);
     z_raw = Boolean_Share::reveal(z);
     x_y_raw = Mat::op_Xor(x_raw, y_raw);
     MatrixXu a, b, c, d;
     a = x_raw.cast<u64>();
     b = y_raw.cast<u64>();
     c = z_raw.cast<u64>();
     d = x_y_raw.cast<u64>();
     cout << "x:" << endl
          << a << endl;
     cout << "y:" << endl
          << b << endl;
     cout << "x*y:" << endl
          << d << endl;
     cout << "z:" << endl
          << c << endl;
}

void test_A_reshare_A()
{
     if (party != 1)
     {
          MatrixXu x = Mat::randomMatrixXu(4, 5);
          cout << "truth:" << 3 * x << endl;
          MatrixXu share = A_reshare_A(x);
          MatrixXu reveal = Boolean_Share::add_reveal(share);
          cout << "reveal:" << reveal << endl;
     }
}

void test_edabit()
{
     if (party != 1)
     {
          MatrixXu x = Mat::randomMatrixXu(4, 5);
          cout << "truth:" << 3 * x << endl;
          MatrixXu share = edabit(x);
          MatrixXu reveal = Boolean_Share::reveal(share);
          cout << "reveal:" << reveal << endl;
     }
}

void test_trun_pair()
{

     MatrixXu r(4, 5), trun_r(4, 5);
     r.setZero();
     trun_r.setZero();
     Trun_pair(4, 5, r, trun_r);
     MatrixXu r_reveal = Secret_Mul::Mul_reveal(r);
     MatrixXu trun_r_reveal = Secret_Mul::Mul_reveal(trun_r);
     r_reveal = r_reveal / IE;
     cout << "truth:" << r_reveal << endl;
     cout << "reveal:" << trun_r_reveal << endl;
}

void test_linear_offline()
{
     // 前向mul_triple
     MatrixXu x(128, 784), y(784, 1), z(128, 1);
     Mul_triple(x, y, z);

     // 前向truncation
     MatrixXu r(128, 1), trun_r(128, 1);
     r.setZero();
     trun_r.setZero();
     Trun_pair(128, 1, r, trun_r);
     // 一次 add 需要13组bool triple，truncation 需要4组，所以共 52组
     u128 size = send_size;
     Constant::Clock *clock_triple;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x(128, 1), bool_y(128, 1), bool_z(128, 1);
     Bool_triple(bool_x, bool_y, bool_z);
     total_time = total_time + 51 * clock_triple->get();
     send_size = send_size + 51 * (send_size - size);

     // 反向mul_triple
     MatrixXu x_(784, 128), y_(128, 1), z_(784, 1);
     Mul_triple(x_, y_, z_);

     // 反向 + 更新梯度truncation
     for (int i = 0; i < 2; i++)
     {
          MatrixXu r_(784, 1), trun_r_(784, 1);
          r_.setZero();
          trun_r_.setZero();
          Trun_pair(784, 1, r_, trun_r_);
          // 一次 add 需要13组bool triple，truncation 需要4组，所以共 52组
          size = send_size;
          clock_triple = new Constant::Clock(1);
          MatrixXu bool_x(784, 1), bool_y(784, 1), bool_z(784, 1);
          Bool_triple(bool_x, bool_y, bool_z);
          total_time = total_time + 51 * clock_triple->get();
          send_size = send_size + 51 * (send_size - size);
     }
}

void test_logistic_offline()
{
     // 前向mul_triple
     MatrixXu x(128, 784), y(784, 1), z(128, 1);
     Mul_triple(x, y, z);

     // 前向truncation
     MatrixXu r(128, 1), trun_r(128, 1);
     r.setZero();
     trun_r.setZero();
     Trun_pair(128, 1, r, trun_r);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     u128 size = send_size;
     Constant::Clock *clock_triple;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x1(128, 1), bool_y1(128, 1), bool_z1(128, 1);
     Bool_triple(bool_x1, bool_y1, bool_z1);
     total_time = total_time + 51 * clock_triple->get();
     send_size = send_size + 51 * (send_size - size);
     // sigmoid  edabit(1次 256 ，1) + 3B2A + 2cwise + 2truncation）
     // 1个edabit 需要2 次bitadder,  一次 bitadder 需要13组bool triple
     // edabit + 3 bitadder + 3B2A + 2cwise + 2truncation)
     // edabit + 3 * 13 bool triple + 3 bool triple B2A + 2cwise + 2truncation)
     // edabit
     MatrixXu eda = Mat::randomMatrixXu(256, 1);
     MatrixXu share1 = edabit(eda);
     // 39次bool triple
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x2(256, 1), bool_y2(256, 1), bool_z2(256, 1);
     Bool_triple(bool_x2, bool_y2, bool_z2);
     total_time = total_time + 38 * clock_triple->get();
     send_size = send_size + 38 * (send_size - size);
     // b2a
     for (int j = 0; j < 3; j++)
     {
          Matrix8 a(128, 1), b(128, 1), c(128, 1);
          Bool_triple_B2A(a, b, c);
     }
     // cwise
     for (int j = 0; j < 2; j++)
     {
          MatrixXu cx(128, 1), cy(128, 1), cz(128, 1);
          CwiseProduct_triple(cx, cy, cz);

          // truncation
          MatrixXu cr(128, 1), ctrun_r(128, 1);
          cr.setZero();
          ctrun_r.setZero();
          Trun_pair(128, 1, cr, ctrun_r);
          // 一次 bitadder 需要13组bool triple，truncation 需要4组
          size = send_size;
          clock_triple = new Constant::Clock(1);
          MatrixXu bool_x(128, 1), bool_y(128, 1), bool_z(128, 1);
          Bool_triple(bool_x, bool_y, bool_z);
          total_time = total_time + 51 * clock_triple->get();
          send_size = send_size + 51 * (send_size - size);
     }

     // 反向mul_triple
     MatrixXu x_(784, 128), y_(128, 1), z_(784, 1);
     Mul_triple(x_, y_, z_);

     // 反向 + 更新梯度truncation
     for (int i = 0; i < 2; i++)
     {
          MatrixXu r_(784, 1), trun_r_(784, 1);
          r_.setZero();
          trun_r_.setZero();
          Trun_pair(784, 1, r_, trun_r_);
          size = send_size;
          clock_triple = new Constant::Clock(1);
          MatrixXu bool_x(784, 1), bool_y(784, 1), bool_z(784, 1);
          Bool_triple(bool_x, bool_y, bool_z);
          total_time = total_time + 51 * clock_triple->get();
          send_size = send_size + 51 * (send_size - size);
     }
}

void test_nn_offline()
{
     // 前向mul_triple
     // 第一层(128*784, 784*64)
     MatrixXu x1(128, 784), y1(784, 64), z1(128, 64);
     Mul_triple(x1, y1, z1);

     // 第一层truncation
     MatrixXu r1(128, 64), trun_r1(128, 64);
     r1.setZero();
     trun_r1.setZero();
     Trun_pair(128, 64, r1, trun_r1);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*64 的矩阵拆成256个 32*1小矩阵
     u128 size = send_size;
     Constant::Clock *clock_triple;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x1(32, 1), bool_y1(32, 1), bool_z1(32, 1);
     Bool_triple(bool_x1, bool_y1, bool_z1);
     total_time = total_time + (52 * 256 - 1) * clock_triple->get();
     send_size = send_size + (52 * 256 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 前向mul_triple
     // 第二层(128*64, 64*64)
     MatrixXu x2(128, 64), y2(64, 64), z2(128, 64);
     Mul_triple(x2, y2, z2);

     // 第二层truncation
     MatrixXu r2(128, 64), trun_r2(128, 64);
     r2.setZero();
     trun_r2.setZero();
     Trun_pair(128, 64, r2, trun_r2);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*64 的矩阵拆成256个 32*1小矩阵
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x2(32, 1), bool_y2(32, 1), bool_z2(32, 1);
     Bool_triple(bool_x2, bool_y2, bool_z2);
     total_time = total_time + (52 * 256 - 1) * clock_triple->get();
     send_size = send_size + (52 * 256 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 第一、二层relu edabit + 3bitadder + B2A + cwise + truncation
     for (int i = 0; i < 2; i++)
     {
          MatrixXu eda = Mat::randomMatrixXu(128, 64);
          MatrixXu share1 = edabit(eda);

          size = send_size;
          clock_triple = new Constant::Clock(1);
          // 将128*64 的矩阵拆成256个 32*1小矩阵
          MatrixXu bool_x3(32, 1), bool_y3(32, 1), bool_z3(32, 1);
          Bool_triple(bool_x3, bool_y3, bool_z3);
          total_time = total_time + (39 * 256 - 1) * clock_triple->get();
          send_size = send_size + (39 * 256 - 1) * (send_size - size);

          // b2a
          Matrix8 a(128, 64), b(128, 64), c(128, 64);
          Bool_triple_B2A(a, b, c);

          // cwise
          MatrixXu cx(128, 64), cy(128, 64), cz(128, 64);
          CwiseProduct_triple(cx, cy, cz);

          // truncation
          MatrixXu cr(128, 64), ctrun_r(128, 64);
          cr.setZero();
          ctrun_r.setZero();
          Trun_pair(128, 64, cr, ctrun_r);
          // 一次 bitadder 需要13组bool triple，truncation 需要4组
          // 将128*64 的矩阵拆成256个 32*1小矩阵
          size = send_size;
          clock_triple = new Constant::Clock(1);
          MatrixXu bool_x4(32, 1), bool_y4(32, 1), bool_z4(32, 1);
          Bool_triple(bool_x4, bool_y4, bool_z4);
          total_time = total_time + (52 * 256 - 1) * clock_triple->get();
          send_size = send_size + (52 * 256 - 1) * (send_size - size);
     }

     cout << __LINE__ << endl;

     // 前向mul_triple
     // 输出层(128*64, 64*64)
     MatrixXu x3(128, 64), y3(64, 1), z3(128, 1);
     Mul_triple(x3, y3, z3);

     // 输出层truncation
     MatrixXu r3(128, 1), trun_r3(128, 1);
     r3.setZero();
     trun_r3.setZero();
     Trun_pair(128, 1, r3, trun_r3);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*1 的矩阵拆成4个 32*1小矩阵
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x5(32, 1), bool_y5(32, 1), bool_z5(32, 1);
     Bool_triple(bool_x5, bool_y5, bool_z5);
     total_time = total_time + (52 * 4 - 1) * clock_triple->get();
     send_size = send_size + (52 * 4 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 反向mul_triple
     // 输出层(64*128, 128*1) 2次乘法
     MatrixXu x4(64, 128), y4(128, 1), z4(64, 1);
     Mul_triple(x4, y4, z4);

     MatrixXu x5(128, 1), y5(1, 64), z5(128, 64);
     Mul_triple(x5, y5, z5);

     // 3次trun 2次（64，1），1次（128，64）
     for (int i = 0; i < 2; i++)
     {
          MatrixXu r4_(64, 1), trun_r4_(64, 1);
          r4_.setZero();
          trun_r4_.setZero();
          Trun_pair(64, 1, r4_, trun_r4_);
          // 一次 bitadder 需要13组bool triple，truncation 需要4组
          // 将64*1 的矩阵拆成2个 32*1小矩阵

          MatrixXu bool_x(32, 1), bool_y(32, 1), bool_z(32, 1);
          Bool_triple(bool_x, bool_y, bool_z);
          total_time = total_time + 103 * clock_triple->get();
          send_size = send_size + 103 * (send_size - size);
     }

     MatrixXu r5_(128, 64), trun_r5_(128, 64);
     r5_.setZero();
     trun_r5_.setZero();
     Trun_pair(128, 64, r5_, trun_r5_);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*64 的矩阵拆成256个 32*1小矩阵
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x6(32, 1), bool_y6(32, 1), bool_z6(32, 1);
     Bool_triple(bool_x6, bool_y6, bool_z6);
     total_time = total_time + (52 * 256 - 1) * clock_triple->get();
     send_size = send_size + (52 * 256 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 反向relu （128，64）
     MatrixXu cx(128, 64), cy(128, 64), cz(128, 64);
     CwiseProduct_triple(cx, cy, cz);

     // truncation
     MatrixXu cr(128, 64), ctrun_r(128, 64);
     cr.setZero();
     ctrun_r.setZero();
     Trun_pair(128, 64, cr, ctrun_r);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*64 的矩阵拆成256个 32*1小矩阵
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x7(32, 1), bool_y7(32, 1), bool_z7(32, 1);
     Bool_triple(bool_x7, bool_y7, bool_z7);
     total_time = total_time + (52 * 256 - 1) * clock_triple->get();
     send_size = send_size + (52 * 256 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 反向linear mul_triple
     MatrixXu x6(64, 128), y6(128, 64), z6(64, 64);
     Mul_triple(x6, y6, z6);

     MatrixXu x7(128, 64), y7(64, 64), z7(128, 64);
     Mul_triple(x7, y7, z7);

     // 3次trun 2次（64，64），1次（128，64）
     for (int i = 0; i < 2; i++)
     {
          MatrixXu r6_(64, 64), trun_r6_(64, 64);
          r6_.setZero();
          trun_r6_.setZero();
          Trun_pair(64, 64, r6_, trun_r6_);
          // 一次 bitadder 需要13组bool triple，truncation 需要4组
          // 将64*64 的矩阵拆成 128个 32*1小矩阵
          size = send_size;
          clock_triple = new Constant::Clock(1);
          MatrixXu bool_x(64, 64), bool_y(64, 64), bool_z(64, 64);
          Bool_triple(bool_x, bool_y, bool_z);
          total_time = total_time + (52 * 128 - 1) * clock_triple->get();
          send_size = send_size + (52 * 128 - 1) * (send_size - size);
     }

     MatrixXu r7_(128, 64), trun_r7_(128, 64);
     r7_.setZero();
     trun_r7_.setZero();
     Trun_pair(128, 64, r7_, trun_r7_);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*64 的矩阵拆成 256个 32*1小矩阵
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x8(32, 1), bool_y8(32, 1), bool_z8(32, 1);
     Bool_triple(bool_x8, bool_y8, bool_z8);
     total_time = total_time + (52 * 256 - 1) * clock_triple->get();
     send_size = send_size + (52 * 256 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 反向relu （128，64）
     MatrixXu cx2(128, 64), cy2(128, 64), cz2(128, 64);
     CwiseProduct_triple(cx2, cy2, cz2);

     // truncation
     MatrixXu cr2(128, 64), ctrun_r2(128, 64);
     cr2.setZero();
     ctrun_r2.setZero();
     Trun_pair(128, 64, cr2, ctrun_r2);
     // 一次 bitadder 需要13组bool triple，truncation 需要4组
     // 将128*64 的矩阵拆成 256个 32*1小矩阵
     size = send_size;
     clock_triple = new Constant::Clock(1);
     MatrixXu bool_x9(32, 1), bool_y9(32, 1), bool_z9(32, 1);
     Bool_triple(bool_x9, bool_y9, bool_z9);
     total_time = total_time + (52 * 256 - 1) * clock_triple->get();
     send_size = send_size + (52 * 256 - 1) * (send_size - size);

     cout << __LINE__ << endl;

     // 反向输入层
     MatrixXu x8(784, 128), y8(128, 64), z8(784, 64);
     Mul_triple(x8, y8, z8);

     // 2次trun 2次（784，64）
     for (int i = 0; i < 2; i++)
     {
          MatrixXu r8_(784, 64), trun_r8_(784, 64);
          r8_.setZero();
          trun_r8_.setZero();
          Trun_pair(784, 64, r8_, trun_r8_);
          // 一次 bitadder 需要13组bool triple，truncation 需要4组
          // 将784*64 的矩阵拆成 256个 32*1小矩阵
          size = send_size;
          clock_triple = new Constant::Clock(1);
          MatrixXu bool_x(32, 1), bool_y(32, 1), bool_z(32, 1);
          Bool_triple(bool_x, bool_y, bool_z);
          total_time = total_time + (52 * 1568 - 1) * clock_triple->get();
          send_size = send_size + (52 * 1568 - 1) * (send_size - size);
     }
}

int main(int argc, char **argv)
{
     Mat::init_public_vector();
     Secret_Mul::init();
     Boolean_Share::init();
     if (argc < 2)
     {
          DBGprint("Please enter party index:\n");
          scanf("%d", &party);
     }
     else
     {
          party = argv[1][0] - '0';
     }
     DBGprint("party index: %d\n", party);
     SocketUtil::socket_init();
     IOManager::init();
     // test_trun_pair();
     // test_A_reshare_A();
     // test_edabit();
     // test_Offline_Mul();
     // test_mul_triple();
     // test_cwise_triple();
     // test_bool_triple_B2A();
     // test_relu();
     // Secret_Mul::get_Triplets();
     omp_set_num_threads(8);
     cout << __LINE__ << endl;
     Constant::Clock *clock_train;
     clock_train = new Constant::Clock(1);
     // test_linear_offline();
     // test_logistic_offline();
     test_nn_offline();
     total_time += clock_train->get();
     cout << "time：" << total_time << endl;
     cout << "send: " << send_size << " " << "receive: " << receive_size << endl;
     return 0;
}