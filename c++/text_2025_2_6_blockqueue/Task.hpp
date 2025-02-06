#pragma once
#include <iostream>
class Task
{
public:
    Task(int x, int y):a(x),b(y)
    {}
    void run()
    {
        std::cout << "run task: " << a << "+" << b << "=" << a+b << std::endl;
    }
    ~Task()
    {}
private:
    int a;
    int b;
};