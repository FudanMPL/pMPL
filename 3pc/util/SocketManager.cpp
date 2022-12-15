
#include "SocketManager.h"

SocketOnline *socket_io[M][M];

void SocketManager::init_windows_socket()
{
#ifdef UNIX_PLATFORM
#else
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}

void SocketManager::exit_windows_socket()
{
#ifdef UNIX_PLATFORM
#else
    WSACleanup();
#endif
}

void SocketManager::server_init(SOCK &serv_sock, string ip, int port)
{
#ifdef UNIX_PLATFORM
    serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr));          //每个字节都用0填充
    serv_addr.sin_family = AF_INET;                    //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str()); //具体的IP地址
    serv_addr.sin_port = htons(port);                  //端口
    int opt = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));
#ifdef MAC_OS
    ::bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
#else

    bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
#endif
    listen(serv_sock, 20);
#else
    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr)); //每个字节都用0填充
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str()); //具体的IP地址
    serv_addr.sin_port = htons(port);                  //端口

    bind(serv_sock, (SOCKADDR *)&serv_addr, sizeof(serv_addr));

    listen(serv_sock, 20);
#endif
}

void SocketManager::client_init(SOCK &sock, string ip, int port)
{
#ifdef UNIX_PLATFORM
    sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr));          //每个字节都用0填充
    serv_addr.sin_family = AF_INET;                    //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str()); //具体的IP地址
    serv_addr.sin_port = htons(port);                  //端口

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
#else
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr)); //每个字节都用0填充
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str()); //具体的IP地址
    serv_addr.sin_port = htons(port);                  //端口

    connect(sock, (SOCKADDR *)&serv_addr, sizeof(serv_addr));
#endif
}

void SocketManager::socket_close(SOCK sock)
{
#ifdef UNIX_PLATFORM
    close(sock);
#else
    closesocket(sock);
#endif
}

SOCK SocketManager::accept_sock(SOCK serv_sock)
{
    SOCK ret;
#ifdef UNIX_PLATFORM
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    ret = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
#else
    SOCKADDR clnt_addr;
    int nSize = sizeof(SOCKADDR);
    ret = accept(serv_sock, (SOCKADDR *)&clnt_addr, &nSize);
#endif
    DBGprint("accept\n");
    return ret;
}

void SocketManager::print_socket()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i != j)
            {
                // DBGprint("socket %d %d:\n");
                socket_io[i][j]->SocketOnline::print();
            }
        }
    }
}

void SocketManager::print()
{
    ll tot_send = 0, tot_recv = 0;
    for (int i = 0; i < M; i++)
    {
        if (party != i)
        {
            tot_send += socket_io[party][i]->send_num;
            tot_recv += socket_io[party][i]->recv_num;
        }
    }
    DBGprint("tot_send: %lld tot_recv: %lld\n", tot_send, tot_recv);
}

SocketManager::pMPL::pMPL() {}

void SocketManager::pMPL::init()
{
    // init("127.0.0.1", 1234);
    string ip[M] = {"127.0.0.1", "127.0.0.1", "127.0.0.1", "127.0.0.1"}; 
    int port[M] = {12000, 12001, 12002, 12003};
    init(ip, port);
}

void SocketManager::pMPL::init(string *ip, int *port)
{
    this->ip = ip;
    this->port = port;
    init_windows_socket();
    server();
    client();
}

void SocketManager::pMPL::server()
{
    server_init(serv_sock, *(ip + party), *(port + party));
    char buffer[101];
    for (int i = party + 1; i < M; i++)
    {
        sock = accept_sock(serv_sock);
#ifdef UNIX_PLATFORM
        read(sock, buffer, 1);
#else
        recv(sock, buffer, 1, NULL);
#endif
        printf("Message form client %d: %c\n", buffer[0] - '0', buffer[0]);
        socket_io[party][buffer[0] - '0'] = new SocketOnline(buffer[0] - '0', sock);
        clnt_sock[buffer[0] - '0'] = sock;
    }
}

void SocketManager::pMPL::client()
{
    //    printf(" asdasd %d\n", port);
    for (int i = 0; i < party; i++)
    {
        client_init(sock, *(ip + i), *(port + i));
        //        printf("client %d connect to server %d\n", party, i);
        //        printf(" port %d\n", port);

        char str[] = "0";
        str[0] += party;
//        printf("str: %s %d\n", str, strlen(str));
#ifdef UNIX_PLATFORM
        write(sock, str, strlen(str));
#else
        send(sock, str, strlen(str), NULL);
#endif
        socket_io[party][i] = new SocketOnline(i, sock);
        clnt_sock[i] = sock;
    }
}

void SocketManager::pMPL::server_exit()
{
    socket_close(serv_sock);
    exit_windows_socket();
}

void SocketManager::pMPL::client_exit()
{
    for (int i = 0; i < M; i++)
    {
        if (i != party)
        {
            socket_close(clnt_sock[i]);
        }
    }
    exit_windows_socket();
}

void SocketManager::pMPL::exit_all()
{
    server_exit();
    client_exit();
}

void SocketManager::pMPL::send(MatrixXu *a, int target)
{
    socket_io[party][target]->send_message(a);
}

void SocketManager::pMPL::send(Matrix8 *a, int target)
{
    socket_io[party][target]->send_message(a);
}

void SocketManager::pMPL::send(Matrixint128 *a, int target)
{
    socket_io[party][target]->send_message(a);
}

void SocketManager::pMPL::receive(MatrixXu *a, int from)
{
    socket_io[party][from]->recv_message(*a);
}

void SocketManager::pMPL::receive(Matrix8 *a, int from)
{
    socket_io[party][from]->recv_message(*a);
}

void SocketManager::pMPL::receive(Matrixint128 *a, int from)
{
    socket_io[party][from]->recv_message(*a);
}