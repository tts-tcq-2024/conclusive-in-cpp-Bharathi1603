#include <gtest/gtest.h>
// #include "typewise-alert.h"
#include "TemperatureClassifier.h"

TemperatureClassifier classifier(CoolingType::PASSIVE);
TEST(TypeWiseAlertTestSuite, PassiveCoolingBreach) {
    EXPECT_EQ(classifier.getBreachType(-1), BreachType::TOO_LOW);
}
