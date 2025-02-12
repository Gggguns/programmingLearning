#include <iostream>
#include <unistd.h>
#include <ctime>
#include <pthread.h>
#include "RingQueue.hpp"
#include "Task.hpp"


struct ThreadData
{
    RingQueue<Task> *rq;
    std::string threadname;
};

void *Consumer(void *args)
{
    ThreadData *td = static_cast<ThreadData*>(args);
    RingQueue<Task> *rq = td->rq;
    std::string name = td->threadname;
    
    while(true)
    {
        // 消费
        // 1. 消费数据
        Task t;
        rq->Pop(&t);

        // 2. 加工处理
        t();
        std::cout << "Consumer get a task, task is: " << t.GetTask() << " who: " << name << " result: " << t.GetResult() << std::endl;
        sleep(1);
    }

    return nullptr;
}

void *Productor(void *args)
{
    sleep(3);
    ThreadData *td = static_cast<ThreadData*>(args);
    RingQueue<Task> *rq = td->rq;
    std::string name = td->threadname;
    int len = opers.size();

    while(true)
    {
        // 生产
        // 1.获取数据
        int data1 = rand() % 10 + 1;
        usleep(100);
        int data2 = rand() % 10;

        char op = rand() % len;

        // 2.生产数据
        Task t(data1, data2, op);
        rq->Push(t);
        std::cout << "Productor task done, task is: " << t.GetTask() << " who: " << name << std::endl;

        sleep(1);
    }

    return nullptr;
}

int main()
{
    srand(time(nullptr)^getpid());
    RingQueue<Task> *rq = new RingQueue<Task>(50);
    

    // 生产消费
    pthread_t c[3], p[5];
    for(int i = 0; i < 3; i++)
    {
        ThreadData *td = new ThreadData();
        td->rq = rq;
        td->threadname = "Consumer-" + std::to_string(i);
        pthread_create(c + i, nullptr, Consumer, td);
    }
    for(int i = 0; i < 5; i++)
    {
        ThreadData *td = new ThreadData();
        td->rq = rq;
        td->threadname = "Productor-" + std::to_string(i);
        pthread_create(p + i, nullptr, Productor, td);
    }

    for(int i = 0; i < 3; i++)
    {
        pthread_join(c[i], nullptr);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_join(p[i], nullptr);
    }

    return 0;
}