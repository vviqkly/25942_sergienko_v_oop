#include "MedicalSensor.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    MedicalSensor<double> a("med_001", 1, 36.6);
    a.print();
    a.setTemperature(37.33);
    a.beep();
    a.print();

    return 0;
}
