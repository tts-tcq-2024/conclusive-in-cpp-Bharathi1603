#pragma once

#include <iostream>

enum class AlertTarget :std::uint8_t
{
    TO_CONTROLLER = 0x00,
    TO_EMAIL =0x01
};