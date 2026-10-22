#include "class.cpp"
#include <iostream>

int main()
{
    TemperatureSensor a("abc-001", 1, 20.0);
    TemperatureSensor b = a;
    TemperatureSensor c("abc-003", 3, 0.0);
    a.setTemperature(30.0);
    c = a;

    a.setTemperature(23.0);
    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();
    std::cout << "c: "; c.print();
    std::cout << "b history[0]: " << b.getHistory(0) << " C\n";
}
