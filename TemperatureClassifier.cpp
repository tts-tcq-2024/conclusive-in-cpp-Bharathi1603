#include "TemperatureClassifier.h"

TemperatureClassifier::TemperatureClassifier(std::unique_ptr<CoolingStrategy> strategy = nullptr) 
: strategy(std::move(strategy)) 
{
    //Nothing to do
}

void TemperatureClassifier::setStrategy(std::unique_ptr<CoolingStrategy> strategy) 
{
    strategy = std::move(strategy);
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