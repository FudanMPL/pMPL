#include "SocketOnline.h"

SocketOnline::SocketOnline() {}

SocketOnline::~SocketOnline()
{
    delete buffer;
    delete header;
}

SocketOnline::SocketOnline(int id, SOCK sock)
{
    this->id = id;
    this->sock = sock;
    buffer = new char[BUFFER_MAX];
    header = new char[max(HEADER_LEN, HEADER_LEN_OPT) + 1];
    send_num = 0;
    recv_num = 0;
    init();
}

SocketOnline &SocketOnline::operator=(const SocketOnline &u)
{
    id = u.id;
    sock = u.sock;
    buffer = new char[BUFFER_MAX];
    header = new char[max(HEADER_LEN, HEADER_LEN_OPT) + 1];
    send_num = 0;
    recv_num = 0;
}

void SocketOnline::init(int id, SOCK sock)
{
    this->id = id;
    this->sock = sock;
    buffer = new char[BUFFER_MAX];
    header = new char[HEADER_LEN + 1];
    send_num = 0;
    recv_num = 0;
#ifdef UNIX_PLATFORM
    int flag, ret_flag, ret_sol;
    flag = 1024 * 1024 * 1024;
    //        ret_sol = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (void*)&flag, sizeof(flag));
    ret_flag = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(flag));
    DBGprint("ret sol: %d flag: %d\n", ret_sol, ret_flag);
#else
    int flag, ret_sol, ret_flag;
    flag = 1;
    //    ret_sol = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (const char*)&flag, sizeof(flag));
    ret_flag = setsockopt(sock, SOL_SOCKET, TCP_NODELAY, (const char *)&flag, sizeof(flag));
    DBGprint("ret sol: %d flag: %d\n", ret_sol, ret_flag);
#endif
}

void SocketOnline::init()
{
#ifdef UNIX_PLATFORM
    int flag, ret_flag, ret_sol;
    flag = 1024 * 1024 * 1024;
    //        ret_sol = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (void*)&flag, sizeof(flag));
    ret_flag = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(flag));
    DBGprint("ret sol: %d flag: %d\n", ret_sol, ret_flag);
#else
    int flag, ret_sol, ret_flag;
    flag = 1;
    //        ret_sol = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (const char*)&flag, sizeof(flag));
    ret_flag = setsockopt(sock, SOL_SOCKET, TCP_NODELAY, (const char *)&flag, sizeof(flag));
    DBGprint("ret sol: %d flag: %d\n", ret_sol, ret_flag);
#endif
}

void SocketOnline::reset()
{
    send_num = 0;
    recv_num = 0;
}

int SocketOnline::send_message(SOCK sock, char *p, int l)
{
    int ret;
#ifdef UNIX_PLATFORM
    ret = write(sock, p, l);
#else
    ret = send(sock, p, l, NULL);
#endif
    return ret;
}

int SocketOnline::send_message_n(SOCK sock, char *p, int l)
{
    int tot = 0, cur = 0;
    //    cout<<"send l: "<<l<<endl;
    while (tot < l)
    {
#ifdef UNIX_PLATFORM
        cur = write(sock, p, l - tot);
#else
        cur = send(sock, p, l - tot, NULL);
#endif
        p += cur;
        tot += cur;
    }
    send_num += l;
    return tot;
}

int SocketOnline::recv_message(SOCK sock, char *p, int l)
{
    int ret;
#ifdef UNIX_PLATFORM
    ret = read(sock, p, l);
#else
    ret = recv(sock, p, l, NULL);
#endif
    return ret;
}

int SocketOnline::recv_message_n(SOCK sock, char *p, int l)
{
    int tot = 0, cur = 0;
    //    cout<<"recv l: "<<l<<endl;
    while (tot < l)
    {
#ifdef UNIX_PLATFORM
        cur = read(sock, p, l - tot);
#else
        cur = recv(sock, p, l - tot, NULL);
#endif
        p += cur;
        tot += cur;
    }
    recv_num += l;
    return tot;
}

void SocketOnline::send_message(Matrixint64 &a)
{
    int len_buffer;
    int r = a.rows();
    int c = a.cols();
    send_message_n(sock, (char *)&r, 4);
    send_message_n(sock, (char *)&c, 4);
    send_message_n(sock, (char *)a.data(), r * c * 8);
}

void SocketOnline::send_message(Matrix8 &a)
{
    int len_buffer;
    int r = a.rows();
    int c = a.cols();
    send_message_n(sock, (char *)&r, 4);
    send_message_n(sock, (char *)&c, 4);
    send_message_n(sock, (char *)a.data(), r * c * 1);
}

void SocketOnline::send_message(Matrixint128 &a)
{
    int len_buffer;
    int r = a.rows();
    int c = a.cols();
    send_message_n(sock, (char *)&r, 4);
    send_message_n(sock, (char *)&c, 4);
    send_message_n(sock, (char *)a.data(), r * c * 16);
}

void SocketOnline::send_message(Matrixint64 *a)
{
    int len_buffer;
    int r = a->rows();
    int c = a->cols();
    send_message_n(sock, (char *)&r, 4);
    send_message_n(sock, (char *)&c, 4);
    send_message_n(sock, (char *)a->data(), r * c * 8);
}

void SocketOnline::send_message(Matrix8 *a)
{
    int len_buffer;
    int r = a->rows();
    int c = a->cols();
    send_message_n(sock, (char *)&r, 4);
    send_message_n(sock, (char *)&c, 4);
    send_message_n(sock, (char *)a->data(), r * c * 1);
}


void SocketOnline::send_message(Matrixint128 *a)
{
    int len_buffer;
    int r = a->rows();
    int c = a->cols();
    send_message_n(sock, (char *)&r, 4);
    send_message_n(sock, (char *)&c, 4);
    send_message_n(sock, (char *)a->data(), r * c * 16);
}
void SocketOnline::send_message(int b)
{
    char *p = buffer;
    Constant::Util::int_to_char(p, b);
    send_message_n(sock, buffer, 4);
}

void SocketOnline::recv_message(Matrixint64 &a)
{
    int r, c;
    recv_message_n(sock, (char *)&r, 4);
    recv_message_n(sock, (char *)&c, 4);
    a.resize(r, c);
    recv_message_n(sock, (char *)a.data(), r * c * 8);
}

void SocketOnline::recv_message(Matrix8 &a)
{
    int r, c;
    recv_message_n(sock, (char *)&r, 4);
    recv_message_n(sock, (char *)&c, 4);
    a.resize(r, c);
    recv_message_n(sock, (char *)a.data(), r * c * 1);
}

void SocketOnline::recv_message(Matrixint128 &a)
{
    int r, c;
    recv_message_n(sock, (char *)&r, 4);
    recv_message_n(sock, (char *)&c, 4);
    a.resize(r, c);
    recv_message_n(sock, (char *)a.data(), r * c * 16);
}

int SocketOnline::recv_message_int()
{
    recv_message_n(sock, buffer, 4);
    char *p = buffer;
    int ret = Constant::Util::char_to_int(p);
    return ret;
}

void SocketOnline::push(const Matrixint64 &a) {}

void SocketOnline::print()
{
    DBGprint("socket online\n");
}

// void SocketOnline::test() {
//     Matrixint64 x;
//     cout << "test" <<endl;
// }

// int main(int argc, char** argv) {
//     SocketOnline::test();
// }