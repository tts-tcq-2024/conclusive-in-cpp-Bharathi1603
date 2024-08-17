#include <gtest/gtest.h>
#include "typewise-alert.h"
#include "TemperatureClassifier.h"

TEST(TypeWiseAlertTestSuite, PassiveCoolingBreach) 
{
    TemperatureClassifier classifier(CoolingType::PASSIVE);
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
    EXPECT_EQ(classifier.getBreachType(36), BreachType::TOO_HIGH);
    EXPECT_EQ(classifier.getBreachType(30), BreachType::NORMAL);
}

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
