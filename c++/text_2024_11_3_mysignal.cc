#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

void PrintPending(sigset_t& pending)
{
    //没有0号，不打印第0位
    //逆向打印，先打印第31号
    for(int signo = 31;signo >= 1;signo--)
    {
        if(sigismember(&pending, signo))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n\n";
}

int main()
{
    //4. 我可以将所有的信号都进行屏蔽，信号不就不会被处理了吗？ 肯定的，但9号肯定不能被屏蔽
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    for(int signo = 1;signo <= 31; signo++)
    {
        sigaddset(&bset, signo);//屏蔽所有信号了吗？
    }
    sigprocmask(SIG_BLOCK, &bset, &oset);

    sigset_t pending;
    while(true)
    {
        //2.1获取
        int n = sigpending(&pending);
        if(n < 0)continue;
        //2.2打印
        PrintPending(pending);
        sleep(1);
    }





    // //1.1 先对2号信号进行屏蔽--数据预备
    // sigset_t bset, oset;//在哪开辟的空间？？ 用户栈上的，属于用户区
    // sigemptyset(&bset); // 先全部置0，初始化
    // sigemptyset(&oset);// 初始化
    // sigaddset(&bset, 2);// 我们已经把2号信号屏蔽了吗？并没有设置进入到你进程中的task_struct

    // //1.2 调用系统调用，将数据设置进内核
    // sigprocmask(SIG_BLOCK, &bset, &oset);// 我们已经把2号信号屏蔽了吗？屏蔽了

    // //2 重复打印当前进程的pending 0000000000000000000000000000000
    // sigset_t pending;
    // int cnt = 0;
    // while(true)
    // {
    //     //2.1 获取
    //     int n = sigpending(&pending);
    //     if(n < 0)continue;
    //     //2.2 打印
    //     PrintPending(pending);
    //     //休眠1秒
    //     sleep(1);
    //     cnt++;
    //     //2.3 解除阻塞
    //     if(cnt == 20)
    //     {
    //         cout << "unblock 2 signo" << endl;
    //         sigprocmask(SIG_SETMASK, &oset, nullptr);//我们已经把2号信号屏蔽解除了吗？解除了
    //     }
    // }
    // //3 发送2号信号 0000000000000000000000000000010




    // //捕捉2号信号，做忽略处理
    // signal(2, SIG_IGN);

    // while(true)
    // {
    //     cout << "hello signal" << endl;
    //     sleep(1);
    // }
    return 0;
}