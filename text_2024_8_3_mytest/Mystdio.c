#include "Mystdio.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_MODE 0666 //创建文件的默认权限

_FILE* _fopen(const char *filename, const char *flag){
  int fd = -1;
  if(strcmp(flag, "w") == 0){
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
  }
  else if(strcmp(flag, "a")){
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, FILE_MODE);
  }
  else if(strcmp(flag, "r")){
    fd = open(filename, O_RDONLY);
  }
  else{
    return NULL;
  }
  
  if(fd < 0)return NULL;
  
  _FILE* fp = (_FILE*)malloc(sizeof(_FILE));
  if(fp == NULL)return NULL;

  fp->fileno = fd;
  fp->flag = FLUSH_LINE;//默认行缓冲
  fp->out_pos = 0;

  return fp;
}

int _fwrite(_FILE *fp, const char *s, int len){
  if(s == NULL)return 0;
  //拷贝数据到缓冲区
  memcpy(&fp->outbuffer[fp->out_pos], s, len);
  fp->out_pos += len;

  if(fp->flag & FLUSH_NOW){ //无缓冲
    if(fp->out_pos > 0){
      write(fp->fileno, fp->outbuffer, fp->out_pos);
      fp->out_pos = 0;
    }
  }
  else if(fp->flag & FLUSH_LINE){ //行缓冲
    if(fp->outbuffer[fp->out_pos-1] == '\n'){
      write(fp->fileno, fp->outbuffer, fp->out_pos);
      fp->out_pos = 0;
    }
  }
  else if(fp->flag & FLUSH_ALL){ //全缓冲
    if(fp->out_pos == SIZE){
      write(fp->fileno, fp->outbuffer, fp->out_pos);
      fp->out_pos = 0;
    }
  }

  return len;
}

void _fflush(_FILE* fp){
  if(fp->out_pos > 0){
    write(fp->fileno, fp->outbuffer, fp->out_pos);
    fp->out_pos = 0;
  }
}

void _fclose(_FILE *fp){
  if(fp == NULL)return;
  //文件关闭前，强制刷新
  _fflush(fp);
  close(fp->fileno);
  free(fp);
}



















