#pragma once

#include <iostream>

class CoolingStrategy
{
public:
    virtual ~CoolingStrategy() = default;
    virtual int getLowerLimit() const = 0;
    virtual int getUpperLimit() const = 0;
};