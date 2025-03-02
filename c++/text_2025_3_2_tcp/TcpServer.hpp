#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include "Daemon.hpp"
#include "ThreadPool.hpp"
#include "Task.hpp"
#include "Log.hpp"

const int defaultfd = -1;
const uint16_t defaultport = 8080;
const std::string defaultip = "0.0.0.0";
const int backlog = 10; // 但是一般不要太大

enum{
    UsageError = 1,
    SocketError,
    BindError,
    ListenError,
};

class TcpServer;

class ThreadData
{
public:
    ThreadData(int fd, const std::string &ip, const uint16_t &port, TcpServer *t):socketfd(fd), clientip(ip), clientport(port), tsvr(t)
    {}
public:
    int socketfd;
    std::string clientip;
    uint16_t clientport;
    TcpServer *tsvr;
};

class TcpServer
{
public:
    TcpServer(const uint16_t &port = defaultport, const std::string &ip = defaultip):listensock_(defaultfd), port_(port), ip_(ip)
    {}
    void Init()
    {
        // socket create
        listensock_ = socket(AF_INET, SOCK_STREAM, 0);
        if( listensock_ < 0)
        {
            lg(Fatal, "socket create error, errno: %d, errstring: %s", errno, strerror(errno));
            exit(SocketError);
        }
        lg(Info, "create socket success, listensock_: %d", listensock_);

        int opt = 1;
        setsockopt(listensock_, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &opt, sizeof(opt));// 防止偶然性的服务器无法进行立即重启

        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port_);
        inet_aton(ip_.c_str(), &(local.sin_addr));
        socklen_t len = sizeof(local);

        // bind socket
        if(bind(listensock_, (struct sockaddr *)&local, len) < 0)
        {
            lg(Fatal, "bind error, errno: %, errstring: %s", errno, strerror(errno));
            exit(BindError);
        }

        // listen
        if(listen(listensock_, backlog) < 0)
        {
            lg(Fatal, "listen error, errno: %d, errstring: %s", errno, strerror(errno));
            exit(ListenError);
        }
        lg(Info, "listen socket success, socketfd: %d", listensock_);

    }
    // static void *Routine(void *args)
    // {
    //     pthread_detach(pthread_self());
    //     ThreadData *td = static_cast<ThreadData *>(args);
    //     td->tsvr->Service(td->socketfd, td->clientip, td->clientport);
    //     delete td;
    //     return nullptr;
    // }
    void Start()
    {
        Daemon();
        signal(SIGPIPE, SIG_IGN);
        ThreadPool<Task>::GetInstance()->Start();
        lg(Info, "tcpServer is running....");
        while(true)
        {
            // 1. 获取新连接
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            int socketfd = accept(listensock_, (struct sockaddr *)&client, &len);
            if(socketfd < 0)
            {
                lg(Warning, "accept error, errno: %d, errstring: %s", errno, strerror(errno));
                continue;
            }
            uint16_t clientport = ntohs(client.sin_port);
            char clientip[32];
            inet_ntop(AF_INET, &(client.sin_addr), clientip, sizeof(clientip));

            // 2. 根据新连接来进行通信
            lg(Info, "get a new link..., sockfd: %d, client ip: %s, client port: %d", socketfd, clientip, clientport);
            // version 1 -- 单进程版
            // Service(socketfd, clientip, clientport);
            // close(socketfd);

            // version 2 -- 多进程版
            // pid_t id = fork();
            // if(id == 0)
            // {
            //     close(listensock_);
            //     pid_t pid = fork();
            //     if(pid > 0) exit(0);
            //     Service(socketfd, clientip, clientport); // 孙子进程
            //     close(socketfd);
            //     exit(0);
            // }
            // close(socketfd);
            // // father
            // pid_t rid = waitpid(id, nullptr, 0);
            // (void)rid;

            // version 3 -- 多线程版本
            // ThreadData *td = new ThreadData(socketfd, clientip, clientport, this);
            // pthread_t tid;
            // pthread_create(&tid, nullptr, Routine, td);

            // version 4 -- 线程池版本
            Task t(socketfd, clientip, clientport);
            ThreadPool<Task>::GetInstance()->Push(t);
        }
    }
    void Service(int socketfd, const std::string &clientip, const uint16_t &clientport)
    {
        // 测试代码
        char buffer[4096];
        while(true)
        {
            ssize_t n = read(socketfd, buffer, sizeof(buffer) - 1);
            if(n > 0)
            {
                buffer[n] = 0;
                std::cout << "client say# " << buffer;
                std::string echo_string = "tcpserver echo# ";
                echo_string += buffer;

                n = write(socketfd, echo_string.c_str(), echo_string.size()); // 100 fd 不在
                if(n < 0)
                {
                    lg(Warning, "write error, errno: %d, errstring: %s", errno, strerror(errno));
                }
            }
            else if(n == 0)
            {
                lg(Info, "%s:%d quit, server close socketfd: %d", clientip.c_str(), clientport, socketfd);
                break;
            }
            else
            {
                lg(Warning, "read error, socketfd: %d, client ip: %s, client port: %d", socketfd, clientip.c_str(), clientport);
                break;
            }
        }
    }
    ~TcpServer()
    {}
private:
    int listensock_;
    uint16_t port_;
    std::string ip_;
};