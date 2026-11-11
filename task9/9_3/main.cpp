#include "WeatherStation.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    TemperatureSensor<double> sensor1("ext_001", 2, 15);
    TemperatureSensor<double> sensor2("ext_002", 3, 18);

    std::cout << "\nДо создания станции: ";
    TemperatureSensor<double>::print_count();

    {
        WeatherStation<double> station(sensor1, sensor2);

        std::cout << "\nМетеостанция:\n";
        station.print();

        std::cout << "\nВо время работы станции: ";
        TemperatureSensor<double>::print_count();
    }

    std::cout << "\nПосле уничтожения станции: ";
    TemperatureSensor<double>::print_count();

    std::cout << "\nВнешние датчики:\n";
    sensor1.print();
    sensor2.print();

    return 0;
}
