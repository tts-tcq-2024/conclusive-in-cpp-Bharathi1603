#pragma once

#include <iostream>
#include "CoolingStrategy.h"

enum class CoolingType :std::uint8_t
{
    PASSIVE = 0x00,
    HI_ACTIVE =0x01,
    MED_ACTIVE = 0x02
};


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

class MedActiveCooling : public CoolingStrategy 
{
public:
    int getLowerLimit() const override 
    {
        return 0;
    }
    int getUpperLimit() const override 
    {
        return 40;
    }
};