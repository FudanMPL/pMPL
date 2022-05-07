
#include "Constant.h"

int64 Constant::Clock::global_clock[101] = {0};

void Constant::Clock::print_clock(int id)
{
    DBGprint("clock: %d %f\n", id, global_clock[id] * 1.0 * microseconds::period::num / microseconds::period::den);
}

double Constant::Clock::get_clock(int id)
{
    return global_clock[id] * 1.0 * microseconds::period::num / microseconds::period::den;
}

void Constant::Util::int_to_char(char *&p, int u)
{
    *p++ = u & 0xff;
    *p++ = u >> 8 & 0xff;
    *p++ = u >> 16 & 0xff;
    *p++ = u >> 24 & 0xff;
}

void Constant::Util::int64_to_char(char *&p, int64 u)
{
    *p++ = u & 0xff;
    *p++ = u >> 8 & 0xff;
    *p++ = u >> 16 & 0xff;
    *p++ = u >> 24 & 0xff;
    *p++ = u >> 32 & 0xff;
    *p++ = u >> 40 & 0xff;
    *p++ = u >> 48 & 0xff;
    *p++ = u >> 56 & 0xff;
}

int Constant::Util::char_to_int(char *&p)
{
    int ret = 0;
    ret = *p++ & 0xff;
    ret |= (*p++ & 0xff) << 8;
    ret |= (*p++ & 0xff) << 16;
    ret |= (*p++ & 0xff) << 24;
    return ret;
}

int64 Constant::Util::char_to_int64(char *&p)
{
    int64 ret = 0;
    ret = (int64)(*p++ & 0xff);
    ret |= (int64)(*p++ & 0xff) << 8;
    ret |= (int64)(*p++ & 0xff) << 16;
    ret |= (int64)(*p++ & 0xff) << 24;
    ret |= (int64)(*p++ & 0xff) << 32;
    ret |= (int64)(*p++ & 0xff) << 40;
    ret |= (int64)(*p++ & 0xff) << 48;
    ret |= (int64)(*p++ & 0xff) << 56;
    return ret;
}

void Constant::Util::int_to_header(char *p, int u)
{
    *p++ = u & 0xff;
    *p++ = u >> 8 & 0xff;
    *p++ = u >> 16 & 0xff;
    *p++ = u >> 24 & 0xff;
}

int Constant::Util::header_to_int(char *p)
{
    int ret = 0;
    ret = *p++ & 0xff;
    ret |= (*p++ & 0xff) << 8;
    ret |= (*p++ & 0xff) << 16;
    ret |= (*p++ & 0xff) << 24;
    return ret;
}

int64 Constant::Util::double_to_int64(double x)
{
    return static_cast<int64>((long)(x * IE));
}

double Constant::Util::int64_to_double(int64 u)
{
    return (long)u / (double)IE;
}

double Constant::Util::char_to_double(char *&p)
{
    return strtod(p, NULL);
}

int Constant::Util::getint(char *&p)
{
    while (!isdigit(*p))
        p++;
    int ret = 0;
    while (isdigit(*p))
    {
        ret = 10 * ret + *p - '0';
        p++;
    }
    return ret;
}

int64 Constant::Util::getint64(char *&p)
{
    bool negative = false;
    while (!isdigit(*p) && (*p != '-'))
        p++;
    int64 ret = 0;
    while (isdigit(*p) || (*p == '-'))
    {
        if (isdigit(*p)){
            ret = 10 * ret + *p - '0';
        } else
            negative = true;
        p++;
    }
    if (negative == true)
    return (-1) * ret;
    else
        return ret;
}
// int64 Constant::Util::randomlong() {
//     return rand() % MOD;
// }

int64 Constant::Util::random_int64()
{
    int64 ra = (int64)((rand()));
    int64 rb = (int64)((rand()));
    ra <<= (sizeof(int) * 8);
    return (int64)((ra | rb) % ((int64)pow(2, 60)));
    // return (int64)((ra | rb));
}

u8 Constant::Util::random_u8()
{
    return rand() % 512;
}


int64 Constant::Util::multiply(int64 a, int64 b)
{
    auto la = (long)a;
    auto lb = (long)b;
    long product = (la * lb) / IE;
    return static_cast<int64>(product);
}

int64 Constant::Util::truncate(int64 x)
{
    return static_cast<int64>((long)x / IE);
}

int64 Constant::Util::divide(int64 a, int b)
{
    return static_cast<int64>((long)a / (double)b);
}

// int64 Constant::Util::get_residual(int64 a) {
//     return (a % MOD + MOD) % MOD;
// }

// ll128 Constant::Util::get_sign(ll128 a) {
//     return a > MOD / 2 ? a - MOD : a;
// }

// ll128 Constant::Util::get_abs(ll128 a) {
//     return a > 0 ? a : -a;
// }

// ll128 Constant::Util::sqrt(ll128 a) {
//     return power(a, MOD + 1 >> 2);
// }

// int64 Constant::Util::inverse(int64 a, int64 b) {
//      return power(a, b-2);
//  }

// int64 Constant::Util::power(int64 a, int64 b) {
//      int64 ret = 1;
//      a = (a%MOD+MOD)%MOD;
//      b = (b%MOD+MOD)%MOD;
//     if (b == 0)
//         return 1;
//     while (b > 0) {
//         if (b&1) ret = ret * a;
//         ret = get_residual(ret);
//         a = a * a;
//         a = get_residual(a);
//         b >>= 1;
//     }
//     return ret;
// }

// ll128 Constant::Util::cal_perm(ll128 *key, int l, int k) {
//     if (!l)
//         return 1;
//     vector<ll128> a(l+1);
//     a[0] = 1;
//     for (int i = 0; i < M; i++)
//         if (i != k)
//             for (int j = l; j; j--) {
//                 a[j] += a[j - 1] * key[i];
//                 a[j] = get_residual(a[j]);
//             }
//     return a[l];
// }
// std::ostream&
// operator<<( std::ostream& dest, int64 value )
// {
//     std::ostream::sentry s( dest );
//     if ( s ) {
//         __uint128_t tmp = value < 0 ? -value : value;
//         char buffer[ 64 ];
//         char* d = std::end( buffer );
//         do
//         {
//             -- d;
//             *d = "0123456789"[ tmp % 10 ];
//             tmp /= 10;
//         } while ( tmp != 0 );
//         if ( value < 0 ) {
//             -- d;
//             *d = '-';
//         }
//         int len = std::end( buffer ) - d;
//         if ( dest.rdbuf()->sputn( d, len ) != len ) {
//             dest.setstate( std::ios_base::badbit );
//         }
//     }
//     return dest;
// }
// const int64 Constant::inv2 = Constant::Util::inverse(2, MOD);

// const int64 Constant::inv2_m = Constant::Util::inverse(1 << DECIMAL_LENGTH, MOD);

vector<int64> Constant::Util::edabits()
{
    vector<int64> res(110); // 1+64+1+44
    srand((unsigned)time(NULL));
    int64 r = Constant::Util::random_int64(), _r;
    res[0] = r;
    for (int i = 1; i < 65; i++)
    {
        res[i] = r % 2;
        r = r >> 1;
        if (i >= 20)
        {
            if (i == 20)
            {
                // r' begins
                std::cout << "r' is " << r << std::endl;
                _r = r;
                res[65] = r;
            }
            res[i + 46] = _r % 2;
            _r = _r >> 1;
        }
    }
    std::reverse(res.begin() + 1, res.begin() + 65);
    std::reverse(res.begin() + 66, res.end());
    return res;
}

vector<int64> Constant::Util::edabits(int64 r)
{
    vector<int64> res(110); // 1+64+1+44
    int64 _r;
    res[0] = r;
    for (int i = 1; i < 65; i++)
    {
        res[i] = r % 2;
        r = r >> 1;
        if (i >= 20)
        {
            if (i == 20)
            {
                // r' begins
                std::cout << "r' is " << r << std::endl;
                _r = r;
                res[65] = r;
            }
            res[i + 46] = _r % 2;
            _r = _r >> 1;
        }
    }
    std::reverse(res.begin() + 1, res.begin() + 65);
    std::reverse(res.begin() + 66, res.end());
    return res;
}