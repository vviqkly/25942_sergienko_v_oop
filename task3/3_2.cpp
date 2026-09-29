#include <iostream>

int main()
{
    // Указатель на одно значение
    int* ptr = new int(33);
    std::cout << "*ptr = " << *ptr << "\n";
    std::cout << "ptr (address) = " << ptr << "\n\n";

    // Указатель на массив
    const int SIZE = 7;
    int* arr = new int[SIZE];
    std::cout << "Array (insert " << SIZE << " numbers): ";

    // ввести с клавиатуры
    for (int i = 0; i < SIZE; ++i)
        std::cin >> arr[i];

    //for (int i = 0; i < SIZE; ++i)
    //    arr[i] = (i+1);

    std::cout << "Original array: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";

    // Висячий указатель
    std::cout << "Dangling pointer\n";
    int* temp = new int(100);
    std::cout << "Before delete *temp = " << *temp << "\n\n";

    delete temp;

    //std::cout << "After delete *temp = : " << *temp << "\n";

    // Вставка в середину массива
    std::cout << "Insert to the middle\n";
    const int NEW_SIZE = SIZE + 1;
    int* newArr = new int[NEW_SIZE];

    int mid = SIZE / 2;         // индекс середины
    int insertValue;
    std::cout << "InsertValue = ";
    std::cin >> insertValue;

    for (int i = 0; i < mid; ++i)
        newArr[i] = arr[i];

    newArr[mid] = insertValue;

    for (int i = mid; i < SIZE; ++i)
        newArr[i + 1] = arr[i];

    std::cout << "New array: ";
    for (int i = 0; i < NEW_SIZE; ++i)
        std::cout << newArr[i] << " ";
    std::cout << "\n\n";

    // Очистка памяти

    delete ptr;        
    ptr = nullptr;
    delete[] arr;         
    arr = nullptr;
    delete[] newArr;      
    newArr = nullptr;

    return 0;
}