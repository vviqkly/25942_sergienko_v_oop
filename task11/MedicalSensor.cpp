#include <string>
#include <cmath>
#include <iostream>
#include <stdexcept>

template<typename NUMBER>
class MedicalSensor
{
    NUMBER temperature;
    void normalize_temperature(NUMBER value);
public:
    MedicalSensor();
    MedicalSensor(NUMBER temperature);
    NUMBER getTemperature() const;
    void setTemperature(NUMBER value);
    void print() const;
};

template<typename NUMBER>
NUMBER MedicalSensor<NUMBER>::normalize_temperature(NUMBER value)
{
    if (value < 34) value = 34;
    if (value > 42) value = 42;
    return value;
}

template<typename NUMBER>
MedicalSensor<NUMBER>::MedicalSensor() : temperature(36.6) {
}

template<typename NUMBER>
MedicalSensor<NUMBER>::MedicalSensor(NUMBER temperature) :
    temperature(normalize_temperature(temperature)) {
}

template<typename NUMBER>
NUMBER MedicalSensor<NUMBER>::getTemperature() const
{
    return temperature;
}

template<typename NUMBER>
void MedicalSensor<NUMBER>::setTemperature(NUMBER value)
{
    temperature = normalize_temperature(value);
}

template<typename NUMBER>
void MedicalSensor<NUMBER>::print() const
{
    std::cout << "temperature: " << temperature << " C\n";
}


