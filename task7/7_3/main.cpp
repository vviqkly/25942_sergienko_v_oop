#include "TemperatureSensor.cpp"

int main()
{
    std::cout << "Static values:\n";
    TemperatureSensor::print_count();
    std::cout << "\n";

    std::cout << "Sensor creation:\n";
    TemperatureSensor first("sv_004", 1, 20.0);
    first.print();
    first.print_count();
    std::cout << "\n";

    std::cout << "Second sensor:\n";
    TemperatureSensor second{first};
    second.print();

    second.setTemperature(200);
    first.setTemperature(1010.0);
    second.print();

    {
        std::cout << "Inside {}:\n";
        TemperatureSensor second{first};
        second.print();

        second.setTemperature(30.0);
        first.setTemperature(40.0);
        second.print();
    }

    std::cout << "Outside {}:\n";
    second.print();

    return 0;
}
