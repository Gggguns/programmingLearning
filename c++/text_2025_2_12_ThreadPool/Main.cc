#include <ctime>
#include "ThreadPool.hpp"
#include "Task.hpp"

int main()
{
    ThreadPool<Task> *tp = new ThreadPool<Task>(20);
    tp->Start();
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
        tp->Push(t);
        // 2. 交给线程池处理
        std::cout << "main thread make task: " << t.GetTask() << std::endl;

        sleep(1);
    }
    return 0;
}