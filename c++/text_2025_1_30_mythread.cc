#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

#define NUM 3

int tickets = 1000; // 多线程模拟一轮抢票票

class ThreadData
{
public:
    ThreadData(int number)
    {
        threadname = "thread-" + to_string(number);
    }

    string threadname;
};

void *getTicket(void *args)
{
    ThreadData *td = static_cast<ThreadData*>(args);
    const char *name = td->threadname.c_str();
    while(true)
    {
        if(tickets > 0)
        {
            usleep(1000);
            printf("who=%s, get a ticket: %d\n", name, tickets);
            tickets--;
        }
        else
            break;
    }

    printf("%s ... quit\n", name);
    return nullptr;
}

int main()
{
    vector<pthread_t> tids;
    vector<ThreadData*> thread_datas;
    for(int i = 1; i <= NUM; i++)
    {
        pthread_t tid;
        ThreadData* td = new ThreadData(i);
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
    return 0;
}


// int *p = nullptr;
// __thread int g_val = 0;
// __thread pid_t pid = 0;
// __thread unsigned int number = 0;

// struct ThreadData
// {
//     string threadname;
// };

// string toHex(pthread_t tid)
// {
//     char buffer[128];
//     snprintf(buffer, sizeof(buffer), "0x%x", tid);
//     return buffer;
// }

// void InitThreadData(ThreadData *td, int number)
// {
//     td->threadname = "thread-" + to_string(number);
// }

// void *threadRoutine(void *args)
// {
//     pthread_detach(pthread_self());
//     int test_i = 0;
//     ThreadData* td = static_cast<ThreadData*>(args);
//     if(td->threadname == "thread-2")p = &test_i;
//     number = pthread_self();
//     pid = getpid();

//     int i = 0;
//     while(i < 10)
//     {
//         // cout << "pid: " << getpid() << ", tid: " 
//         //         << toHex(pthread_self()) << ", threadname: " << td->threadname 
//         //         << ", test_i: " << test_i << ", &test_i: " << &test_i << endl;
//         cout << "pid: " << pid << ", tid: " 
//                 << toHex(number) << ", threadname: " << td->threadname 
//                 << ", g_val: " << g_val << ", &g_val: " << &g_val << endl;
//         sleep(1);
//         i++; g_val++;
//         //test_i++;
//     }

//     delete td;
//     return nullptr;
// }

// int main()
// {
//     vector<pthread_t> tids;
//     for(int i = 0; i < NUM; i++)
//     {
//         pthread_t tid;
//         //这里能不能采用 ThreadData td这种写法？ 不能，因为这种写法出了for循环，td就被销毁了
//         ThreadData* td = new ThreadData;
//         InitThreadData(td, i);

//         pthread_create(&tid, nullptr, threadRoutine, td);
//         tids.push_back(tid);
//         sleep(1);
//     }

//     // sleep(1);//确保拷贝成功
//     // cout << "main thread get a thread local value, val: " << *p << ", &val: " << p << endl;

//     // for(int i = 0; i < NUM; i++)
//     // {
//     //     pthread_detach(tids[i]);
//     // }

//     for(int i = 0; i < NUM; i++)
//     {
//         // 这里加个返回值输出，验证相应的线程是否分离了
//         int n = pthread_join(tids[i], nullptr);
//         printf("n = %d, who = 0x%x, why: %s\n", n, tids[i], strerror(n));
//     }

//     return 0;
// }