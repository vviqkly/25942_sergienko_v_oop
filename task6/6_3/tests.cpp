
#include <gtest/gtest.h>
#include "TemperatureSensor.cpp"

TEST(TemperatureSensorTest, CopyConstructor) {
    TemperatureSensor first("SN-001", 1, 20.0);

    first.setTemperature(25.0);

    TemperatureSensor second = first;

    first.setTemperature(30.0);

    EXPECT_DOUBLE_EQ(second.getTemperature(), 25.0);
    EXPECT_DOUBLE_EQ(second.getHistory(0), 20.0);
    EXPECT_DOUBLE_EQ(first.getHistory(0), 25.0);
}
