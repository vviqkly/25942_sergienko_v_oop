#include "TemperatureSensor.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Double:\n";

    {
        TemperatureSensor<double> a("sv_004", 1, -20.5);
        TemperatureSensor<double> b = a;

        b.setTemperature(36.6);

        std::cout << a << "\n";
        std::cout << b << "\n";
    }

    std::cout << "\nInt:\n";

    {
        TemperatureSensor<int> c("sv_002", 2, 30);

        c.setTemperature(-40);
        std::cout << c << "\n";
    }

    return 0;
}
