#pragma once

#include <iostream>
#include "CoolingStrategy.h"

class PassiveCooling : public CoolingStrategy 
{
public:
    int getLowerLimit() const override 
    {
        return 0;
    }
    
    int getUpperLimit() const override 
    {
        return 35;
    }
};
