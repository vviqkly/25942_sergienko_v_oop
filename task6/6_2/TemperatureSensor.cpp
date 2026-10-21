#include <string>
#include <cmath>
#include <iostream>
#include <stdexcept>

class TemperatureSensor {
    std::string factory_id;
    int set_id;
    double temperature;

    static std::string check_factory_id(const std::string& value);
    static double normalize_temperature(double value);

public:
    TemperatureSensor();
    TemperatureSensor(std::string factory_id, int set_id, double temperature);
    TemperatureSensor(const TemperatureSensor& other);
    TemperatureSensor& operator=(const TemperatureSensor& other);

    const std::string& getFactoryId() const;
    int getSetId() const;
    double getTemperature() const;

    void setSetId(int value);
    void setTemperature(double value);
    void print() const;
};

std::string TemperatureSensor::check_factory_id(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument("поле factory_id не должно быть пустым");
    }
    return value;
}

double TemperatureSensor::normalize_temperature(double value)
{
    if (value < -273.0) return -273.0;
    if (value > 500.0) return 500.0;
    return value;
}

TemperatureSensor::TemperatureSensor()
    : factory_id("abc_01"), set_id(0), temperature(0.0) {
    std::cout << "конструктор по умолчанию\n";
}

TemperatureSensor::TemperatureSensor(std::string factory_id, int set_id, double temperature)
    : factory_id(check_factory_id(factory_id)), set_id(set_id), temperature(normalize_temperature(temperature)) {
    std::cout << "инициализирующий конструктор\n";
}

TemperatureSensor::TemperatureSensor(const TemperatureSensor& other)
    : factory_id(other.factory_id), set_id(other.set_id), temperature(other.temperature) {
    std::cout << "конструктор копирования\n";
}

TemperatureSensor& TemperatureSensor::operator=(const TemperatureSensor& other)
{
    if (this != &other)
    {
        set_id = other.set_id;
        temperature = other.temperature;
    }
    std::cout << "оператор присваивания\n";
    return *this;
}

const std::string& TemperatureSensor::getFactoryId() const 
{
    return factory_id;
}

int TemperatureSensor::getSetId() const 
{
    return set_id;
}

double TemperatureSensor::getTemperature() const 
{
    return temperature;
}

void TemperatureSensor::setSetId(int value)
{
    set_id = value;
}

void TemperatureSensor::setTemperature(double value)
{
    temperature = normalize_temperature(value);
}

void TemperatureSensor::print() const
{
    std::cout << "factory_id: " << factory_id << ", set_id: " << set_id << ", temperature: " << temperature << " C\n";
}
