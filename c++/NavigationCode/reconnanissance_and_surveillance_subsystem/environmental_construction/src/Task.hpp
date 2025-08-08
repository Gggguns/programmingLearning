#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "TimeRange.hpp"
#include "TargetArea.hpp"
#include "Satellite.hpp"


class Task
{
public:
    Task(){}
    ~Task(){}

    

    // 初始化任务
    void init()
    {
        std::cout << "请输入任务名称: ";
        std::string name;
        std::cin >> name;
        setName(name);
        timeRange.init();
        targetArea.init();
        taskDescription = "任务描述";
    }

    // 执行任务
    void execute()
    {
        std::cout << "执行任务: " << taskName << std::endl;
        // 这里添加任务执行的具体逻辑
    }

    // 任务结果导出
    void taskResultExport()
    {}

    // 设置和获取任务描述
    void setName(const std::string& name)
    {
        taskName = name;
    }
    void getName(std::string* name) const
    {
        if (name) *name = taskName;
    }

    // 设置和获取任务时间范围
    void setTimeRange(const TimeRange& range)
    {
        timeRange = range;
    }
    void getTimeRange(TimeRange* range) const
    {
        if (range) *range = timeRange;
    }

    // 添加和获取目标区域
    void setTargetArea(const TargetArea& area)
    {
        targetArea = area;
    }
    void getTargetArea(TargetArea* area) const
    {
        if (area) *area = targetArea;
    }

    // 添加卫星和获取卫星链表
    void addSatellite(const Satellite& satellite)
    {
        satelliteList.push_back(satellite);
    }
    void getSatelliteList(std::vector<Satellite>* list) const
    {
        if (list) *list = satelliteList;
    }

    // 设置和获取任务描述
    void setDescription(const std::string& description)
    {
        taskDescription = description;
    }
    void getDescription(std::string* description) const
    {
        if (description) *description = taskDescription;
    }

private:
    std::string taskName; // 任务名字
    TimeRange timeRange; // 时间范围
    TargetArea targetArea; // 目标区域
    std::vector<Satellite> satelliteList; // 卫星链表
    std::string taskDescription; // 任务描述
};

#endif // TASK_HPP