#include <iostream>
#include <signal.h>
#include <cstring>
#include <ctime>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void handler(int signo)
{
    sleep(5);
    pid_t rid;
    //如果有就一直回收
    while( rid = waitpid(-1, nullptr, 0) > 0)
    {
        cout << "I am process: " << getpid() << ", catch a signo: " << signo << ", child process quit: " << rid << endl;
    }
}

int main()
{
    srand(time(nullptr));
    signal(17, SIG_IGN);

    //如果我们有10个子进程？如果同时退出呢？
    //如果退一半呢？
    for(int i = 0; i < 10; i++)
    {
        pid_t id = fork();
        if(id == 0)
        {
            while(true)
            {
                cout << "I am child process, pid: " << getpid() << ", ppid: " << getppid() << endl;
                sleep(10);
                break;
            }
            cout << "child quit!!!" << endl;
            exit(0);
        }
        sleep(rand()%5+3);
    }

    //father
    while(true)
    {
        cout << "I am father process, pid: " << getpid() << endl;
        sleep(1);
    }


    return 0;
}

// volatile int flag = 0;

// void handler(int signo)
// {
//     cout << "catch a signal, signal number: " << signo << endl;
//     flag = 1;
// }

// int main()
// {
//     signal(2, handler);

//     while(!flag);

//     cout << "process quit normal" << endl;

//     return 0;
// }

// void PrintPending()
// {
//     sigset_t pending;
//     sigpending(&pending);
//     cout << endl;
//     for(int signo = 1; signo <= 31; signo++)
//     {
//         if(sigismember(&pending, signo))cout << "1";
//         else cout << "0";
//    }
//     cout << endl;
// }

// void handler(int signo)
// {
//     cout << "catch a signal, signal number: " << signo << endl;
//     while(true)
//     {
//         PrintPending();
//         sleep(1);
//     }
// }

// int main()
// {
//     struct sigaction act, oact;
//     //初始化act, oact
//     memset(&act, 0, sizeof(act));
//     memset(&oact, 0, sizeof(oact));

//     //我们还想屏蔽1，3，4信号
//     sigemptyset(&act.sa_mask);
//     sigaddset(&act.sa_mask, 1);
//     sigaddset(&act.sa_mask, 3);
//     sigaddset(&act.sa_mask, 4);

//     //设置自定义
//     act.sa_handler = handler;
//     sigaction(2, &act, &oact);

//     while(true)
//     {
//         cout << "I am a proccess: " << getpid() << endl;
//         sleep(1);
//     }

//     return 0;
// }