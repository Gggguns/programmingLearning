//#pragma once
//避免头文件重复包含，宏的名字随便取的
#ifndef __MYSTDIO_H__
#define __MYSTDIO_H__

#include <string.h>

#define SIZE 1024
//缓冲区刷新策略
#define FLUSH_NOW 1 //无缓冲
#define FLUSH_LINE 2 //行缓冲
#define FLUSH_ALL 4 //全缓冲

typedef struct IO_FILE{
  int fileno;
  int flag;
  //缓冲区又分输入缓冲区和输出缓冲区
  //char inbuffer[SIZE];
  char outbuffer[SIZE];//以输出缓冲区为例
  int out_pos; //缓冲区有效字符个数
}_FILE;

_FILE* _fopen(const char *filename, const char *flag);
int _fwrite(_FILE *fp, const char *s, int len);
void _fclose(_FILE *fp);


#endif
