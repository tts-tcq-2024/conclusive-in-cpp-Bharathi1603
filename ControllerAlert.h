#pragma once

#include <iostream>

#include "AlertStrategy.h"

class ControllerAlert : public AlertStrategy 
{
public:
    void send(BreachType breachType) const override;
};