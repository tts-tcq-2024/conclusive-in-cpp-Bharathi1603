#pragma once

#include <iostream>

enum class CoolingType :std::uint8_t
{
    PASSIVE = 0x00,
    HI_ACTIVE =0x01,
    MED_ACTIVE = 0x02
};
