#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

int main()
{
    int a = 10;
    int b = 0;
    a /= b;
    cout << "a = " << a << endl;
    return 0;
}

// int main()
// {
//     pid_t id = fork();
//     if(id == 0)
//     {
//         //child
//         int cnt = 500;
//         while(cnt)
//         {
//             cout << "i am a child  process, pid: " << getpid() << " cnt: " << cnt << endl;
//             sleep(1);
//             cnt--;
//         }
//         exit(0);
//     }
    
//     //father
//     int status = 0;
//     pid_t rid = waitpid(id, &status, 0);
//     if(rid == id)
//     {
//         cout << "child quit info, rid: " << rid << " exit code: " <<
//             ((status>>8)&0xFF) << " exit signal: " << (status&0x7F) << " core dump: " << ((status>>7)&1) << endl;
//     }
//     return 0;
// }

// void handler(int signo)
// {
//     cout << "...get a sig, number: " << signo << endl;
//     int n = alarm(5);
//     cout << "剩余时间: " << n << endl;
// }

// int main()
// {
//     signal(14, handler);
//     //定一个5秒的闹钟
//     alarm(50);
//     while(true)
//     {
//         cout << "proc is running, pid: " << getpid() << endl;
//         sleep(1);
//     }
//     return 0;
// }

// int main()
// {
//     char buffer[1024];
//     int n = 1024;
//     n = read(4, buffer, n);//从4号文件描述符，读取内容
//     printf("n=%d\n", n);
//     return 0;
// }

// //信号为什么会一直触发？
// void myhandler(int signo)
// {
//     cout << "get a sig, number: " << signo << endl;//我什么都没干，只是打印信息
// }

// int main()
// {
//     signal(11, myhandler);
//     //野指针
//     cout << "point error before" << endl;
//     sleep(1);
//     int *p = nullptr;
//     *p = 100;
//     cout << "point error after" << endl;
//     sleep(1);
//     //除零错误
//     // signal(8, myhandler);
//     // cout << "div before" << endl;
//     // sleep(1);
//     // int a = 10;
//     // a /= 0;//异常
//     // cout << "div after" << endl;
//     // sleep(1);
//     return 0;
// }