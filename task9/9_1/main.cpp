#include "Manufacturer.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    TemperatureSensor<double> a("sv_001", 1, 2.5);

    std::cout << "До калибровки:\n";
    a.print();

    calibrate_zero(a, -2.5);

    std::cout << "После калибровки:\n";
    a.print();

    Manufacturer manufacturer;
    manufacturer.set_factory_id(a, "new_001");
    manufacturer.set_set_id(a, 10);
    manufacturer.set_temperature(a, 25.0);

    std::cout << "После настройки производителем:\n";
    a.print();

    return 0;
}
