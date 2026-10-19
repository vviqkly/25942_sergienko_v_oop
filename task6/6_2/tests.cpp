
#include <gtest/gtest.h>
#include "TemperatureSensor.cpp"

TEST(TemperatureSensorTest, TemperatureRange) {
    TemperatureSensor sensor("SN-001", 1, 1500.0);

    EXPECT_DOUBLE_EQ(sensor.getTemperature(), 1000.0);

    sensor.setTemperature(-500.0);

    EXPECT_DOUBLE_EQ(sensor.getTemperature(), -273.0);
}
