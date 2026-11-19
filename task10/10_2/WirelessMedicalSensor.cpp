#include "MedicalSensor.cpp"

template <typename NUMBER>
class WirelessMedicalSensor final : private MedicalSensor<NUMBER>
{
public:
    // 10_3 
    using MedicalSensor<NUMBER>::beep();
    WirelessMedicalSensor(std::string factory_id, int set_id, NUMBER temperature);
    void send_T() const;
};

template <typename NUMBER>
WirelessMedicalSensor<NUMBER>::WirelessMedicalSensor(std::string factory_id, int set_id, NUMBER temperature) :
    MedicalSensor<NUMBER>(factory_id, set_id, temperature) {
}

template <typename NUMBER>
void WirelessMedicalSensor<NUMBER>::send_T() const
{
    std::cout << "Температура " << this->getTemperature() << " C успешно передана\n";
}
