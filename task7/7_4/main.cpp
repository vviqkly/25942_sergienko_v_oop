#include "TemperatureSensor.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    TemperatureSensor sensor("sv_004", 1, 11.0);
    double temperature;

    while (true)
    {
        std::cout << "Введите температуру: ";

        if (!(std::cin >> temperature))
        {
            std::cout << "Введите число\n";
        }

        try
        {
            sensor.setTemperature(temperature);
            break;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    sensor.print();

    return 0;
}
