#include "TemperatureSensor.cpp"
#include <iostream>

int main() 
{
    TemperatureSensor a;
    TemperatureSensor b("SN-001", 1, 25.5);
    b.setTemperature(27.0);
    TemperatureSensor c = b;             // копирование
    a = b;                               // присваивание

    a.print();                          
    b.print();
    c.print();
    
    TemperatureSensor d("SN-002", 2, 1500.0);
    d.print();                                           // нормализация температуры
}
