#include <gtest/gtest.h>
#include "TemperatureSensor.cpp"

TEST(TemperatureSensorTest, DefaultConstructor) 
{
    TemperatureSensor sensor;
    
    EXPECT_EQ(sensor.getFactoryId(), "abc_01");
    EXPECT_EQ(sensor.getSetId(), 0);
    EXPECT_DOUBLE_EQ(sensor.getTemperature(), 0.0);
}

TEST(TemperatureSensorTest, InitializationConstructor) 
{
    TemperatureSensor sensor("SN-001", 1, 25.5);
    
    EXPECT_EQ(sensor.getFactoryId(), "SN-001");
    EXPECT_EQ(sensor.getSetId(), 1);
    EXPECT_DOUBLE_EQ(sensor.getTemperature(), 25.5);
}

TEST(TemperatureSensorTest, CopyConstructor) 
{
    TemperatureSensor first("SN-001", 1, 25.5);
    TemperatureSensor second = first;
    
    EXPECT_EQ(second.getFactoryId(), first.getFactoryId());
    EXPECT_EQ(second.getSetId(), first.getSetId());
    EXPECT_DOUBLE_EQ(second.getTemperature(), first.getTemperature());
}

TEST(TemperatureSensorTest, AssignmentOperator) 
{
    TemperatureSensor first("SN-001", 1, 25.5);
    TemperatureSensor second("SN-002", 2, 30.0);
    second = first;

    EXPECT_EQ(second.getFactoryId(), "SN-002");
    EXPECT_EQ(second.getSetId(), 1);
    EXPECT_DOUBLE_EQ(second.getTemperature(), 25.5);
}

TEST(TemperatureSensorTest, FactoryIdValidation) 
{
    EXPECT_THROW(TemperatureSensor("", 1, 25.0),std::invalid_argument);
}

TEST(TemperatureSensorTest, TemperatureNormalization) 
{
    TemperatureSensor sensor("SN-001", 1, 600.0);
    EXPECT_DOUBLE_EQ(sensor.getTemperature(), 500.0);

    sensor.setTemperature(-300.0);
    EXPECT_DOUBLE_EQ(sensor.getTemperature(), -273.0);
}

TEST(TemperatureSensorTest, Setters) 
{
    TemperatureSensor sensor("SN-001", 1, 20.0);
    sensor.setSetId(5);
    sensor.setTemperature(35.0);

    EXPECT_EQ(sensor.getSetId(), 5);
    EXPECT_DOUBLE_EQ(sensor.getTemperature(), 35.0);
}
