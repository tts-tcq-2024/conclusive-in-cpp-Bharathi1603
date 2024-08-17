#include <gtest/gtest.h>
#include "typewise-alert.h"

// #include "TemperatureClassifier.h"

TEST(TypeWiseAlertTestSuite, PassiveCoolingBreach) 
{
    std::unique_ptr<CoolingContext> coolingObj = std::make_unique<CoolingContext>(std::make_unique<PassiveCooling>());
    EXPECT_EQ(coolingObj.inferBreach(-1), BreachType::TOO_LOW);
    EXPECT_EQ(coolingObj.inferBreach(36), BreachType::TOO_HIGH);
    EXPECT_EQ(coolingObj.inferBreach(30), BreachType::NORMAL);
}
/*
TEST(TypeWiseAlertTestSuite, HiActiveCoolingBreach) 
{
    TemperatureClassifier classifier(CoolingType::HI_ACTIVE);
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
    EXPECT_EQ(classifier.getBreachType(46), BreachType::TOO_HIGH);
    EXPECT_EQ(classifier.getBreachType(30), BreachType::NORMAL);
}

TEST(TypeWiseAlertTestSuite, MediumActiveCoolingBreach) 
{
    TemperatureClassifier classifier(CoolingType::MED_ACTIVE);
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
    EXPECT_EQ(classifier.getBreachType(41), BreachType::TOO_HIGH);
    EXPECT_EQ(classifier.getBreachType(30), BreachType::NORMAL);
}
*/
