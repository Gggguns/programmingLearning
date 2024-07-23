#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
  
  pid_t id = fork();
  if(id == 0){
    char* myargv[] = {
      "otherExe",
      "-a",
      "-w",
      "-v",
      NULL
    };
    extern char** environ;
    putenv("PRIVATE_ENV=6666666666");

    printf("before: I am a process, pid: %d, ppid: %d\n",getpid(),getppid());
    sleep(5);
    //下面这种是标准写法
    //execl("/usr/bin/python3","python3","test.py",NULL);
    //execl("/usr/bin/bash","bash","test.sh",NULL);
    //execl("./otherExe","otherExe","-a","-b",NULL);
    //execl("/usr/bin/top","top",NULL);
    //execlp("ls","ls","-a","-l",NULL);
    //execv("/usr/bin/ls",myargv);
    //execvp("ls",myargv);
    char* const myenv[] = {
      "MYVAL=666",
      "MYPATH=/usr/bin/XXX",
      NULL
    };
    //execle("/usr/bin/ls","ls","-a","-l",NULL,environ);
    execvpe("./otherExe",myargv,myenv);
    //execve("/usr/bin/ls",myargv,environ);
    printf("afterr: I am a process, pid: %d, ppid: %d\n",getpid(),getppid());
    exit(0);
  }
  pid_t ret = waitpid(id,NULL,0);
  if(ret > 0)printf("wait success, father pid: %d, ret id: %d\n",getpid(),ret);
  sleep(5);
  return 0;
}
