#include <vector>
#include "UDPServer.hpp"

void Usage(std::string proc)
{
    std::cout << "\n\rUsage: " << proc << " port[1024+]\n" << std::endl;
}

bool SafeCheck(const std::string &cmd)
{
    bool safe = false;
    std::vector<std::string> key_word = {
        "rm",
        "mv",
        "cp",
        "kill",
        "sudo",
        "unlink",
        "uninstall",
        "yum",
        "top",
    };
    for(const auto &word : key_word)
    {
        auto pos = cmd.find(word);
        if(pos != std::string::npos)return false;
    }

    return true;
}

std::string Handler(const std::string &info, const std::string &clientip, uint16_t clientport)
{
    std::cout << "[" << clientip << ":" << clientport << "]# " << info << std::endl;
    std::string res = "Server get a message: ";
    res += info;
    std::cout << res << std::endl;
    return res;
}

std::string ExcuteCommand(const std::string &cmd)
{
    std::cout << "get a request  cmd: " << cmd << std::endl;
    if(!SafeCheck(cmd)) return "Bad man!";
    FILE *fp = popen(cmd.c_str(), "r");
    if(fp == nullptr)
    {
        perror("popen");
        return "error";
    }
    std::string result;
    char buffer[4096];
    while(true)
    {
        char *ok = fgets(buffer, sizeof(buffer), fp);
        if(ok == nullptr)break;
        result += ok;
    }
    pclose(fp);
    return result;
}

// ./udpserver port
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    uint16_t port = std::stoi(argv[1]);
    
    std::unique_ptr<UdpServer> svr(new UdpServer(9002));

    svr->Init();
    svr->Run();

    return 0;
}