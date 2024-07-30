#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#define LEFT "["
#define RIGHT "]"
#define LABEL "#"
#define DELIM " \t"
#define LINE_SIZE 1024
#define ARGC_SIZE 32
#define EXIT_CODE 44

#define NONE -1
#define IN_RDIR 0   //输入重定向<
#define OUT_RDIR 1  //输出重定向>
#define APPEND_RDIR 2 //追加重定向>>

int lastcode = 0;
extern char **environ;
char pwd[LINE_SIZE];//记录当前工作路径
char commandline[LINE_SIZE];//记录指令
char *argv[ARGC_SIZE];//记录分割后的字符串
//自定义环境表，这里我们只允许保存一个
char myenv[LINE_SIZE];//保存环境变量
char* rdirfilename = NULL;//重定向的文件名
int rdir = NONE;//是否有重定向符

void check_rdir(char *cmd){
  //ls -a -n >\<\>> filename.txt
  char *pos = cmd;
  //遍历找到重定向符号
  while(*pos){
    if(*pos == '>'){
      if(*(pos + 1) == '>'){
        *pos = '\0';//将重定向符设置为去掉
        pos++;
        *pos = '\0';
        pos++;
        //空格往后走
        while(isspace(*pos))pos++;
        rdirfilename = pos;
        rdir = APPEND_RDIR;
        break;
      }
      else{
        *pos = '\0';
        pos++;
        while(isspace(*pos))pos++;
        rdirfilename = pos;
        rdir = OUT_RDIR;
        break;
      }
    }
    else if(*pos == '<'){
      *pos = '\0';
      pos++;
      //如果空格就往后++
      while(isspace(*pos))pos++;

      rdirfilename = pos;
      rdir = IN_RDIR;
      break;
    }
    else{
      //do nothing
    }
    pos++;
  }
}

//获取信息
const char* getUserName(){
  return getenv("USER");
}
const char* getHostName(){
  return getenv("HOSTNAME");
}
void getPwd(){
  //第一个参数传数组，第二个参数传数组的大小
  getcwd(pwd,sizeof(pwd));
}


void interact(char *cline,int size){
    getPwd();
    //printf中的相邻两个字符串会自动连接
    printf(LEFT"%s@%s %s"RIGHT"$",getUserName(),getHostName(),pwd);
    //ls -a -l -> "ls -a -l"
    //scanf("%s",commandline);
    char* s = fgets(cline,size,stdin);
    (void)s;//编译器老是警告，我们这里骗它说，这个变量我们用过了
    assert(s);
    //ls -a -b\n
    cline[strlen(cline)-1] = '\0';
    //if(s)printf("echo: %s\n",commandline);
    //检查是否有重定向符号
    check_rdir(cline);

}
int splitString(char cline[],char *_argv[]){
  int i=0;
  _argv[i++] = strtok(cline,DELIM);
  while(_argv[i++] = strtok(NULL,DELIM));//故意写的=
  return i-1;
}
void normalExcute(char *_argv[]){
  pid_t id = fork();
  //id<0表示出错，打印错误信息，直接返回
  if(id < 0){
    perror("fork");
    return;
  }
  else if(id == 0){
    //child
    //我们进行重定向各种关系，不会影响后面的程序替换吗？
    int fd = 0;
    if(rdir == IN_RDIR){
      fd = open(rdirfilename, O_RDONLY);
      dup2(fd, 0);
    }
    else if(rdir == OUT_RDIR){
      fd = open(rdirfilename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
      dup2(fd, 1);
    }
    else if(rdir == APPEND_RDIR){
      fd = open(rdirfilename, O_WRONLY | O_CREAT | O_APPEND, 0666);
      dup2(fd, 1);
    }
    execvpe(_argv[0],_argv,environ);
    exit(EXIT_CODE);//进程替换失败，就终止子进程
  }
  else{
    int status = 0;
    pid_t rid = waitpid(id, &status, 0);//阻塞等待
    if(rid == id){
      //获取子进程退出码
      lastcode = WEXITSTATUS(status);
    }
  }
}
int buildCommand(char *_argv[], int _argc){
  //argv[0]就是指令的名字
  //cd指令
  if(_argc == 2 && strcmp(_argv[0],"cd") == 0){
    chdir(_argv[1]);
    getPwd();
    sprintf(getenv("PWD"),"%s",pwd);
    return 1;
  }
  else if(_argc == 2 && strcmp(_argv[0], "export") == 0){
    //不能直接 putenv(_argv[1]);
    strcpy(myenv,_argv[1]);
    putenv(myenv);
    return 1;
  }
  else if(_argc == 2 && strcmp(_argv[0], "echo") == 0){
    if(strcmp(_argv[1], "$?") == 0){
      printf("%d\n",lastcode);
      lastcode = 0;
    }
    else if(*_argv[1] == '$'){
      char *val = getenv(_argv[1]+1);
      if(val)printf("%s\n",val);
    }
    else printf("%s\n",_argv[1]);
    return 1;
  }
  //ls --color
  if(strcmp(_argv[0], "ls") == 0){
    _argv[_argc] = "--color";
    _argc++;
    _argv[_argc] = NULL;
  }
  return 0;
}

int main(){
  int quit=0;
  while(!quit){
    //1.
    rdirfilename = NULL;
    rdir = NONE;
    //2.交互问题，获取命令行
    interact(commandline,sizeof(commandline));
    //commandline: ls -a -b\0 -> "ls" "-a" "-b"
    //3.子串分割的问题，解析命令行
    int argc = splitString(commandline,argv);
    if(argc == 0)continue;//如果返回值为0，意味着没指令
    //debug
    //4.指令的判断
    int n = buildCommand(argv, argc);
    //int i = 0;
    //for(i = 0;i < argc;i++)printf("argv[%d]-> %s\n",i,argv[i]);
    //5.普通命令的执行
    if(!n)normalExcute(argv);
  }
  return 0;
}
