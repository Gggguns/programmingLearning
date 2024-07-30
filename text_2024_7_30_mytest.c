#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define filename "log.txt"

int main(){
  int fd = open(filename, O_RDONLY);
  if(fd < 0){
    perror("open");
    return 1;
  }
  dup2(fd,0);
  char inbuffur[1024];
  ssize_t s = read(0, inbuffur, sizeof(inbuffur)-1);
  if(s > 0){
    //read的返回值s刚好就是字符串的末尾
    inbuffur[s] = '\0';
    printf("echo# %s\n", inbuffur);
  }
  return 0;
}

//int main(){
//  //关闭0位置的文件
//  //close(0);
//  //关闭1位置的文件
//  //close(1);
//  //关闭2位置的文件
//  //close(2);
//
//  int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
//  //int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
//  //fd是数组下标，不会小于0
//  if(fd < 0){
//    perror("open");
//    return 1;
//  }
//
//  dup2(fd, 1);
//  close(fd);
//
//  printf("fd: %d\n", fd);
//  const char *message = "hello Linux\n";
//  int cnt = 5;
//  while(cnt){
//    //write(fd, message, strlen(message));
//    write(1, message, strlen(message));
//    cnt--;
//  }
//
//  close(fd);
//  return 0;
//}
