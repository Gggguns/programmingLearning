#ifndef TASK_SCHEDULER_HPP
#define TASK_SCHEDULER_HPP

#include <vector>
#include "Task.hpp"

class TaskScheduler
{
public:
    TaskScheduler(){}
    ~TaskScheduler(){}

    void addTask(const Task& task)
    {
        eventSequence.push_back(task);
    }
    void executeTasks()
    {
        for (auto& task : eventSequence)
        {
            task.execute();
        }
    }

private:
    std::vector<Task> eventSequence; // 事件序列
};

#endif // TASK_SCHEDULER_HPP
