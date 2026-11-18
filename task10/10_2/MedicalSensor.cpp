#include "TemperatureSensor.cpp"

template <typename NUMBER>
class MedicalSensor : protected TemperatureSensor<NUMBER>
{
    NUMBER precision;
    NUMBER check_temperature(NUMBER value);

public:
    using TemperatureSensor<NUMBER>::print;
    using TemperatureSensor<NUMBER>::getTemperature;

    void beep() const;
    MedicalSensor(std::string factory_id, int set_id, NUMBER temperature);
    void setTemperature(NUMBER value);
    NUMBER getPrecision() const;
};

template <typename NUMBER>
NUMBER MedicalSensor<NUMBER>::check_temperature(NUMBER value)
{
    if (!std::isfinite(static_cast<double>(value)) ||
        value < 34.0 || value > 42.0)
    {
        throw std::out_of_range("Температура должна быть от 34 до 42");
    }

    return static_cast<NUMBER>(std::round(value * 100) / 100);
}

template <typename NUMBER>
void MedicalSensor<NUMBER>::beep() const
{
    std::cout << "измерения окончены\n";
}

template <typename NUMBER>
MedicalSensor<NUMBER>::MedicalSensor(
    std::string factory_id, int set_id, NUMBER temperature)
    : TemperatureSensor<NUMBER>(factory_id, set_id, check_temperature(temperature)),
      precision(0.01)
{
}

template <typename NUMBER>
void MedicalSensor<NUMBER>::setTemperature(NUMBER value)
{
    TemperatureSensor<NUMBER>::setTemperature(check_temperature(value));
    beep();
}

template <typename NUMBER>
NUMBER MedicalSensor<NUMBER>::getPrecision() const
{
    return precision;
}
