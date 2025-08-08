#include <iostream>
#include <string>
#include "Task.hpp"
using namespace std;

int main()
{
    Task task;
    task.init();
    task.execute();
    task.taskResultExport();

    return 0;
}