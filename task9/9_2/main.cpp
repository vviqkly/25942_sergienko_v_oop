#include "Calibrator.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    TemperatureSensor<double> sensor("sv_001", 1, 2.5);
    Calibrator calibrator;

    std::cout << "До настройки:\n";
    calibrator.print_temperature(sensor);

    calibrator.set_zero_offset(sensor, -2.5);
    std::cout << "После настройки:\n";
    calibrator.print_temperature(sensor);

    calibrator.reset_zero_offset(sensor);
    std::cout << "После сброса:\n";
    calibrator.print_temperature(sensor);

    return 0;
}
