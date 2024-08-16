#include "ControllerAlert.h"

void ControllerAlert::send(BreachType breachType) const 
{
    const unsigned short header = 0xfeed;
    std::cout << std::hex << header << " : " << static_cast<std::uint16_t>(breachType) << std::endl;
}
