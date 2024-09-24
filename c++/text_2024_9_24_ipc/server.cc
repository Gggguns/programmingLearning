#include "common.hpp"
#include "log.hpp"

//管理管道文件
int main(){
    
    //logmessage(Info, "hello");

    Init init;
    Log log;

    log.Enable(Classfile);

    //打开管道
    int fd = open(FIFO_FILE, O_RDONLY);
    if(fd < 0){
        //perror("open");
        log(Fatal, "error string: %s, error code: %d", strerror(errno), errno);
        exit(FIFO_OPEN_ERR);
    }

    //std::cout << "server open file done" << std::endl;
    //为了便于测试
    log(Info, "server open file done, error string: %s, error code: %d", strerror(errno), errno);
    log(Warning, "server open file done, error string: %s, error code: %d", strerror(errno), errno);
    log(Fatal, "server open file done, error string: %s, error code: %d", strerror(errno), errno);
    log(Debug, "server open file done, error string: %s, error code: %d", strerror(errno), errno);

    //开始通信
    while(true){
        char buffer[1024] = {0};
        int x = read(fd, buffer, sizeof(buffer));
        if(x > 0){
            buffer[x] = 0;
            std::cout << "client say# " << buffer << std::endl;
        }
        else if(x == 0){
            //提示信息
            //std::cout << "client quit, me too!" << std::endl;
            log(Debug, "client quit, me too! error string: %s, error code: %d", strerror(errno), errno);
            break;
        }
        else break;
    }

    close(fd);

    
    return 0;
}