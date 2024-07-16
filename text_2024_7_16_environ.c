#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[], char** env){
  extern char** environ;
  for(int i=0;environ[i];i++){
    printf("%s\n",environ[i]);
  }


  //printf("%s\n",getenv("Hello"));
  //for(int i=0;env[i];i++){
  //  printf("env[%d]->%s\n",i,env[i]);
  //}
  
  //char who[32];
  //strcpy(who,getenv("USER"));
  //if(strcmp(who,"root") == 0){
  //  printf("让他做任何事\n");
  //}
  //else{
  //  printf("他受权限约束\n");
  //}

  //for(int i=0;i<argc;i++){
  //  //printf("argv[%d]->%s\n",i,argv[i]);
  //  if(strcmp(argv[i],"./proc") == 0){
  //    printf("功能1\n");
  //  }
  //  if(strcmp(argv[i],"-a") == 0){
  //    printf("功能2\n");
  //  }
  //  else if(strcmp(argv[i],"-b") == 0){
  //    printf("功能3\n");
  //  }
  //  else if(strcmp(argv[i],"-c") == 0){
  //    printf("功能4\n");
  //  }
  //  else{
  //  //  printf("没有更多功能了\n");
  //  }
  //}
  return 0;
}
