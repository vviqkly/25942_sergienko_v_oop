#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include "3_1.h"

// M = 10, N = 200, T1 = double, T2 = int

int main()
{
    const int M = 10;
    const int N = 200;
    using T1 = double;
    using T2 = int;

    // Генератор для заполнения контейнеров
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T1> dist(-N, N);

    // Второе число для функции
    T1 second = dist(gen);
    std::cout << "Second arg for function = " << second << "\n\n";

    // Контейнеры
    std::array<T1, M> arr;
    std::vector<T1> vec(M);
    std::list<T1> lst;
    std::deque<T1> deq;

    // Заполнение
    for (int i = 0; i < M; ++i)
        arr[i] = dist(gen);

    for (int i = 0; i < M; ++i)
        vec[i] = dist(gen);

    for (int i = 0; i < M; ++i)
        lst.push_back(dist(gen));

    for (int i = 0; i < M; ++i)
        deq.push_back(dist(gen));

    // Классический for
    std::cout << "array (classic for): ";
    for (int i = 0; i < M; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Итераторы
    std::cout << "vector (iterators):    ";
    for (std::vector<T1>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // Range-based
    std::cout << "list (range-based): ";
    for (const T1& x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    // deque — range-based
    std::cout << "deque (range-based): ";
    for (const T1& x : deq)
        std::cout << x << " ";
    std::cout << "\n\n";

    // Результаты в другие контейнеры
    std::vector<T2> resVec;
    std::list<T2> resLst;
    std::deque<T2> resDeq;

    // array to vector
    for (int i = 0; i < M; ++i)
        resVec.push_back(modified::add<T1, T2>(arr[i], second));

    // vector to list
    for (std::vector<T1>::iterator it = vec.begin(); it != vec.end(); ++it)
        resLst.push_back(modified::add<T1, T2>(*it, second));

    // list to deque
    for (const T1& x : lst)
        resDeq.push_back(modified::add<T1, T2>(x, second));

    // Таблица в md
    std::ofstream out("table.md");
    out << "| array | vector | list | deque | array to vector | vector to list | list to deque |\n";
    out << "|-------|--------|------|-------|-----------------|----------------|---------------|\n";

    std::array<T1, M>::iterator itArr = arr.begin();
    std::vector<T1>::iterator itVec = vec.begin();
    std::list<T1>::iterator itLst= lst.begin();
    std::deque<T1>::iterator itDeq = deq.begin();
    std::vector<T2>::iterator itRV = resVec.begin();
    std::list<T2>::iterator itRL = resLst.begin();
    std::deque<T2>::iterator itRD = resDeq.begin();

    for (int i = 0; i < M; ++i)
    {
        out << "| " << *itArr << " | " << *itVec << " | " << *itLst << " | "
            << *itDeq << " | " << *itRV << " | " << *itRL << " | " << *itRD << " |\n";
        ++itArr; ++itVec; ++itLst; ++itDeq;
        ++itRV;  ++itRL;  ++itRD;
    }

    out.close();

    return 0;
}