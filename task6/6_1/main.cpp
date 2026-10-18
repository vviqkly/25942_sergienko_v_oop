#include "TemperatureSensor.cpp"

int main() 
{
    TemperatureSensor first;                           // по умолчанию
    TemperatureSensor second("abc_003", 3, -8.7);      // инициализирующий
    TemperatureSensor third = second;                  // копирование 
    first = second;                                    // присваивание

    first.print();
    second.print();
    third.print();
}
