#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>

#define N 2 // 数组大小
#define NUM 1024

using namespace std;

void Writer(int wfd){
    //模拟要发送的数据
    string s = "hello, I am chlid";
    pid_t self = getpid();
    int number = 0;

    char buffer[NUM];//用来存储发送数据
    while(true){
        buffer[0] = 0; //字符串清空，这里只是为了提醒阅读代码的人，我把这个数组当作一个字符串
        snprintf(buffer,sizeof(buffer), "%s-%d-%d", s.c_str(), self, number++); //调用snprintf
        //cout << buffer <<endl; //验证是否正确写入
        //发送/写入数据给父进程
        
        write(wfd, buffer, strlen(buffer));//需不需要 strlen + 1 ? 不需要，文件里没有\0作为字符串结尾的概念
        sleep(1); //休息一秒，再写入

        // char ch = 'c';
        // sleep(1);
        // write(wfd, &ch, 1);
        // number++;
        // cout << number << endl;
        //if(number > 5)break;
    }
}

void Reader(int rfd){
    
    char buffer[NUM];//用于接受数据
    int cnt = 0;

    while(true){
        //sleep(50);//这里让父进程久一点再进行读取
        buffer[0] = 0;
        ssize_t n = read(rfd, buffer, sizeof(buffer));//sizeof != strlen
        if(n > 0){//判断是否有内容g
            buffer[n] = 0; // 0 == '\0' 把buffer中的内容看作字符串
            cout << "father get a message[" << getpid() << "]#" << buffer << endl;
        }
        else if(n == 0){
            printf("father read file done!\n");
            break;
        }
        else break;
        
        cnt++;
        if(cnt > 5)break;

    }
}

int main()
{
    int pipefd[N] = {0};  // 定义一个数组
    int n = pipe(pipefd); // 调用pipe函数，创建管道
    if (n < 0)return 1; // 检查管道创建情况

    // debug 输出数组信息
    //cout << "pipefd[0]: " << pipefd[0] << " , pipefd[1]: " << pipefd[1] << endl;

    pid_t id = fork();
    if (id < 0)return 2;//fork失败则返回

    // 我们让子进程写数据，父进程读数据
    if (id == 0)
    {
        // child
        close(pipefd[0]); // 关闭读端

        // IPC code
        Writer(pipefd[1]); // 把写数据的行为放到Writer函数中

        close(pipefd[1]); // 写完后，关闭写端
        exit(0);          // 退出子进程
    }
    // 走到这的是父进程

    close(pipefd[1]); // 关闭写端

    // IPC code
    Reader(pipefd[0]); // 把父进程读数据的行为封装到Reader函数中
    close(pipefd[0]); //关闭读端
    cout << "father close read fd: " << pipefd[1] << endl;//打印提示信息
    sleep(5); //为了观察僵尸进程
    
    int status = 0;
    //等待回收子进程
    pid_t rid = waitpid(id, &status, 0);
    if(rid < 0)return 3; //回收失败则返回
    cout << "wait child success: " << rid << " exit code: " << ((status>>8)&0xFF) << " exit signal: " << (status&0x7F) << endl;//提示信息
    sleep(5);

    cout << "father quit" << endl;//提示信息
    
    return 0;
}
