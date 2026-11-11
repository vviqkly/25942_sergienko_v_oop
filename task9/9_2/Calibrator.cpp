#include "TemperatureSensor.cpp"

template<typename NUMBER>
void Calibrator::set_zero_offset(TemperatureSensor<NUMBER>& sensor, NUMBER offset)
{
    sensor.zero_offset = offset;
}

template<typename NUMBER>
void Calibrator::reset_zero_offset(TemperatureSensor<NUMBER>& sensor)
{
    sensor.zero_offset = 0;
}

template<typename NUMBER>
void Calibrator::print_temperature(const TemperatureSensor<NUMBER>& sensor)
{
    std::cout << "Температура: " << sensor.getTemperature() << " C\n";
}
