#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

std::string toHex(pthread_t tid)
{
  char hex[64];
  snprintf(hex, sizeof(hex), "%p", tid);
  return hex;
}

void *threadRoutine(void *args)
{
  while(true)
  {
    cout << "new thread id: " << toHex(pthread_self()) << endl;
    sleep(1);
  }
  return nullptr;
}

int main()
{
  pthread_t tid;
  pthread_create(&tid, nullptr, threadRoutine, nullptr);
  cout << "main thread create new thread done, new thread id:  " << toHex(tid) << endl;

  pthread_join(tid, nullptr);
}

// void threadrun()
// {
//   while(true)
//   {
//     cout << "I am new thread for C++" << endl;
//     sleep(1);
//   }
// }

// int main()
// {
//   thread t1(threadrun);

//   t1.join();

//   return 0;
// }

// class Request
// {
// public:
//   Request(int start, int end, const string& threadname)
//   :start_(start),end_(end),threadname_(threadname)
//   {}
//   int start_;
//   int end_;
//   string threadname_;
// };

// class Response
// {
// public:
//   Response(int result, int exitcode)
//   :result_(result),exitcode_(exitcode)
//   {}
//   int result_; //计算结果
//   int exitcode_; //计算结果是否正确
// };

// //求和函数
// void* sumCount(void* args)
// {
//   Request* rq = static_cast<Request*>(args); // 相当于 rq = (Request*)args
//   Response* rsp = new Response(0, 0);
//   for(int i = rq->start_; i <= rq->end_; i++)
//   {
//     cout << rq->threadname_ << " is runing caling ..., " << i << endl;
//     rsp->result_ += i;
//     usleep(10000);
//   }
//   delete rq;
//   return rsp;
// }

// int main()
// {
//   pthread_t tid;
//   Request *rq = new Request(1, 100, "thread 1");
//   pthread_create(&tid, nullptr, sumCount, rq);

//   void* ret;
//   pthread_join(tid, &ret);
//   Response* rsp = static_cast<Response*>(ret);
//   cout << "rsp->result_: " << rsp->result_ << ", rsp->exitcode_: " << rsp->exitcode_ << endl;
//   delete rsp;
//   return 0;
// }



// int g_val = 0;

// //可以被多个执行流执行 show函数被冲入了哦！！
// void show(const string& name)
// {
//   cout << name << "say# hello thread" << endl;
// }

// //new thread
// void *threadRoutine(void *args)
// {
//   const char* name = (const char*) args; 
//   int cnt = 5;
//   while(true)
//   {
//     printf("%s: %d, g_val: %d, &g_val: %p\n", name, getpid(), g_val, &g_val);
//     // cout << "new thread pid: " << getpid() << endl;
//     //show("[new thread]");
//     cnt--;
//     sleep(1);
//     if(cnt == 0)break;
//   }
//   pthread_exit((void*)100);
//   // exit(11); // exit是用来终止进程的，不能用来终止线程
//   return (void*)1; // 走到这里，默认线程退出
// }

// int main()
// {
//   PTHREAD_CANCELED;
//   //创建线程
//   pthread_t tid;
//   // pthread_create(&tid, nullptr, threadRoutine, nullptr);
//   pthread_create(&tid, nullptr, threadRoutine, (void*)"thread 1");
//   sleep(1); //休息1秒，确保新线程被创建
//   pthread_cancel(tid);

//   // while(true)
//   // {
//   //   //tid是一个无符号长整数
//   //   printf("main thread pid: %d, g_val: %d, &g_val: %p, create new thread tid: %p\n", getpid(), g_val, &g_val, tid);
//   //   // cout << "main thread pid: " << getpid() << endl;
//   //   // show("[main thread]");
//   //   sleep(1);
//   //   g_val++;
//   // }

//   void *retval = nullptr;

//   //等待线程
//   pthread_join(tid, &retval); //main thread 等待的时候，默认是阻塞等待
//   cout << "main thread quit ..., ret: " << (long long int)retval << endl;

//   return 0;
// }

//计算指针大小
// int main()
// {
//   std::cout << sizeof(void*) << std::endl;
//   return 0;
// }
//fork测试
//int main()
//{
//  pid_t id = fork();
//  if(id == 0){
//    execl("/usr/bin/python3", "python3", "test.py", NULL);
//    exit(0);
//  }
//  pid_t ret = waitpid(id, NULL, 0);
//  if(ret > 0)printf("wait success, father pid: %d, ret id: %d\n", getpid(), ret);
//
//  return 0;
//}