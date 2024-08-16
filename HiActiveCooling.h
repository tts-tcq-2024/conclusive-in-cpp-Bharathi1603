#pragma once

#include <iostream>
#include "CoolingStrategy.h"

class HiActiveCooling : public CoolingStrategy 
{
public:
    int getLowerLimit() const override 
    {
        return 0;
    }
    int getUpperLimit() const override 
    {
        return 45;
    }
};
