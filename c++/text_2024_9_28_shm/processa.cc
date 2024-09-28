#include "common.hpp"

int main()
{
    //管道
    Init init;
    //建立共享内存
    int shmid = CreateShm();
    log(Debug, "create shm done");

    //sleep(5);

    //建立关联
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);
    log(Debug, "attach shm done, shmaddr: 0x%x", shmaddr);

    //打开管道
    int fd = open(FIFO_FILE, O_RDONLY);//等待写入方打开之后，自己才会打开文件，向后执行，open阻塞了
    if(fd < 0)
    {
        log(Fatal, "error string: %s, error code: %d\n", strerror(errno), errno);
        exit(FIFO_OPEN_ERR);
    }
    
    //开始通信
    //一旦有人把数据写入到共享内存，其实我们立马能看到了
    //不需要经过系统调用，直接就能看到数据了

    struct shmid_ds shmds;
    while(true)
    {
        char c;
        ssize_t s = read(fd, &c, sizeof(c));
        if(s == 0)break;
        else if(s < 0)break;

        cout << "client say@ " << shmaddr << endl;//直接访问共享内存
        sleep(1);

        shmctl(shmid, IPC_STAT, &shmds);
        cout << "shm size: " << shmds.shm_segsz << endl;//共享内存大小
        cout << "shm nattch: " << shmds.shm_nattch << endl;//关联数
        printf("shm _key: 0x%x\n", shmds.shm_perm.__key);//key
        cout << "shm mode: " << shmds.shm_perm.mode << endl;//权限
    }

    //去关联
    shmdt(shmaddr);
    log(Debug, "dettach shm done, shmaddr: 0x%x", shmaddr);

    //log(Debug, "processa quit....");

    //sleep(5);

    //释放共享内存
    shmctl(shmid, IPC_RMID, nullptr);
    log(Debug, "destory shm done, shmaddr: 0x%x", shmaddr);
    return 0;
}