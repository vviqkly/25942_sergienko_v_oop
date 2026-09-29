#include <iostream>
#include <memory>

int main()
{
    // Обычный указатель
    std::cout << "simple pointer\n";
    int* raw = new int(42);
    std::cout << "*raw = " << *raw << "\n";
    delete raw;
    // std::cout << *raw;   // UB
    raw = nullptr;

    // unique_ptr (одмн владелец)
    std::cout << "unique_ptr\n";
    std::unique_ptr<int> u = std::make_unique<int>(42);
    std::cout << "*u = " << *u << "\n";
    // std::unique_ptr<int> u2 = u;   // ошибка компиляции
    
    // shared_ptr (несколько владельцев)
    std::cout << "shared_ptr\n";
    std::shared_ptr<int> sp1 = std::make_shared<int>(100);
    std::cout << "sp1 use_count = " << sp1.use_count() << "\n";

    {
        std::shared_ptr<int> sp2 = sp1;
        std::shared_ptr<int> sp3 = sp1;
        std::cout << "Inside block use_count = " << sp1.use_count() << "\n";
    }

    std::cout << "After block use_count = " << sp1.use_count() << "\n\n";

    // unique_ptr на массив
    std::cout << "unique_ptr on array\n";
    const int SIZE = 7;
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(SIZE);

    std::cout << "Array (insert " << SIZE << " numbers): ";

    for (int i = 0; i < SIZE; ++i)
        std::cin >> arr[i];

    std::cout << "arr: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}