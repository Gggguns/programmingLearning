#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>
#include <assert.h>
#include "Task.hpp"


const int processnum = 10;
std::vector<task_t> tasks;

//先描述
class channel{
public:
    channel(int cmdfd, pid_t slaverid, std::string processname):_cmdfd(cmdfd),_slaverid(slaverid),_processname(processname){}
    int _cmdfd;                //发送任务的文件描述符
    pid_t _slaverid;           //子进程的PID
    std::string _processname;  //子进程的名字 -- 方便我们打印日志
};

void slaver(){
    while(true){
        int cmdcode = 0;
        int n = read(0, &cmdcode, sizeof(int));//如果父进程不发送数据呢？阻塞等待
        if(n == sizeof(int)){
            //执行cmdcode对应的任务列表
            //std::cout << getpid() << " : cmdcode: " << cmdcode << std::endl;
            std::cout << "slaver say@ get a command: " << getpid() << " : cmdcode: " << cmdcode << std::endl;//输出提示信息
            if(cmdcode >= 0 && cmdcode < tasks.size())tasks[cmdcode]();//执行任务
        }

    }
}
//输出 *
//输入 const &
//输入输出 &
void InitProcessPool(std::vector<channel> *channels){
    for(int i = 0; i<processnum; i++){
        int pipefd[2]; //临时空间
        int n = pipe(pipefd);  
        assert(!n);  //演示就可以
        (void)n; //告诉编译器变量n使用过了

        pid_t id = fork();
        if(id == 0){//child
            close(pipefd[1]); //关闭写端
            dup2(pipefd[0],0);//将管道的读端重定向到0，这样slaver就不用传参了，直接从0读
            slaver();  //等待指令 
            exit(0);
        }
        
        //father
        close(pipefd[0]);//关闭读端

        //增加channel字段
        std::string name = "process-"+std::to_string(i);
        channels->push_back(channel(pipefd[1], id, name));
    }
}

void Debug(const std::vector<channel> channels){
    //test
    for(const auto& c : channels){
        std::cout << c._cmdfd << " " << c._slaverid << " " << c._processname << std::endl;
    }
}

void Menu(){
    std::cout << "##########################################" <<std::endl;
    std::cout << "# 1. 刷新日志         2. 刷新出来野怪      #" <<std::endl;
    std::cout << "# 3. 检测软件是否更新  4. 更新用的血量和蓝量#" <<std::endl;
    std::cout << "#                     0. 退出            #" <<std::endl;
    std::cout << "##########################################" <<std::endl;
}

void ctrlSlaver(const std::vector<channel> &channels){
    int which = 0;//增加一个计数器
    while(true){
        //
        int select = 0;
        Menu();
        std::cout << "Please Eater@ ";
        std::cin >> select;

        if(select <= 0 || select >= 5)break;//判定合法性
        //1.选择任务
        // int cmdcode = rand()%tasks.size();
        int cmdcode = select-1;

        //2.选择进程
        // int processpos = rand()%channels.size();
        int processpos = which;

        //Debug
        std::cout << "father say: " << "cmdcode: " << 
            cmdcode << " already sent to " << channels[processpos]._slaverid << 
                " process name: " << channels[processpos]._processname << std::endl;

        //3.发送任务
        write(channels[processpos]._cmdfd, &cmdcode, sizeof(cmdcode));
        which++;
        which %= channels.size();//防止越界
        sleep(1);
     }
}

int main(){
    srand(time(nullptr)^getpid()^1023);//种一个随机数种子，乘别的数是为了增大离散程度
    LoadTask(&tasks);
    //再组织
    std::vector<channel> channels;
    //1.初始化
    InitProcessPool(&channels);
    //Debug(channels);

    //2.控制子进程
    ctrlSlaver(channels);

    //3.清理收尾

    return 0;
}