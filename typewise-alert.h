#pragma once
#include <memory>
#include "BreachType.h"

class CoolingStrategy
{
    public:
    virtual ~CoolingStrategy()= default;
    virtual BreachType inferBreach(double value) const = 0;
};

class PassiveCooling : public CoolingStrategy
{
    public:
    BreachType inferBreach(double value) const override;
};

class HiActiveCooling : public CoolingStrategy
{
    public:
    BreachType inferBreach(double value) const override;
};

class MedActiveCooling : public CoolingStrategy
{
    public:
    BreachType inferBreach(double value) const override;
};

class CoolingContext 
{
  private:
  std::unique_ptr<CoolingStrategy> strategy;
  
  public:
  CoolingContext(std::unique_ptr<CoolingStrategy> strategy);
  BreachType inferBreach(double value) const;  
};


typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
