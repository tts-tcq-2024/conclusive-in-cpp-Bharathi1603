#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, PassiveCoolingBreach) 
{
    std::unique_ptr<CoolingContext> coolingObj = std::make_unique<CoolingContext>(std::make_unique<PassiveCooling>());
    EXPECT_EQ(coolingObj->inferBreach(-1), BreachType::TOO_LOW);
    EXPECT_EQ(coolingObj->inferBreach(36), BreachType::TOO_HIGH);
    EXPECT_EQ(coolingObj->inferBreach(30), BreachType::NORMAL);
}

TEST(TypeWiseAlertTestSuite, HiActiveCoolingBreach) 
{
    std::unique_ptr<CoolingContext> coolingObj = std::make_unique<CoolingContext>(std::make_unique<HiActiveCooling>());
    EXPECT_EQ(coolingObj->inferBreach(-1), BreachType::TOO_LOW);
    EXPECT_EQ(coolingObj->inferBreach(46), BreachType::TOO_HIGH);
    EXPECT_EQ(coolingObj->inferBreach(30), BreachType::NORMAL);
}

TEST(TypeWiseAlertTestSuite, MediumActiveCoolingBreach) 
{
    std::unique_ptr<CoolingContext> coolingObj = std::make_unique<CoolingContext>(std::make_unique<MedActiveCooling>());
    EXPECT_EQ(coolingObj->inferBreach(-1), BreachType::TOO_LOW);
    EXPECT_EQ(coolingObj->inferBreach(31), BreachType::TOO_HIGH);
    EXPECT_EQ(coolingObj->inferBreach(30), BreachType::NORMAL);
}

