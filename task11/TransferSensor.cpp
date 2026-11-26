#include "MedicalSensor.cpp"
#include <string>

template<typename NUMBER>
class TransferSensor : protected MedicalSensor
{
	std::string protocol;
public:
	TransferSensor();
	TransferSensor(NUMBER temperature, std::string protocol);
	void print_protocol() const;
};

template<typename NUMBER>
TransferSensor<NUMBER>::TransferSensor() : MedicalSensor<NUMBER>(), protocol("wire") {
}

template<typename NUMBER>
TransferSensor<NUMBER>::TransferSensor(NUMBER temperature, std::string protocol) :
	MedicalSensor<NUMBER>(temperature), protocol(protocol) {
}

template<typename NUMBER>
void TransferSensor<NUMBER>::print_protocol() const
{
	std::cout << "protocol: " << protocol << "\n";
}
