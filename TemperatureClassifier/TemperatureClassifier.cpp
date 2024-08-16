#include "TemperatureClassifier.h"

TemperatureClassifier::TemperatureClassifier(const CoolingType coolingType) 
{
    strategy = createCoolingStrategy(coolingType);
}

std::unique_ptr<CoolingStrategy> TemperatureClassifier::createCoolingStrategy(const CoolingType coolingType)
{
    auto it = coolingStrategies.find(coolingType);
    if (it != coolingStrategies.end()) 
	{
        return it->second();
    } 
    else 
    {
        throw std::invalid_argument("Unknown Cooling type");
    }
}

void TemperatureClassifier::setCoolingType(const CoolingType coolingType)
{
    strategy = createCoolingStrategy(coolingType);
}

BreachType TemperatureClassifier::inferBreach(double value, double lowerLimit, double upperLimit) const 
{
    if (value < lowerLimit) 
    {
        return BreachType::TOO_LOW;
    }
    if (value > upperLimit) 
    {
        return BreachType::TOO_HIGH;
    }
    return BreachType::NORMAL;
}

BreachType TemperatureClassifier::getBreachType(double temperatureInC) const 
{
    if (strategy) 
    {
        int lowerLimit = strategy->getLowerLimit();
        int upperLimit = strategy->getUpperLimit();
        return inferBreach(temperatureInC, lowerLimit, upperLimit);
    }

    std::cerr << "No cooling strategy set" << std::endl;
    return BreachType::NORMAL;
}
