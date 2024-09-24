#include "common.hpp"
int main(){

    //以写方式打开管道
    int fd = open(FIFO_FILE, O_WRONLY);
    if(fd < 0){
        perror("open");
        exit(FIFO_OPEN_ERR);
    }

    //提示信息
    std::cout << "client open file done" << std::endl;

    std::string line;
    while(true){
        //输出提示信息
        std::cout << "Please Enter@ ";
        std::getline(std::cin, line);

        //向管道写入数据
        write(fd, line.c_str(), line.size());
    }

    close(fd);

    return 0;
}