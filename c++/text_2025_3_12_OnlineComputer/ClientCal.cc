#include <iostream>
#include <string>
#include <assert.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "Protocol.hpp"
#include "Socket.hpp"

static void Usage(const std::string &proc)
{
    std::cout << "\nUsage: " << proc << " serverip serverport\n" << std::endl;
}

// ./clientcal ip port
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(0);
    }

    std::string serverip = argv[1];
    uint16_t serverport = std::stoi(argv[2]);

    Sock sockfd;
    sockfd.Socket();
    bool r = sockfd.Connect(serverip, serverport);
    if(!r) return 1;

    srand(time(nullptr)^getpid());
    int cnt = 1;
    const std::string opers = "+-*/%=-=&^";

    std::string inbuffer_stream;
    while(cnt <= 20)
    {
        std::cout << "===============第" << cnt << "次测试......" << "==========" << std::endl;
        int x = rand() % 100 + 1;
        usleep(1234);
        int y = rand() % 100;
        usleep(1234);
        char oper = opers[rand()%opers.size()];
        Request req(x, y, oper);
        req.DebugPrint();

        std::string package;
        req.Serialize(&package);

        package = Encode(package);

        std::cout << "这是最新发出的请求: \n" << package;
        write(sockfd.Fd(), package.c_str(), package.size());

        char buffer[128];
        ssize_t n = read(sockfd.Fd(), buffer, sizeof(buffer)); // 我们也无法保证我们就读到一个完整的报文
        if(n > 0)
        {
            buffer[n] = 0;
            inbuffer_stream += buffer; // "len"\n"result code"\n
            std::string content;
            bool r = Decode(inbuffer_stream, &content); // "result code"
            assert(r);

            Response resp;
            r = resp.Deserialize(content);
            assert(r);

            resp.DebugPrint();
        }
        std::cout << "============================================" << std::endl;
        sleep(1);
        cnt++;
    }
    sockfd.Close();
    
    return 0;
}