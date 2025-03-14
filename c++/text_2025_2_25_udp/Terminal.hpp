#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

std::string terminal =  "/dev/pts/1";

int OpenTerminal()
{
    int fd = open(terminal.c_str(), O_WRONLY);
    if(fd < 0)
    {
        std::cerr << "open terminal error" << std::endl;
        return 1;
    }
    dup2(fd, 2);
    return 0;
}