
#include "TemperatureSensor.cpp"
#include <vector>
#include <list>
#include <set>
#include <windows.h>

bool operator<(const TemperatureSensor& a, const TemperatureSensor& b)
{
    return a.getFactoryId() < b.getFactoryId();
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Start:\n";
    TemperatureSensor::print_count();
    std::cout << "\n";

    {
        std::cout << "Vector:\n";
        std::vector<TemperatureSensor> v;
        v.reserve(4);

        for (int i = 1; i <= 4; ++i)
        {
            v.emplace_back("V" + std::to_string(i), i, 20.0 * i);
        }
        TemperatureSensor::print_count();
        std::cout << "\n";

        std::cout << "List:\n";
        std::list<TemperatureSensor> l;

        for (int i = 1; i <= 4; ++i)
        {
            l.emplace_back("L" + std::to_string(i), i, 25.0 * i);
        }
        TemperatureSensor::print_count();
        std::cout << "\n";

        std::cout << "Set:\n";
        std::set<TemperatureSensor> s;

        for (int i = 1; i <= 4; ++i)
        {
            s.emplace("S" + std::to_string(i), i, 30.0 * i);
        }
        TemperatureSensor::print_count();
    }

    std::cout << "\n";
    std::cout << "End:\n";
    TemperatureSensor::print_count();

    return 0;
}
