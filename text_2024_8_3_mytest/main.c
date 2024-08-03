#include "Mystdio.h"
#include <unistd.h>

#define MYFILE "test.txt"

int main(){
  _FILE* fp = _fopen(MYFILE, "w");
  if(fp == NULL)return 1;

  const char *msg = "hello world\n";

  int cnt = 10;
  //每秒向文件写入一次
  while(cnt){
    _fwrite(fp, msg, strlen(msg));
    sleep(1);
    cnt--;
  }

  _fclose(fp);

  return 0;
}
