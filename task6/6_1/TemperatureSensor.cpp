
#include <string>
#include <iostream>

class TemperatureSensor {
    std::string factory_id;
    int set_id;
    double temperature;

public:
    TemperatureSensor();
    TemperatureSensor(std::string factory_id, int set_id, double temperature);
    TemperatureSensor(const TemperatureSensor& other);
    TemperatureSensor& operator=(const TemperatureSensor& other);

    void print() const;
};

TemperatureSensor::TemperatureSensor()
    : factory_id("abc_01"), set_id(0), temperature(0.0) {
    std::cout << "конструктор по умолчанию\n";
}

TemperatureSensor::TemperatureSensor(std::string factory_id, int set_id, double temperature)
    : factory_id(factory_id), set_id(set_id), temperature(temperature) {
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

void TemperatureSensor::print() const
{
    std::cout << "factory_id: " << factory_id << ", set_id: " << set_id << ", temperature: " << temperature << " C\n";
}
