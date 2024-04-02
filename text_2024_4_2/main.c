#include"processBar.h"
#include<unistd.h>
typedef void (*callback_t)(int);//函数指针

void DownLoad(callback_t cb)
{
  int total=10000;//假设这个文件有10000MB
  int curr=0;//目前，只下载了0MB
  while(curr<=total)
  {
    int rate=curr*100/total;//已经下载了百分之几
    cb(rate);//调用进度条打印函数
    usleep(10000);//模拟下载10MB需要的时间
    curr+=10;//每次下载10M
  }
  printf("\n");
}

int main()
{
  DownLoad(processBar);
  return 0;
}
