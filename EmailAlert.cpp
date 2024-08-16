#include "EmailAlert.h"

void EmailAlert::send(BreachType breachType) const
{
    if(breachType != BreachType::NORMAL)
    {
        const std::string recepient = "a.b@c.com";
        
        auto it = breachMessages.find(breachType);
        if(it != breachMessages.end())
        {
            std::cout << "To: " << recepient << std::endl;
            std::cout << "Hi, " << it->second << std::endl; 
        }
    }
}