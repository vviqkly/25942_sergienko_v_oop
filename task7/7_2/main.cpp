#include "TemperatureSensor.cpp"

int main()
{
    TemperatureSensor::print_count();
    TemperatureSensor a;
    TemperatureSensor b("SN-001", 1, 25.5);
    TemperatureSensor c = b;
    a = b;

    a.print();
    b.print();
    c.print();
    TemperatureSensor::print_count();
  
    return 0;
}
