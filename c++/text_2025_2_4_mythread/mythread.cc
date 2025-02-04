#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include "LockGuard.hpp"
using namespace std;
#define NUM 3

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int tickets = 1000; // 多线程模拟一轮抢票票

class ThreadData
{
public:
    ThreadData(int number/*, pthread_mutex_t *mutex*/)
    {
        threadname = "thread-" + to_string(number);
        // lock = mutex;
    }

    string threadname;
    // pthread_mutex_t *lock;
};

void *getTicket(void *args)
{
    ThreadData *td = static_cast<ThreadData*>(args);
    const char *name = td->threadname.c_str();
    while(true)
    {
        // pthread_mutex_lock(td->lock); // 申请成功，才能往后执行，不成功，阻塞等待！
        // pthread_mutex_lock(&lock); // 申请成功，才能往后执行，不成功，阻塞等待！
        {
            LockGuard lockguard(&lock); // 临时的LockGuard对象，RAII风格的锁！
            if(tickets > 0)
            {
                usleep(1000);
                printf("who=%s, get a ticket: %d\n", name, tickets);
                tickets--;
                // pthread_mutex_unlock(td->lock);
                pthread_mutex_unlock(&lock);
            }
            else
            {
                // pthread_mutex_unlock(td->lock);
                pthread_mutex_unlock(&lock);
                break;
            }
        }
        usleep(13); // 我们抢到了票，我们会立马抢下一张吗？其实多线程还要执行得到票之后的后续动作，usleep模拟
    }

    printf("%s ... quit\n", name);
    return nullptr;
}

int main()
{
    // pthread_mutex_t lock;
    // pthread_mutex_init(&lock, nullptr);// 第二个参数是所得属性，直接设为nullptr

    vector<pthread_t> tids;
    vector<ThreadData*> thread_datas;
    for(int i = 1; i <= NUM; i++)
    {
        pthread_t tid;
        ThreadData* td = new ThreadData(i/*, &lock*/);
        thread_datas.push_back(td);

        pthread_create(&tid, nullptr, getTicket, thread_datas[i-1]);
        tids.push_back(tid);
    }

    //等待线程
    for(auto tid : tids)
    {
        pthread_join(tid, nullptr);
    }

    for(auto td : thread_datas)
    {
        delete td;
    }

    // pthread_mutex_destroy(&lock);
    return 0;
}

