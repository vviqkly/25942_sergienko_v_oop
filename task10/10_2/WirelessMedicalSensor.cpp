#include "MedicalSensor.cpp"

template<typename NUMBER>
class WirelessMedicalThermometer final : private MedicalThermometer<NUMBER>
{
public:
    WirelessMedicalThermometer(std::string factory_id, int set_id, NUMBER temperature);
    void send_T() const;
};

template<typename NUMBER>
WirelessMedicalThermometer<NUMBER>::WirelessMedicalThermometer(std::string factory_id, int set_id, NUMBER temperature)
    : MedicalThermometer<NUMBER>(factory_id, set_id, temperature) {
}

template<typename NUMBER>
void WirelessMedicalThermometer<NUMBER>::send_T() const
{
    std::cout << "Температура " << this->getTemperature() << " C успешно передана.\n";
}
