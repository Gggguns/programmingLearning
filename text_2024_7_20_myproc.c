#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
  printf("you can see me");
  exit(0);
  return 0;
}

//void show(){
//  printf("hello show\n");
//  printf("hello show\n");
//  printf("hello show\n");
//  printf("hello show\n");
//  printf("hello show\n");
//  printf("hello show\n");
//  printf("hello show\n");
//  return; 
//  printf("hello show\n");
//  printf("hello show\n");
//  printf("hello show\n");
//}
//
//int main(){
//  show();
//  exit(13);
//  return 12;
//  //while(1){
//  //  printf("i am a process, pid: %d\n",getpid());
//  //  sleep(1);
//  //}
//  //int a=0;
//  //int b=100/a;
//  //return 0;
//  //char* p = NULL;
//  //*p = 100;
//  //return 0;
//}

//int main(){
//  int ret=0;
//  char* p =(char*)malloc(1000*1000*1000*4);
//  if(p == NULL){
//    printf("malloc error, %d: %s\n",errno,strerror(errno));
//    ret=1;
//  }
//  else{
//    printf("malloc sucess\n");
//  }
//  return ret;
//}


//int main(){
//  int i=0;
//  for(i=0;i<200;i++){
//    printf("%d : %s\n",i,strerror(i));
//  }
//  return 0;
//}


//void runChild(){
//  int cnt=3;
//  while(cnt){
//    printf("i am child: %d,ppid: %d\n",getpid(),getppid());
//    sleep(1);
//    cnt--;
//  }
//  return;
//}

//int main(){




  //printf("模拟一个逻辑的实现\n");

  //return 0;
  //int i=0;
  //for(i=0;i<5;i++){
  //  pid_t id=fork();
  //  if(id == 0){
  //    runChild();
  //    exit(0);
  //  }
  //}

  ////这里我们别让父进程退出这么快，便于查看
  //sleep(1000);

  //printf("pid : %d before!\n",getpid());
  //fork();
  //printf("pid : %d after !\n",getpid());
//  return 0;
//}
//
