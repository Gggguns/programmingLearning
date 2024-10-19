#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void Usage(string proc)
{
    cout << "Usage:\n\t" << proc << " signum pid\n\n";
}

//mykill signum pid
int main(int argc, char *argv[])
{
    //确认指令是否正确
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }

    int signum = stoi(argv[1]);
    pid_t pid = stoi(argv[2]);

    int n = kill(pid, signum);
    if(n == -1)
    {
        perror("kill");
        exit(2);
    }
    
    return 0;
}

// //int: 收到了哪一个信号
// void myhandler(int signo)
// {
//     //打印信号
//     cout << "process get a signal: " << signo << endl;

//     //退出程序
//     exit(1);
// }

// int main()
// {
//     //sleep(200);
//     signal(1, myhandler);
//     signal(2, myhandler);
//     signal(3, myhandler);
//     signal(4, myhandler);
//     signal(5, myhandler);
//     signal(6, myhandler);
//     signal(7, myhandler);

//     int cnt = 5;
//     //信号的产生和我们自己的代码的运行是异步的
//     while(true)
//     {
//         cout << "I am crazy process" << endl;
//         sleep(1);
//         cnt--;
//         // if(cnt == 0)
//         // {
//         //     cout << "cnt: " << cnt << endl;
//         //     // kill(getpid(), 2);
//         //     //raise(2);
//         //     abort();
//         // }
        
//     }
//     return 0;
// }