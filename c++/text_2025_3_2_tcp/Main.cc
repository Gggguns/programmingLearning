#include "TcpServer.hpp"

void Usage(const std::string &proc)
{
    std::cout << "\n\rUsage: " << proc << " port[1024+]\n" << std::endl;
}

//./tcpserver 9002
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(UsageError);
    }
    uint16_t port = std::stoi(argv[1]);
    std::unique_ptr<TcpServer> tcp_svr(new TcpServer(port));
    tcp_svr->Init();
    tcp_svr->Start();
    return 0;
}