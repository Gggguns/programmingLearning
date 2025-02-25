#include <iostream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include "Terminal.hpp"

const int size = 1024;

void Usage(std::string proc)
{
    std::cout << "\n\rUsage: " << proc << " serverip serverport\n" << std::endl;
}

struct ThreadData
{
    struct sockaddr_in server;
    int socketfd;
    std::string serverip;
};

void *recv_message(void *args)
{
    //OpenTerminal();
    ThreadData *td = static_cast<ThreadData*>(args);
    char inbuffer[size];
    while(true)
    {
        struct sockaddr_in temp;
        socklen_t len = sizeof(temp);
        
        ssize_t n = recvfrom(td->socketfd, inbuffer, sizeof(inbuffer) - 1, 0, (struct sockaddr *)&temp, &len);
        if(n > 0)
        {
            inbuffer[n] = 0;
            std::cerr << inbuffer << std::endl;
        }
    }
}

void *send_message(void *args)
{
    ThreadData *td = static_cast<ThreadData*>(args);
    socklen_t len = sizeof(td->server);

    std::string welcome = td->serverip;
    welcome += " coming...";
    sendto(td->socketfd, welcome.c_str(), welcome.size(), 0, (struct sockaddr *)&(td->server), len);

    std::string message;
    while(true)
    {
        message.clear();
        std::cout << "Please Enter@ ";
        getline(std::cin, message);
        sendto(td->socketfd, message.c_str(), message.size(), 0, (struct sockaddr *)&(td->server), len);
    }
}

// 多线程
// ./udpclient serverip serverport
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(0);
    }
    std::string serverip = argv[1];
    uint16_t serverport = std::stoi(argv[2]);

    struct ThreadData td;
    // 创建套接字
    td.socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(td.socketfd < 0)
    {
        std::cout << "socket error" << std::endl;
        return 1;
    }

    bzero(&(td.server), sizeof(td.server));
    td.server.sin_family = AF_INET;
    td.server.sin_port = htons(serverport);
    td.server.sin_addr.s_addr = inet_addr(serverip.c_str());

    td.serverip = serverip;

    pthread_t recvr, sender;
    pthread_create(&recvr, nullptr, recv_message, &td);
    pthread_create(&sender, nullptr, send_message, &td);

    pthread_join(recvr, nullptr);
    pthread_join(sender, nullptr);
    
    close(td.socketfd);
    return 0;
}