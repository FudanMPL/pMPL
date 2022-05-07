#ifndef CONSTANT_H
#define CONSTANT_H

#ifndef UNIX_PLATFORM
#define UNIX_PLATFORM
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <queue>
#include <Eigen/Dense>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <chrono>
#include <cmath>
#include <limits>
#ifdef UNIX_PLATFORM
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#else
#include <winsock2.h>
#endif

#define BUFFER_MAX 10000001
#define HEADER_LEN_OPT 2
#define HEADER_LEN 4
#define M 3               // the number of parties
#define ML 0              // 0 for linear regression; 1 for logistic; 2 for nn
#define BIT_LENGTH 64     // the length of bit
#define DECIMAL_LENGTH 20 // the length of decimal part

#define IE 1048576ll // 2^20
#define N 60000      // the number of train data
#define testN 10000  // the number of test data
#define Ep 5
#define B 128
#define D 784 // the size of total features
#define IT N *Ep / B
// #define R 0.04 // linear regression learning rate
#define R 0.01 // logistic regression learning rate

#define nLayer 3  // the number of layers
#define hiddenDim 128 // the number of
#define numClass 1

#define DEBUG
#ifdef DEBUG
#define DBGprint(...) printf(__VA_ARGS__)
#else
#define DBGprint(...)
#endif

using namespace std;
using namespace chrono;

typedef int64_t int64;
typedef __int128_t int128;
typedef uint8_t u8; // 8 bit
typedef long long ll;

class Constant
{
public:
    static const int64 UINT64_MASK = (uint)1 << DECIMAL_LENGTH;

    // static const int64 inv2;    //求逆
    // static const int64 inv2_m;  //小数部分求逆

    static string getDateTime()
    {
        time_t t = std::time(nullptr);
        struct tm *now = localtime(&t);
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d_%H-%M-%S", now);
        return string(buf);
    }
    class Clock
    {
        int id;
        system_clock::time_point start;
        static int64 global_clock[101];

    public:
        static double get_clock(int id);
        static void print_clock(int id);
        Clock(int id) : id(id)
        {
            start = system_clock::now();
        };
        ~Clock()
        {
            system_clock::time_point end = system_clock::now();
            decltype(duration_cast<microseconds>(end - start)) time_span = duration_cast<microseconds>(end - start);
            global_clock[id] += time_span.count();
        };
        double get()
        {
            system_clock::time_point end = system_clock::now();
            decltype(duration_cast<microseconds>(end - start)) time_span = duration_cast<microseconds>(end - start);
            return time_span.count() * 1.0 * microseconds::period::num / microseconds::period::den;
        }
        void print()
        {
            system_clock::time_point end = system_clock::now();
            decltype(duration_cast<microseconds>(end - start)) time_span = duration_cast<microseconds>(end - start);
            DBGprint("duration: %f\n", time_span.count() * 1.0 * microseconds::period::num / microseconds::period::den);
            // printf("duration: %f\n", time_span.count() * 1.0 * microseconds::period::num / microseconds::period::den);
        }
    };
    class Util
    {
    public:
        static void int_to_char(char *&p, int u);
        static void int64_to_char(char *&p, int64 u);
        static int char_to_int(char *&p);
        static int64 char_to_int64(char *&p);
        static void int_to_header(char *p, int u);
        static int header_to_int(char *p);
        static int64 double_to_int64(double x);
        static double int64_to_double(int64 u); // unsigned to double, long(signed)
        static double char_to_double(char *&p);
        static int64 getint64(char *&p);
        static int getint(char *&p);
        static int64 random_int64();
        static u8 random_u8();

        static int64 truncate(int64 u);        // in form of secureML
        static int64 multiply(int64 a, int64 b); // in form of secureML
        static int64 divide(int64 a, int b);
        static vector<int64> edabits();      // default with 64 bits
        static vector<int64> edabits(int64 r); // default with 64 bits
    };
};
// std::ostream&
// operator<<( std::ostream& dest, int64 value );

#endif // ACCESSCONTROL_CONSTANT_H