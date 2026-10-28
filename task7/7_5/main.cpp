#include "TemperatureSensor.cpp"
#include <windows.h>

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    TemperatureSensor sensor("sv_004", 1, 20.0);

    std::cout << "До ввода:\n";
    std::cout << sensor << "\n";

    while (true)
    {
        std::cout << "Введите set_id и температуру: ";

        try
        {
            if (!(std::cin >> sensor))
            {
                std::cout << "Введите 2 числа\n";
                return 1;
            }
            break;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    std::cout << "После ввода:\n";
    std::cout << sensor << "\n";

    return 0;
}
