#ifndef SENSOR_PARAMS_HPP
#define SENSOR_PARAMS_HPP

#include "Spectrum.hpp"

class SensorParams
{
public:
    SensorParams(){}
    ~SensorParams(){}

    // 设置和获取传感器参数
    void setResolution(double width, double height)
    {
        resolutionWidth = width;
        resolutionHeight = height;
    }
    void getResolution(double& width, double& height) const
    {
        width = resolutionWidth;
        height = resolutionHeight;
    }

    // 设置和获取光谱范围
    void setSpectralRegion(const Spectrum& region)
    {
        spectralRegion = region;
    }
    void getSpectralRegion(Spectrum* region) const
    {
        if (region) *region = spectralRegion;
    }

    // 设置和获取扫描参数
    void setScanningParameters(double width, double height)
    {
        scanningWidth = width;
        scanningHeight = height;
    }
    void getScanningParameters(double* width, double* height) const
    {
        if (width) *width = scanningWidth;
        if (height) *height = scanningHeight;
    }

private:
    double resolutionWidth; // 分辨率宽度
    double resolutionHeight; // 分辨率高度
    double scanningWidth; // 扫描宽度
    double scanningHeight; // 扫描高度
    Spectrum spectralRegion; // 光谱范围
};

#endif // SENSOR_PARAMS_HPP