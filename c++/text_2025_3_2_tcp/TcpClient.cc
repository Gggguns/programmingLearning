#include <iostream>
#include <string>
#include <memory>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void Usage(const std::string &proc)
{
    std::cout << "\n\rUsage: " << proc << " serverip serverport\n"
              << std::endl;
}

// ./tcpserver serverip serverport
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    uint16_t serverport = std::stoi(argv[2]);
    std::string serverip = argv[1];

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    inet_pton(AF_INET, serverip.c_str(), &(server.sin_addr));
    socklen_t len = sizeof(server);

    while (true)
    {
        int cnt = 20;
        bool isreconnect = false;
        // socket
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd < 0)
        {
            std::cerr << "socket error" << std::endl;
            return 1;
        }

        // 断线重连
        do
        {
            // tcp客户端要不要bind? 要 要不要显示bind呢？不要，系统进行bind，随机端口
            // 什么时候，bind? 客户端发起connect的时候，进行自动随机bind.
            int n = connect(socketfd, (struct sockaddr *)&server, len);
            if (n < 0)
            {
                isreconnect = true;
                cnt--;
                std::cerr << "connect error..., reconnect: " << cnt << std::endl;
                sleep(1);
            }
            else
            {
                break;
            }
        } while (cnt && isreconnect);

        if (cnt == 0)
        {
            std::cerr << "user offline..." << std::endl;
            break;
        }

        while(true)
        {
            std::string message;
            std::cout << "Please Enter@ ";
            std::getline(std::cin, message);

            int n = write(socketfd, message.c_str(), message.size());
            if (n < 0)
            {
                std::cerr << "write error..." << std::endl;
                break;
            }

            char inbuffer[4096];
            n = read(socketfd, inbuffer, sizeof(inbuffer) - 1);
            if (n > 0)
            {
                inbuffer[n] = 0;
                std::cout << inbuffer << std::endl;
            }
            else
            {
                break;
            }
        }

        close(socketfd);
    }

    return 0;
}