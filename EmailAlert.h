#pragma once

#include <iostream>
#include <map>

#include "AlertStrategy.h"

class EmailAlert : public AlertStrategy 
{
public:
    void send(BreachType breachType) const override;

private:
    const std::map<const BreachType, std::string> breachMessages =
    {
        {BreachType::TOO_LOW, "the temperature is too low"},
        {BreachType::TOO_HIGH, "the temperature is too high"},
    };
};
