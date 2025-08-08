#ifndef SATELLITE_HPP
#define SATELLITE_HPP

#include "PayloadParams.hpp"

class Satellite
{
public:
    Satellite(){}
    ~Satellite(){}

    void initialize(){}
    void updatePosition(){}
    void transmitData(){}

private:
    int id; // 卫星ID
    PayloadParams payload; // 载荷参数
};

#endif // SATELLITE_HPP