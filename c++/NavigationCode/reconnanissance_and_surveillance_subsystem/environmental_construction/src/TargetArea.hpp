#ifndef TARGET_AREA_HPP
#define TARGET_AREA_HPP

#include <iostream>
#include "Coordinate.hpp"

class TargetArea
{
public:
    TargetArea(){}
    ~TargetArea(){}

    // 初始化目标区域
    void init()
    {
        std::cout << "请输入目标区域的顶点A坐标:" << std::endl;
        a.init();
        std::cout << "请输入目标区域的顶点B坐标:" << std::endl;
        b.init();
    }

    // 设置和获取目标区域的顶点a
    void setA(const Coordinate& a)
    {
        this->a = a;
    }
    void getA(Coordinate* a) const
    {
        if (a) *a = this->a;
    }

    // 设置和获取目标区域的顶点b
    void setB(const Coordinate& b)
    {
        this->b = b;
    }
    void getB(Coordinate* b) const
    {
        if (b) *b = this->b;
    }

private:
    Coordinate a; // 目标区域的一个顶点a
    Coordinate b; // 目标区域的另一个顶点b
};

#endif // TARGET_AREA_HPP