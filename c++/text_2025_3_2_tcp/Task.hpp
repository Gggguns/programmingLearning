#pragma once
#include <iostream>
#include <unistd.h>
#include "Init.hpp"
#include "Log.hpp"

Init init;

class Task
{
public:
    Task(int socketfd, const std::string &clientip, const uint16_t &clientport)
        : socketfd_(socketfd), clientip_(clientip), clientport_(clientport)
    {
    }
    Task()
    {
    }
    void run()
    {
        // 测试代码
        char buffer[4096];
        ssize_t n = read(socketfd_, buffer, sizeof(buffer) - 1);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "client key# " << buffer;
            std::string echo_string = init.translation(buffer);

            n = write(socketfd_, echo_string.c_str(), echo_string.size()); // 100 fd 不存在
            if (n < 0)
            {
                lg(Warning, "write error, errno: %d, errstring: %s", errno, strerror(errno));
            }
        }
        else if (n == 0)
        {
            lg(Info, "%s:%d quit, server close socketfd: %d", clientip_.c_str(), clientport_, socketfd_);
        }
        else
        {
            lg(Warning, "read error, socketfd: %d, client ip: %s, client port: %d", socketfd_, clientip_.c_str(), clientport_);
        }
        close(socketfd_);
    }

    void operator()()
    {
        run();
    }

    ~Task()
    {
    }

private:
    int socketfd_;
    std::string clientip_;
    uint16_t clientport_;
};