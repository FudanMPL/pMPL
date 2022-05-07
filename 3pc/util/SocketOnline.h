
#ifndef SOCKETONLINE_H
#define SOCKETONLINE_H

#include "Mat.h"

#ifdef UNIX_PLATFORM
typedef int SOCK;
#else
typedef SOCKET SOCK;
#endif

class SocketOnline
{
public:
    int id;
    SOCK sock;
    char *buffer;
    char *header;
    ll send_num;
    ll recv_num;
    SocketOnline();
    ~SocketOnline();
    static void test();
    SocketOnline(int id, SOCK sock);
    SocketOnline &operator=(const SocketOnline &u);
    void init(int id, SOCK sock);
    void init();
    void reset();
    int send_message(SOCK sock, char *p, int l);
    int send_message_n(SOCK sock, char *p, int l);
    int recv_message(SOCK sock, char *p, int l);
    int recv_message_n(SOCK sock, char *p, int l);
    void send_message(Matrixint64 &a);
    void send_message(Matrix8 &a);
    void send_message(Matrixint128 &a);
    void send_message(Matrixint64 *a);
    void send_message(Matrix8 *a);
    void send_message(Matrixint128 *a);
    void send_message(int b);
    Matrixint64 recv_message();
    void recv_message(Matrixint64 &a);
    void recv_message(Matrix8 &a);
    void recv_message(Matrixint128 &a);
    int recv_message_int();
    void push(const Matrixint64 &a);
    void print();
};

#endif // SOCKETONLINE_H
