#include "WirelessMedicalSensor.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    WirelessMedicalSensor<double> a("wireless_001", 1, 36.678);
    a.send_T();

    double temperature;
    while (true)
    {
        std::cout << "Введите температуру: ";
        std::cin >> temperature;

        try
        {
            WirelessMedicalSensor<double> b("wireless_002", 2, temperature);
            b.send_T();
            break;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}
