#include "common.hpp"
int main()
{
    //建立关联
    int shmid = GetShm();
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);

    //打开管道
    int fd = open(FIFO_FILE, O_WRONLY);//等待读方打开之后，自己才会打开文件，向后执行，open阻塞了！
    if(fd < 0)
    {
        printf("error string: %s, error code: %d\n", strerror(errno), errno);
        exit(FIFO_OPEN_ERR);
    }

    //一旦有共享内存，挂接到你的进程地址空间中，你直接把它当成自己的内存空间使用
    //不需要调用系统调用
    //ipc code
    while(true)
    {
        // char buffer[1024];
        // cout << "Please Enter@ ";
        // fgets(buffer, sizeof(buffer), stdin);
        // memcpy(shmaddr, buffer, strlen(buffer)+1);//我们希望它把buffer中的内容当成一个字符串，所以strlen+1
        cout << "Please Enter@ ";
        fgets(shmaddr, size, stdin);

        write(fd, "c", sizeof(char));//通知对方
    }

    //去关联
    shmdt(shmaddr);

    return 0;
}