#ifndef SPECTRUM_HPP
#define SPECTRUM_HPP

#include <vector>
#include <string>

class Spectrum
{
public:
    Spectrum(){}
    ~Spectrum(){}

    // 设置和获取光谱范围
    void setRange(double startFrequency, double endFrequency)
    {
        this->startFrequency = startFrequency;
        this->endFrequency = endFrequency;
    }

    void getRange(double* startFrequency, double* endFrequency) const
    {
        if (startFrequency) *startFrequency = this->startFrequency;
        if (endFrequency) *endFrequency = this->endFrequency;
    }
    
    // 设置和获取起始频率
    void setStartFrequency(double startFrequency)
    {
        this->startFrequency = startFrequency;
    }
    void getStartFrequency(double* startFrequency) const
    {
        if (startFrequency) *startFrequency = this->startFrequency;
    }

    // 设置和获取结束频率

    void setEndFrequency(double endFrequency)
    {
        this->endFrequency = endFrequency;
    }
    void getEndFrequency(double* endFrequency) const
    {
        if (endFrequency) *endFrequency = this->endFrequency;
    }  

    // 添加和获取光谱带
    void addBand(const std::string& band)
    {
        bands.push_back(band);
    }
    void getBands(std::vector<std::string>* bands) const
    {
        if (bands) *bands = this->bands;
    }

private:
    std::vector<std::string> bands; // 光谱带列表
    double startFrequency; // 起始频率
    double endFrequency; // 结束频率
};

#endif // SPECTRUM_HPP