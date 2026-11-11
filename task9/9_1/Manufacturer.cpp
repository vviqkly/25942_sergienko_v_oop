#include "TemperatureSensor.cpp"

class Manufacturer
{
public:
    template<typename NUMBER>
    void set_factory_id(TemperatureSensor<NUMBER>& sensor, const std::string& value);

    template<typename NUMBER>
    void set_set_id(TemperatureSensor<NUMBER>& sensor, int value);

    template<typename NUMBER>
    void set_temperature(TemperatureSensor<NUMBER>& sensor, NUMBER value);

    template<typename NUMBER>
    void set_zero_offset(TemperatureSensor<NUMBER>& sensor, NUMBER value);

    template<typename NUMBER>
    void set_history(TemperatureSensor<NUMBER>& sensor, int index, NUMBER value);
};

template<typename NUMBER>
void Manufacturer::set_factory_id(TemperatureSensor<NUMBER>& sensor, const std::string& value)
{
    sensor.factory_id = TemperatureSensor<NUMBER>::check_factory_id(value);
}

template<typename NUMBER>
void Manufacturer::set_set_id(TemperatureSensor<NUMBER>& sensor, int value)
{
    sensor.set_id = value;
}

template<typename NUMBER>
void Manufacturer::set_temperature(TemperatureSensor<NUMBER>& sensor, NUMBER value)
{
    sensor.setTemperature(value);
}

template<typename NUMBER>
void Manufacturer::set_zero_offset(TemperatureSensor<NUMBER>& sensor, NUMBER value)
{
    sensor.zero_offset = value;
}

template<typename NUMBER>
void Manufacturer::set_history(TemperatureSensor<NUMBER>& sensor, int index, NUMBER value)
{
    if (index < 0 || index >= 10)
    {
        throw std::out_of_range("Неверный индекс (0..9)");
    }

    if (sensor.history == nullptr)
    {
        sensor.history = new NUMBER[10]{};
    }

    sensor.history[index] = value;
}
