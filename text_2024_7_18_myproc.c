#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//int g_val_1;
//int g_val_2 = 100;
//int g_val=100;

int main(){
  char *str = "hello Linux";
  *str='H';
  //pid_t id = fork();
  //if(id == 0){
  //  int cnt = 3;//设置计数器
  //  //子进程
  //  while(1){
  //    printf("i am child,pid : %d, ppid : %d g_val : %d, &g_val : %p\n",getpid(),getppid(),g_val,&g_val);
  //    sleep(1);
  //    //三秒后子进程修改g_val的值
  //    if(cnt)cnt--;
  //    else{
  //      g_val=200;
  //      printf("子进程 change g_val : 100->200\n");
  //      cnt--;
  //    }
  //  }
  //}
  //else{
  //  //父进程
  //  while(1){
  //    printf("i am parent,pid : %d, ppid : %d g_val : %d, &g_val : %p\n",getpid(),getppid(),g_val,&g_val);
  //    sleep(1);
  //  }
  //}

  //printf("code addr: %p\n",main);
  //const char* str = "hello Linux";
  //printf("read only string addr: %p\n", str);
  //printf("init global value addr: %p\n", &g_val_2);
  //printf("uninit global value addr: %p\n", &g_val_1);
  ////堆
  //char *mem = (char*)malloc(100);
  //char *mem1 = (char*)malloc(100);
  //char *mem2 = (char*)malloc(100);
  //printf("heap addr: %p\n", mem);
  //printf("heap addr: %p\n", mem1);
  //printf("heap addr: %p\n", mem2);
  ////栈
  //printf("stack addr: %p\n", &str);
  //printf("stack addr: %p\n", &mem);
  //int a,c;
  //static int b;
  //printf("stack addr: %p\n", &a);
  //printf("b stack addr: %p\n", &b);
  //printf("stack addr: %p\n", &c);

  return 0;
}
