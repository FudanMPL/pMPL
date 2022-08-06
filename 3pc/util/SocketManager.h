
#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include "SocketOnline.h"

extern int party;
extern SocketOnline *socket_io[M][M];

class SocketManager
{
public:
    static void init_windows_socket();
    static void exit_windows_socket();
    static void server_init(SOCK &sock, string ip, int port);
    static void client_init(SOCK &sock, string ip, int port);
    static void socket_close(SOCK sock);
    static SOCK accept_sock(SOCK sock);
    static void print_socket();
    static void print();
    class pMPL
    {
        string *ip;
        int *port;
        SOCK serv_sock;
        SOCK clnt_sock[M];
        SOCK sock;
        int epoch;

    public:
        pMPL();
        void init();
        void init(string *ip, int *port);
        void server();
        void client();
        void server_exit();
        void client_exit();
        void exit_all();
        void send(MatrixXu *a, int target);
        void send(Matrix8 *a, int target);
        void send(Matrixint128 *a, int target);
        void receive(MatrixXu *a, int from);
        void receive(Matrix8 *a, int from);
        void receive(Matrixint128 *a, int from);
    };
};

#endif // SOCKETMANAGER_H
