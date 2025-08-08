#ifndef PAYLOAD_PARAMS_HPP
#define PAYLOAD_PARAMS_HPP

#include <string>
#include "SensorParams.hpp"

class PayloadParams
{
public:
    PayloadParams(){}
    ~PayloadParams(){}

    // 设置和获取轨道根数
    void setOrbitalNumber(int orbitalNum)
    {
        orbitalNumber = orbitalNum;
    }
    void getOrbitalNumber(int* orbitalNum) const
    {
        if (orbitalNum) *orbitalNum = orbitalNumber;
    }

    // 获取传感器参数
    void setSensorParams(const SensorParams& params)
    {
        sensorParams = params;
    }
    void getSensorParams(SensorParams* params) const
    {
        if (params) *params = sensorParams;
    }

private:
    int orbitalNumber; // 轨道根数
    SensorParams sensorParams; // 传感器参数

};

#endif // PAYLOAD_PARAMS_HPP