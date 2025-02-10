#include "BlockQueue.hpp"
#include "Task.hpp"
#include <ctime>
void *Consumer(void *args)
{
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task>*>(args);

    while(true)
    {
        // 消费
        Task t = bq->pop();

        // 计算
        t();
        std::cout << "处理任务：" << t.GetTask() << " 运算结果是：" << t.GetResult() << " thread id: " << pthread_self() << std::endl;
    }
}

void *Productor(void *args)
{
    int len = opers.size();
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task>*>(args);

    while(true)
    {

        // 模拟生产者生产数据
        int data1 = rand() % 10; // [0,9]
        usleep(10);
        int data2 = rand() % 10;
        char op = opers[rand() % len];
        Task t(data1, data2, op);

        // 生产
        bq->push(t);
        std::cout << "生产了一个任务：" << t.GetTask() << " thread id: " << pthread_self() << std::endl;
    }
}

int main()
{
    srand(time(nullptr));
    BlockQueue<Task> *bq = new BlockQueue<Task>();
    int threadNum = 3;
    pthread_t c[threadNum], p[threadNum];
    
    // 创建线程
    for(int i = 0; i < threadNum; i++)
    {
        pthread_create(c + i, nullptr, Consumer, bq); // 消费者
    }

    for(int i = 0; i < threadNum; i++)
    {
        pthread_create(p + i, nullptr, Productor, bq); // 生产者
    }
    
    // 等待线程
    for(int i = 0; i < threadNum; i++)
    {
        pthread_join(c[i], nullptr);
    }
    for(int i = 0; i < threadNum; i++)
    {
        pthread_join(p[i], nullptr);
    }
    delete(bq);

    return 0;
}