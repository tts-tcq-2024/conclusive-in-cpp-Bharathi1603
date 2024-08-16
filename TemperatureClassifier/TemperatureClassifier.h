#pragma once

#include <iostream>
#include <memory>

#include "CoolingStrategy.h"
#include "BreachType.h"


class TemperatureClassifier 
{
private:
    std::unique_ptr<CoolingStrategy> strategy;
    BreachType inferBreach(double value, double lowerLimit, double upperLimit) const;
    
public:
    TemperatureClassifier(std::unique_ptr<CoolingStrategy> strategy);
    
    void setStrategy(std::unique_ptr<CoolingStrategy> strategy);
    
    BreachType getBreachType(double temperatureInC) const;
};
