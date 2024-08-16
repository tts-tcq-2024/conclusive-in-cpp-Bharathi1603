#pragma once

#include <iostream>
#include "BreachType.h"

class AlertStrategy 
{
public:
    virtual ~AlertStrategy() = default;
    virtual void send(BreachType breachType) const = 0;
};