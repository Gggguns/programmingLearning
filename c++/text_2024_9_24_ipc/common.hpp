#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#define FIFO_FILE "./myfifo" // 创建管道的路径
#define MODE 0664            // 管道创建的初始权限



// 枚举出错码
enum
{
    FIFO_CREATE_ERR = 1,
    FIFO_DELETE_ERR,
    FIFO_OPEN_ERR
};

class Init
{
public:
    // 创建管道
    Init()
    {
        int n = mkfifo(FIFO_FILE, MODE);
        if (n == -1)
        {
            perror("mkfifo");
            exit(FIFO_CREATE_ERR);
        }
    }
    // 删除管道
    ~Init()
    {
        int m = unlink(FIFO_FILE);
        if (m == -1)
        {
            perror("unlink");
            exit(FIFO_DELETE_ERR);
        }
    }
};