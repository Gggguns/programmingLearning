#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <WinSock2.h>
#include <Windows.h>

#pragma warning(disable:4996)

#pragma comment(lib, "ws2_32.lib")

const int size = 1024;

std::string serverip = "47.243.13.193";
uint16_t serverport = 9002;

int main()
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);

    // ´´½¨Ì×½Ó×Ö
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd < 0)
    {
        std::cout << "socket error" << std::endl;
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());

    std::string message;
    char inbuffer[size];
    while (true)
    {
        std::cout << "Please Enter@ ";
        getline(std::cin, message);

        sendto(socketfd, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server));

        struct sockaddr_in temp;
        int len = sizeof(temp);

        size_t n = recvfrom(socketfd, inbuffer, sizeof(inbuffer) - 1, 0, (struct sockaddr*)&temp, &len);
        if (n > 0)
        {
            inbuffer[n] = 0;
            std::cout << inbuffer << std::endl;
        }

    }

    closesocket(socketfd);

	WSACleanup();
	return 0;
}