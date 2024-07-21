#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define N 10

void runChild(){
  int cnt=5;
  while(1){
    printf("I am child, pid: %d, ppid: %d, cnt: %d\n",getpid(),getppid(),cnt);
    cnt--;
    sleep(1);
  }
}

int main(){
  //int i=0;
  ////创建10个子进程
  //for(i=0;i<N;i++){
  //  pid_t id=fork();
  //  if(id == 0){
  //    runChild();//执行我们安排的任务
  //    exit(0);   //退出子进程
  //  }
  //}
  //sleep(5);//在这歇息一会，我们看看结果

  ////等待
  //for(i=0;i<N;i++){
  //  pid_t id=wait(NULL);
  //  if(id > 0){
  //    printf("wait: %d success\n",id);
  //  }
  //}

  //sleep(10);//别急着走，我再看看

  pid_t id = fork();
  if(id < 0){
    perror("fork");
    return 1;
  }
  else if(id == 0){
    //child
    //int a=10;
    //a/=0;
    int cnt = 5;
    while(cnt){
      printf("I am child, pid: %d , ppid: %d ,cnt: %d\n",getpid(),getppid(),cnt);
      cnt--;
      sleep(1);
    }
    exit(1);//便于测试设置为1
  }
  else{
    ////parent
    //int cnt=10;
    //while(cnt){
    //  printf("I am parent, pid: %d , ppid: %d ,cnt: %d\n",getpid(),getppid(),cnt);
    //  sleep(1);
    //  cnt--;
    //}
    int status = 0;
    //询问
    while(1){
      pid_t ret = waitpid(id,&status,WNOHANG);//根据返回值判断等待是否成功
      if(ret == id){
        //0x7F 0111 1111
        //printf("wait success, ret: %d,exit sig: %d,exit code: %d\n",ret,status&0x7F,(status>>8)&0x8F);
        if(WIFEXITED(status)){
          printf("进程是正常跑完的，退出码: %d\n",WEXITSTATUS(status));
        }
        else{
          printf("进程出异常\n");
        }
        break;
      }
      else if(ret == 0){
        printf("子进程还没退出，我再等等...\n");
        sleep(1);
      }
      //在什么情况下，进程会等待失败？
      else{
        printf("wait failed!\n");
        break;
      }
    }
  }

  return 0;
}
