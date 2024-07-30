#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  int fd1 = open("log1.txt", O_WRONLY | O_CREAT);
  int fd2 = open("log2.txt", O_WRONLY | O_CREAT);
  int fd3 = open("log3.txt", O_WRONLY | O_CREAT);
  int fd4 = open("log4.txt", O_WRONLY | O_CREAT);
  printf("fd1-> %d\n", fd1);
  printf("fd2-> %d\n", fd2);
  printf("fd3-> %d\n", fd3);
  printf("fd4-> %d\n", fd4);
  return 0;
}

//int main(){
//
//  printf("stdin->fd: %d\n", stdin->_fileno);
//  printf("stdout->fd: %d\n", stdout->_fileno);
//  printf("stderr->fd: %d\n", stderr->_fileno);
//  return 0;
//}

//int main(){
//  //int fd = open("log.txt",O_RDONLY);
//  char buffer[1024];
//  ssize_t s = read(0, buffer, sizeof(buffer));
//  //ssize_t s = read(fd, buffer, sizeof(buffer));
//  if(s < 0)return 1;
//  buffer[s] = '\0';
//  printf("echo : %s\n", buffer);
//  return 0;
//}

//int main(){
//  close(1);
//  int n = printf("hello Linux\n");
//
//  fprintf(stderr,"printf ret: %d\n", n);
//
//  return 0;
//}

//int main(){
//  umask(0);
//  //file descriptor: 文件描述符，fd，int
//  int fd = open("log.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
//  printf("fd: %d\n", fd);
//  //int fd = open("log.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
//  if(fd < 0){
//    printf("open file error");
//    return 1;
//  }
//  //const char *message = "1\n";
//  const char *message = "hello system call\n";
//  write(fd, message, strlen(message));
//
//  close(fd);
//  return 0;
//}

//#define ONE (1<<0) //1
//#define TWO (1<<1) //2
//#define THREE (1<<2) //4
//#define FOUR (1<<3) //8
//
//void show(int flags){
//  if(flags&ONE)printf("hello function1\n");
//  if(flags&TWO)printf("hello function2\n");
//  if(flags&THREE)printf("hello function3\n");
//  if(flags&FOUR)printf("hello function4\n");
//}
//
//int main(){
//  printf("----------------------\n");
//  show(ONE);
//  printf("----------------------\n");
//  
//  printf("----------------------\n");
//  show(TWO);
//  printf("----------------------\n");
//
//  printf("----------------------\n");
//  show(ONE | TWO);
//  printf("----------------------\n");
//
//  printf("----------------------\n");
//  show(THREE | FOUR);
//  printf("----------------------\n");
//
//  printf("----------------------\n");
//  show(ONE | TWO | THREE | FOUR);
//  printf("----------------------\n");
//
//  return 0;
//}

//int main(){
//  //chdir("/home/common_108");
//  //打开文件的路径和文件名，默认在当前路径下新建一个文件？
//  //FILE *fp = fopen("log.txt", "w");
//  FILE *fp = fopen("log.txt", "a");
//  //打开失败
//  if(fp == NULL){
//    perror("fopen");
//    return 1;
//  }
//  //写入
//  //const char *message = "hello Linux message";
//  const char *message = "abcd";
//  //strlen(message) + 1 ? 为什么？
//  //fwrite(message, strlen(message), 1, fp);
//  fprintf(fp, "%s : %d\n", message, 1234);
//
//  fclose(fp);
//
//  //printf("Pid: %d\n", getpid());
//  //sleep(10);
//  return 0;
//}
