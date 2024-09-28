#ifndef _COMM_HPP
#define _COMM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "log.hpp"

using namespace std;

const int size = 4096;//这个最好是4096的整数倍
const string pathname = "/home/common_108";
const int proj_id = 0x6666;
Log log;


key_t GetKey()
{
    key_t k = ftok(pathname.c_str(), proj_id);
    if(k < 0)
    {
        log(Fatal, "ftok error: %s", strerror(errno));
        exit(1);
    }
    log(Info, "ftok success, key is: 0x%x", k);
    return k;
}

int GetShareMemHelper(int flag)
{
    key_t k = GetKey();
    int shmid = shmget(k, size, flag);
    if(shmid < 0)
    {
        log(Fatal,"create share memory error: %s", strerror(errno));
        exit(2);
    }

    log(Info, "create share memory success, shmid: %d", shmid);
    return shmid;
}

int CreateShm()
{
    return GetShareMemHelper(IPC_CREAT | IPC_EXCL | 0666);
}

int GetShm()
{
    return GetShareMemHelper(IPC_CREAT);
}

//管道
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


#endif