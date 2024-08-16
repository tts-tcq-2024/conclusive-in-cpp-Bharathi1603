#include <gtest/gtest.h>
// #include "typewise-alert.h"
#include "TemperatureClassifier.h"

TemperatureClassifier classifier(CoolingType::PASSIVE);
TEST(TypeWiseAlertTestSuite, PassiveCoolingBreach) {
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
    EXPECT_EQ(classifier.getBreachType(36), BreachType::TOO_HIGH);
    EXPECT_EQ(classifier.getBreachType(30), BreachType::NORMAL);
}

classifier.setCoolingType(CoolingType::HI_ACTIVE);
TEST(TypeWiseAlertTestSuite, HiActiveCoolingBreach) {
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
    EXPECT_EQ(classifier.getBreachType(46), BreachType::TOO_HIGH);
    EXPECT_EQ(classifier.getBreachType(30), BreachType::NORMAL);
}

classifier.setCoolingType(CoolingType::MED_ACTIVE);
TEST(TypeWiseAlertTestSuite, MediumActiveCoolingBreach) {
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
    EXPECT_EQ(classifier.getBreachType(41), BreachType::TOO_HIGH);
    EXPECT_EQ(classifier.getBreachType(30), BreachType::NORMAL);
}
