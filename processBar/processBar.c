#include"processBar.h"
char label[5]="/|\\-";
char buff[102]={0};
int i=0;
void processbar(int rate,size_t Time)
{
  if(rate>=0&&rate<=100)
  {
    int len=strlen(label);
    printf("[%s][%%%d][%c]\r",buff,rate,label[(i++)%len]);
    fflush(stdout);
    usleep(Time);
    buff[rate]='-';
    if(rate!=99)
      buff[rate+1]='>';
  }
}
void Download(size_t Totaltime)
{
  size_t total=100000;
  size_t everyload =1000;
  size_t count=0;
  size_t Time=Totaltime/(total/everyload);
  while(count<=total)
  {
    int rate=count*100/total;
    processbar(rate,Time);
    count+=everyload;
  }
  printf("\n");
  return;
}
