#ifndef TIME_RANGE_HPP
#define TIME_RANGE_HPP

#include <iostream>
class TimeRange
{
public:
    TimeRange(){}
    ~TimeRange(){}

    // 初始化时间范围
    void init()
    {
        double start, end;
        std::cout << "请输入开始时间: ";
        std::cin >> start;
        setStartTime(start);
        std::cout << "请输入结束时间: ";
        std::cin >> end;
        setEndTime(end);
    }

    // 设置和获取时间范围
    void setTimeRange(double start, double end)
    {
        setStartTime(start);
        setEndTime(end);
    }

    // 设置和获取开始时间
    void setStartTime(double start)
    {
        startTime = start;
    }
    void getStartTime(double* start) const
    {
        *start = startTime;
    }

    // 设置和获取结束时间
    void setEndTime(double end)
    {
        endTime = end;
    }
    void getEndTime(double* end) const
    {
        *end = endTime;
    }

    // 检查时间范围是否有效
    bool isValid() const
    {
        return startTime < endTime;
    }

private:
    double startTime; // 开始时间
    double endTime; // 结束时间
};

#endif // TIME_RANGE_HPP