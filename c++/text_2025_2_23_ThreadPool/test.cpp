#include <iostream>
#include <unistd.h>
#include <ctime>
#include "ThreadPool.hpp"
#include "Task.hpp"

int main()
{
    std::cout << "process running ..." << std::endl;
    ThreadPool<Task>::GetInstance()->Start();
    srand(time(nullptr)^getpid());
    int len = opers.size();

    while(true)
    {
        // 1. 构建任务
        int data1 = rand() % 10 + 1;
        usleep(10);
        int data2 = rand() % 10;
        char op = opers[rand()%len];

        Task t(data1, data2, op);
        ThreadPool<Task>::GetInstance()->Push(t);
        // 2. 交给线程池处理
        std::cout << "main thread make task: " << t.GetTask() << std::endl;

        sleep(1);
    }
    return 0;
}

// class Init
// {
// public:
//     Init()
//     {
//         std::cout << "hello world!" << std::endl;
//     }  
// };

// Init t;

// int main()
// {
//     int cnt = 3;
//     while(cnt > 0)\
//     {
//         std::cout << "Countdown: " << cnt << std::endl;
//         cnt--;
//     }
//     return 0;
// }