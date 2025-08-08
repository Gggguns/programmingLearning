#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <iostream>

class Coordinate
{
public:
    Coordinate(){}
    ~Coordinate(){}

    // 初始化坐标
    void init()
    {
        double x, y, z;
        std::cout << "请输入X坐标: ";
        std::cin >> x;
        setX(x);
        std::cout << "请输入Y坐标: ";
        std::cin >> y;
        setY(y);
        std::cout << "请输入Z坐标: ";
        std::cin >> z;
        setZ(z);
    }

    // 设置和获取X坐标
    void setX(double x)
    {
        this->x = x;
    }
    void getX(double* x) const
    {
        if (x) *x = this->x;
    }

    // 设置和获取Y坐标
    void setY(double y)
    {
        this->y = y;
    }
    void getY(double* y) const
    {
        if (y) *y = this->y;
    }

    // 设置和获取Z坐标
    void setZ(double z)
    {
        this->z = z;
    }
    void getZ(double* z) const
    {
        if (z) *z = this->z;
    }

private:
    double x; // X坐标
    double y; // Y坐标
    double z; // Z坐标
};

#endif // COORDINATE_HPP