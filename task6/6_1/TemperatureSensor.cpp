#include <string>
#include <iostream>


class TemperatureSensor {
    const std::string factory_id;
    int set_id;
    double temperature;
    double history[10];

public:
    TemperatureSensor();
    TemperatureSensor(std::string factory_id, int set_id, double temperature);
    TemperatureSensor(const TemperatureSensor& other);
    TemperatureSensor& operator=(const TemperatureSensor& other);

    void print() const;
};

TemperatureSensor::TemperatureSensor()
    : factory_id("UNKNOWN"), set_id(0), temperature(0.0), history{} {
}

TemperatureSensor::TemperatureSensor(std::string factory_id, int set_id, double temperature)
    : factory_id(factory_id), set_id(set_id), temperature(temperature), history{} {
}

TemperatureSensor::TemperatureSensor(const TemperatureSensor& other)
    : factory_id(other.factory_id), set_id(other.set_id),
      temperature(other.temperature), history{} {
    for (int i = 0; i < 10; ++i) 
    {
        history[i] = other.history[i];
    }
}

TemperatureSensor& TemperatureSensor::operator=(const TemperatureSensor& other) 
{
    if (this != &other) 
    {
        set_id = other.set_id;
        temperature = other.temperature;
        for (int i = 0; i < 10; ++i) 
        {
            history[i] = other.history[i];
        }
    }
    return *this;
}

void TemperatureSensor::print() const 
{
    std::cout << "factory_id: " << factory_id << ", set_id: " << set_id << ", temperature: " << temperature << " C\n";
}
