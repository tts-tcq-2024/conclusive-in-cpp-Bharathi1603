#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <functional>

#include "CoolingStrategy.h"
#include "CoolingTypes.h"
#include "PassiveCooling.h"
#include "HiActiveCooling.h"
#include "MedActiveCooling.h"
#include "BreachType.h"

class TemperatureClassifier 
{
private:
    std::unique_ptr<CoolingStrategy> strategy;
    
    BreachType inferBreach(double value, double lowerLimit, double upperLimit) const;
    
    const std::map<CoolingType, std::function<std::unique_ptr<CoolingStrategy>()>> coolingStrategies = 
    {
        { CoolingType::PASSIVE, []() { return std::make_unique<PassiveCooling>(); } },
        { CoolingType::HI_ACTIVE, []() { return std::make_unique<HiActiveCooling>(); } },
        { CoolingType::MED_ACTIVE, []() { return std::make_unique<MedActiveCooling>(); } },
    };

    std::unique_ptr<CoolingStrategy> createCoolingStrategy(const CoolingType coolingType);
    
public:
    TemperatureClassifier(const CoolingType coolingType);
    
    void setCoolingType(const CoolingType coolingType);
    
    BreachType getBreachType(double temperatureInC) const;
};
