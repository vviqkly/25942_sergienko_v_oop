#include "MedicalSensor.cpp"

template<typename NUMBER>
class SoundSensor : protected MedicalSensor
{
	int tone;
public:
	SoundSensor();
	SoundSensor(NUMBER temperature, int tone);
	void beep() const;
};

template<typename NUMBER>
SoundSensor<NUMBER>::SoundSensor() : MedicalSensor(), tone(2000) {
}

template<typename NUMBER>
SoundSensor<NUMBER>::SoundSensor(NUMBER temperature, int tone) :
	MedicalSensor<NUMBER>(temperature), tone(tone){
}

template<typename NUMBER>
void SoundSensor<NUMBER>::beep() const
{
	std::cout << "beep!, tone: " << tone;
}
