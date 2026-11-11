#include "TemperatureSensor.cpp"

template<typename NUMBER>
class WeatherStation
{
    TemperatureSensor<NUMBER> internal_sensor;
    TemperatureSensor<NUMBER>& external_sensor1;
    TemperatureSensor<NUMBER>& external_sensor2;

public:
    WeatherStation(TemperatureSensor<NUMBER>& sensor1, TemperatureSensor<NUMBER>& sensor2);

    void print() const;
};

template<typename NUMBER>
WeatherStation<NUMBER>::WeatherStation(TemperatureSensor<NUMBER>& sensor1, TemperatureSensor<NUMBER>& sensor2)
    : internal_sensor("built_in", 1, 20), external_sensor1(sensor1), external_sensor2(sensor2) {
}

template<typename NUMBER>
void WeatherStation<NUMBER>::print() const
{
    std::cout << "Встроенный датчик:\n";
    internal_sensor.print();

    std::cout << "Внешний датчик 1:\n";
    external_sensor1.print();

    std::cout << "Внешний датчик 2:\n";
    external_sensor2.print();
}
