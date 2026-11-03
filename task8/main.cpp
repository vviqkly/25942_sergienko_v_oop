
#include "TemperatureSensor.cpp"
#include <windows.h>
#include <utility>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    TemperatureSensor<double> a("sv_001", 1, 20.0);
    a.setTemperature(25.0);

    TemperatureSensor<double> b(a);
    std::cout << b << "\n";

    TemperatureSensor<double> c(std::move(a));
    std::cout << c << "\n";
    std::cout << "a после перемещения: " << a << "\n";

    TemperatureSensor<double> d("sv_002", 2, 10.0);

    d = b;
    std::cout << d << "\n";

    d = std::move(c);
    std::cout << d << "\n";
    std::cout << "История d[0]: " << d.getHistory(0) << "\n";

    return 0;
}
