#include "TemperatureSensor"
#include <gtest/gtest.h>

class TemperatureSensorTest : public testing::Test {
    protected:
    TemperatureSensor<double> a{ "sv_004", 1, -20.5 };
    TemperatureSensor<double> b{ "sv_001", 2, 10 };
    TemperatureSensor<int> a{ "sv_002", 3, 33 };
};

TEST_F(TemperatureSensorTest, InitializeSensor) {
    EXPECT_EQ("sv_004", a.getFactoryId());
    EXPECT_DOUBLE_EQ(1, a.getSetId());
    EXPECT_DOUBLE_EQ(-20.5, getTemperature());
    EXPECT_EQ(1, a.getUniqueId());
    EXPECT_EQ(2, TemperatureSensor<double>::getCount());
    EXPECT_EQ(1, TemperatureSensor<int>::getCount());
}

TEST_F(TemperatureSensorTest, SetTemperatureAndHistory) {
    a.setTemperature(200.0);
    EXPECT_EQ(a.getTemperature(), 200);
    EXPECT_DOUBLE_EQ(-20.5, getHistory(0));

    a.setTemperature(-333.3);
    EXPECT_EQ(a.getTemperature(), -273.0);
    EXPECT_DOUBLE_EQ(200.0, getHistory(0));
    EXPECT_DOUBLE_EQ(-20.5, getHistory(1));

    a.setTemperature(1032.2);
    EXPECT_EQ(a.getTemperature(), 1000.0);
    EXPECT_DOUBLE_EQ(-20.5, getHistory(2));
    EXPECT_DOUBLE_EQ(200.0, getHistory(1));
    EXPECT_DOUBLE_EQ(-273.0, getHistory(0));
}
