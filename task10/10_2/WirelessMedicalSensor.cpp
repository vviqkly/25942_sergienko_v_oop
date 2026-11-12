#include "MedicalSensor.cpp"

template <typename NUMBER>
class WirelessMedicalSensor final : private MedicalSensor<NUMBER>
{
public:
	void send_T() const;
};

template <typename NUMBER>
void WirelessMedicalSensor<NUMBER>::send_T() const
{
	std::cout << "\n";
}

