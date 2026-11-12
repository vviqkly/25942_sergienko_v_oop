#include "MedicalSensor.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    MedicalSensor<double> a("med_001", 1, 36.6);
    a.print();
    a.setTemperature(37.33);
    a.print();

    MedicalSensor<double> b("med_001", 1, 36.6);

    double temperature;
    while (true)
    {
        std::cout << "Введите температуру: ";
        std::cin >> temperature;

        try
        {
            b.setTemperature(temperature);
            b.print();
            break;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}
