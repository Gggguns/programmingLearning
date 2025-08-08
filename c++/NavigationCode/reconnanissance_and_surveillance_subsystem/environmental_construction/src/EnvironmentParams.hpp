#ifndef ENVIRONMENT_PARAMS_HPP
#define ENVIRONMENT_PARAMS_HPP

class EnvironmentParams
{
public:
    EnvironmentParams(){}
    ~EnvironmentParams(){}

    // 设置和获取大气密度
    void setAtmosphereDensity(double density)
    {
        atmosphereDensity = density;
    }
    void getAtmosphereDensity(double* density) const
    {
        if (density) *density = atmosphereDensity;
    }

    // 设置和获取光照条件
    void setLightConditions(double conditions)
    {
        lightConditions = conditions;
    }
    void getLightConditions(double* conditions) const
    {
        if (conditions) *conditions = lightConditions;
    }

    // 获取和设置电磁干扰水平
    void setElectromagneticInterferenceLevel(double interference)
    {
        electromagneticInterferenceLevel = interference;
    }
    void getElectromagneticInterferenceLevel(double* interference) const
    {
        if (interference) *interference = electromagneticInterferenceLevel;
    }

private:
    double atmosphereDensity; // 大气密度
    double lightConditions; // 光照条件
    double electromagneticInterferenceLevel; // 电磁干扰水平
};

#endif // ENVIRONMENT_PARAMS_HPP