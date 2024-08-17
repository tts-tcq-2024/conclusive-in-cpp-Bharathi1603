#include "typewise-alert.h"
#include <stdio.h>

BreachType PassiveCooling::inferBreach(double value) const
{
    if (value < 0.0) 
    {
        return BreachType::TOO_LOW;
    }
    else if (value > 35.0) 
    {
        return BreachType::TOO_HIGH;
    }
    return BreachType::NORMAL; 
}

BreachType HiActiveCooling::inferBreach(double value) const
{
    if (value < 0.0) 
    {
        return BreachType::TOO_LOW;
    }
    else if (value > 45.0) 
    {
        return BreachType::TOO_HIGH;
    }
    return BreachType::NORMAL; 
}

BreachType MedActiveCooling::inferBreach(double value) const
{
    if (value < 0.0) 
    {
        return BreachType::TOO_LOW;
    }
    else if (value > 40.0) 
    {
        return BreachType::TOO_HIGH;
    }
    return BreachType::NORMAL; 
}


/*
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  switch(coolingType) {
    case PASSIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 40;
      break;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
*/
