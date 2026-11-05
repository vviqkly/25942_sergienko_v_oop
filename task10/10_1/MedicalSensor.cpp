#include "TemperatureSensor.cpp"

template <typename NUMBER>
class MedicalSensor : public TemperatureSensor<NUMBER>
{
	static NUMBER check_temperature(NUMBER value);
public:
	void beep() const;
	MedicalSensor(std::string factory_id, int set_id, NUMBER temperature);
	void setTemperature(NUMBER value) override;
};

template <typename NUMBER>
static NUMBER MedicalSensor<NUMBER>::check_temperature(NUMBER value)
{
	if (value < 34.0 || value > 42.0)
	{
		throw std::out_of_range("Температура должна быть от 34 до 42");
	}
	return value;
}

template <typename NUMBER>
void MedicalSensor<NUMBER>::beep() const
{
	std::cout << "измерения окончены";
}

template <typename NUMBER>
MedicalSensor<NUMBER>::MedicalSensor(std::string factory_id, int set_id, NUMBER temperature) :
	TemperatureSensor<NUMBER>(factory_id, set_id, check_temperature(temperature)) {
}

template <typename NUMBER>
void MedicalSensor<NUMBER>::setTemperature(NUMBER value)
{
	TemperatureSensor<NUMBER>::setTemperature(check_temperature(value));
}
