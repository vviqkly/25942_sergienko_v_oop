#include "SoundSensor.cpp"
#include "TransferSensor.cpp"

template<typename NUMBER>
class GeneralSensor : protected SoundSensor, protected TransferSensor
{
public:
	GeneralSensor();
	GeneralSensor(NUMBER temperature, NUMBER tone, std::string protocol);
	void print() const;
};

template<typename NUMBER>
GeneralSensor<NUMBER>::GeneralSensor() : SoundSensor<NUMBER>(), protocol("wire") {
}

template<typename NUMBER>
GeneralSensor<NUMBER>::GeneralSensor(NUMBER temperature, NUMBER tone, std::string protocol) :
	SoundSensor<NUMBER>(temperature, tone), TransferSensor<NUMBER>(temperature, protocol) {
}

template<typename NUMBER>
void GeneralSensor<NUMBER>::print() const
{
	std::cout << "temperature: " << temperature << "tone: " << tone << "protocol: " << protocol << "\n";
}
