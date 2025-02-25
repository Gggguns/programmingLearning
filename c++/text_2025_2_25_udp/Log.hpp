#pragma once
#include <iostream>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1024

// 日志等级
#define Info 0
#define Debug 1
#define Warning 2
#define Error 3
#define Fatal 4

// 日志输出方式
#define Screen 1
#define Onefile 2
#define Classfile 3

#define LogFile "log.txt"

class Log
{
public:
    //初始化
    Log(){
        printMethod = Screen;
        path = "./log/";
    }
    //更改记录日志方式
    void Enable(int method){
        printMethod = method;
    }
    // 等级转换成字符串
    std::string levelToString(int level)
    {
        switch (level)
        {
        case Info:
            return "Info";
        case Debug:
            return "Debug";
        case Warning:
            return "Warning";
        case Error:
            return "Error";
        case Fatal:
            return "Fatal";
        default:
            return "None";
        }
    }
    
    void operator()(int level, const char *format, ...)
    {
        char leftbuffer[SIZE];
        time_t t = time(nullptr);         // time函数返回的是一个时间戳，我们需要做转换
        struct tm *ctime = localtime(&t); // 转换后的时间，是1900年0月开始的
        snprintf(leftbuffer, sizeof(leftbuffer), "[%s][%d-%d-%d %d:%d:%d]", levelToString(level).c_str(),
                 ctime->tm_year + 1900, ctime->tm_mon + 1, ctime->tm_mday,
                 ctime->tm_hour, ctime->tm_min, ctime->tm_sec);

        va_list s;
        va_start(s, format);
        char rightbuffer[SIZE];
        vsnprintf(rightbuffer, sizeof(rightbuffer), format, s);
        va_end(s);

        // 格式：默认部分+自定义部分
        char logtxt[SIZE * 2];
        snprintf(logtxt, sizeof(logtxt), "%s %s\n", leftbuffer, rightbuffer);

        //printf("%s", logtxt); // 暂时打印
        printLog(level, logtxt);
    }

    //打印日志
    void printLog(int level, const std::string &logtxt){
        switch(printMethod)
        {
        case Screen:
            std::cout << logtxt ;
            break;
        case Onefile:
            printOneFile(LogFile, logtxt);
            break;
        case Classfile:
            printClassFile(level, logtxt);
            break;
        default:
            break;
        }
    }
    //单文件打印
    void printOneFile(const std::string &logname, const std::string &logtxt){
        std::string _logname = path + logname;
        int fd = open(_logname.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0666);
        if(fd < 0){
            return;
        }
        write(fd, logtxt.c_str(), logtxt.size());
        close(fd);
    }
    //多文件打印
    void printClassFile(int level, const std::string &logtxt){
        std::string filename = LogFile;
        filename += '.';
        filename += levelToString(level);
        printOneFile(filename, logtxt);
    }
private:
    int printMethod = Screen;
    std::string path;
};
