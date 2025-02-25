#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <functional>
#include <stdlib.h>
#include "Log.hpp"

// 两种方式等价
// using func_t = std::function<std::string(const std::string &)>;
typedef std::function<std::string(const std::string &, const std::string &, uint16_t)> func_t;


Log lg;

enum{
    SOCKET_ERR = 1,
    BIND_ERR,
};

uint16_t defaultport = 8080;
std::string defaultip = "0.0.0.0";
const int size = 1024;

class UdpServer{
public:
    UdpServer(const uint16_t &port = defaultport, const std::string ip = defaultip):ip_(ip),port_(port),isrunning_(false)
    {}
    void Init()
    {
        // 创建套接字
        socketfd_ = socket(AF_INET, SOCK_DGRAM, 0); 
        if(socketfd_ < 0)
        {
            lg(Fatal, "socket create error, socketfd: %d", socketfd_);
            exit(SOCKET_ERR);
        }
        lg(Info, "socket create success, socketfd: %d", socketfd_);

        // 绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port_); 
        local.sin_addr.s_addr = INADDR_ANY;

        if(bind(socketfd_, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            lg(Fatal, "bind error, errno: %d, err string: %s", errno, strerror(errno));
            exit(BIND_ERR);
        }
        lg(Info, "bind success, errno: %d, err string: %s", errno, strerror(errno));

    }
    void CheckUser(const struct sockaddr_in &client, const std::string &clientip, uint16_t clientport)
    {
        auto iter = online_user_.find(clientip);
        if(iter == online_user_.end())
        {
            online_user_.insert({clientip,client});
            std::cout << "[" << clientip << ":" << clientport << "] add to online user." << std::endl;
        }
    }
    void Broadcast(const std::string &info, const std::string &clientip, uint16_t clientport)
    {
        std::string message;
        for(const auto &user : online_user_)
        {
            message.clear();
            message = "[";
            message += clientip;
            message += ":";
            message += std::to_string(clientport);
            message += "]# ";
            message += info;
            socklen_t len = sizeof(user.second);
            sendto(socketfd_, message.c_str(), message.size(), 0, (struct sockaddr*)(&user.second), len); 
        }
    }
    void Run()
    {
        isrunning_ = true;
        char inbuffer[size];
        while(isrunning_)
        {
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            ssize_t n= recvfrom(socketfd_, inbuffer, sizeof(inbuffer) - 1, 0, (struct sockaddr*)&client, &len);
            if(n < 0)
            {
                lg(Warning, "recvfrom error, errno: %d, err string: %s", errno, strerror(errno));
                continue;
            }

            uint16_t clientport = ntohs(client.sin_port);
            std::string clientip = inet_ntoa(client.sin_addr);//将ip转成字符串
            CheckUser(client, clientip, clientport);

            std::string info = inbuffer;
            Broadcast(info, clientip, clientport);
        }
    }
    ~UdpServer()
    {
        if(socketfd_ > 0)
        {
            close(socketfd_);
        }
    }
private:
    int socketfd_; // 网络文件描述符
    std::string ip_; // 任意地址，bind 0
    uint16_t port_; // 表明服务器进程的端口
    bool isrunning_;
    std::unordered_map<std::string, struct sockaddr_in> online_user_;
};