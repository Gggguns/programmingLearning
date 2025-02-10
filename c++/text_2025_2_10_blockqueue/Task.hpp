#pragma once
#include <iostream>

std::string opers = "+-*/%";

//错误码
enum{
        DivZero = 1,
        ModZero,
        Unknown,
};

class Task
{
public:
    Task(int x, int y, char op):data1_(x), data2_(y), oper_(op), result_(0), exitcode_(0)
    {}
    void run()
    {
        switch(oper_)
        {
            case '+':
                result_ = data1_ + data2_;
                break;
            case '-':
                result_ = data1_ - data2_;
                break;
            case '*':
                result_ = data1_ * data2_;
                break;
            case '/':
                {
                    if(data2_ == 0)exitcode_ = DivZero;
                    else result_ = data1_ / data2_;
                }
                break;
            case '%':
                {
                    if(data2_ == 0)exitcode_ = ModZero;
                    else result_ = data1_ % data2_;
                }
                break;
            default:
                break;
        }
    }

    void operator()()
    {
        run();
    }
    
    std::string GetResult()
    {
        std::string r = std::to_string(data1_);
        r += oper_;
        r += std::to_string(data2_);
        r += "=";
        r += std::to_string(result_);
        r += "[";
        r += std::to_string(exitcode_);
        r += "]";
        return r;
    }

    std::string GetTask()
    {
        std::string r = std::to_string(data1_);
        r += oper_;
        r += std::to_string(data2_);
        r += "=?";

        return r;
    }

    ~Task()
    {}
private:
    int data1_;
    int data2_;
    char oper_;

    int result_;
    int exitcode_;
};