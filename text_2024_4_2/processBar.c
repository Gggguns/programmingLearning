#include"processBar.h"
#include<string.h>
#include<unistd.h>

const char* label="|/-\\";
char bar[NUM]={0};//为了保证每次输出比上一次多输出一个字符

void processBar(int rate)
{
  int len=strlen(label);;
  printf("[%-100s][%d%%][%c]\r",bar,rate,label[rate%len]);
  fflush(stdout);
  bar[rate++]=Body;
  if(rate<100)bar[rate]=Right;
}

//void processBar()
//{
//  int cnt=0;//定义一个变量cnt,表示进度条的进度
//  char bar[NUM];//为了保证每次输出比上一次多输出一个字符
//  memset(bar,'\0',sizeof(bar));
//  int len=strlen(label);;
//  while(cnt<=100)//进度由0到100,判断条件设置为cnt<=100
//  {
//    printf("[%-100s][%d%%][%c]\r",bar,cnt,label[cnt%len]);
//    fflush(stdout);
//    usleep(100000);
//    bar[cnt++]=Body;
//  if(cnt<100)bar[cnt]=Right;
//  }
//  printf("\n");
//}
