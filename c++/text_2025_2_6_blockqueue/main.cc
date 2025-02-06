#include "BlockQueue.hpp"
#include "Task.hpp"
void *Consumer(void *args)
{
    // BlockQueue<int> *bq = static_cast<BlockQueue<int>*>(args);
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task>*>(args);

    while(true)
    {
        // 消费
        // sleep(2);
        // int data = bq->pop();
        // std::cout << "消费了一个数据: " << data << std::endl;
        Task t = bq->pop();
        t.run();
    }
}

void *Productor(void *args)
{
    // BlockQueue<int> *bq = static_cast<BlockQueue<int>*>(args);
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task>*>(args);
    // int data = 0;
    int x = 10;
    int y = 20;
    while(true)
    {    
        // 生产
        // sleep(2);
        // data++;
        // bq->push(data);
        // std::cout << "生产了一个数据：" << data << std::endl;
        Task t(x++, y++);
        bq->push(t);
        std::cout << "生产了一个任务!" << std::endl;
    }
}

int main()
{
    // BlockQueue<int> *bq = new BlockQueue<int>();
    BlockQueue<Task> *bq = new BlockQueue<Task>();
    pthread_t c, p;
    pthread_create(&c, nullptr, Consumer, bq); // 消费者
    pthread_create(&p, nullptr, Productor, bq); // 生产者

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);
    delete(bq);

    return 0;
}