#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int check(char c)
{
    return (c >= '0' && c <= '9') || (c == '-');
}

int main()
{
    std::vector<int> first;
    std::vector<int> second;

    std::ifstream in1("s04_v1_42_1.txt");
    std::ifstream in2("s04_v1_42_2.txt");

    std::string line;
    std::string num;

    // Чтение 1 файла
    if (in1.is_open())
    {
        while (std::getline(in1, line))
        {
            std::string token;

            for (std::size_t i = 0; i < line.size(); ++i)
            {
                char c = line[i];
                if (check(c)) token += c;
                else
                {
                    if (!token.empty())
                    {
                        first.push_back(std::stoi(token));
                        token.clear();
                    }
                }
            }

            if (!token.empty()) first.push_back(std::stoi(token));
        }
    }
    in1.close();

    // Чтение 2 файла
    if (in2.is_open())
    {
        while (std::getline(in2, line))
        {
            std::string token;

            for (std::size_t i = 0; i < line.size(); ++i)
            {
                char c = line[i];
                if (check(c)) token += c;
                else
                {
                    if (!token.empty())
                    {
                        second.push_back(std::stoi(token));
                        token.clear();
                    }
                }
            }

            if (!token.empty()) second.push_back(std::stoi(token));
        }
    }
    in2.close();

    // Кол-во чисел в файлах
    std::cout << "nums in first file: " << first.size() << std::endl;
    std::cout << "nums in second file: " << second.size() << std::endl;
    std::cout << std::endl;

    // Частота через цикл for
    std::cout << "First vector (for)" << std::endl;
    std::vector<int> usedFirst;
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    {
        bool already = false;
        for (std::vector<int>::iterator u = usedFirst.begin(); u != usedFirst.end(); ++u)
        {
            if (*u == *it)
            {
                already = true;
                break;
            }
        }
        if (already) continue;

        int count = 0;
        for (std::vector<int>::iterator j = first.begin(); j != first.end(); ++j)
            if (*j == *it) ++count;

        std::cout << *it << " -> " << count << std::endl;
        usedFirst.push_back(*it);
    }
    std::cout << std::endl;

    std::cout << "Second vector (for)" << std::endl;
    std::vector<int> usedSecond;
    for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    {
        bool already = false;
        for (std::vector<int>::iterator u = usedSecond.begin(); u != usedSecond.end(); ++u)
        {
            if (*u == *it)
            {
                already = true;
                break;
            }
        }
        if (already) continue;

        int count = 0;
        for (std::vector<int>::iterator j = second.begin(); j != second.end(); ++j)
            if (*j == *it) ++count;

        std::cout << *it << " -> " << count << std::endl;
        usedSecond.push_back(*it);
    }
    std::cout << std::endl;

    // Частота через <algorithm>
    std::cout << "First vector (algorithm)" << std::endl;
    std::vector<int> uniqueFirst = first;
    std::sort(uniqueFirst.begin(), uniqueFirst.end());
    uniqueFirst.erase(std::unique(uniqueFirst.begin(), uniqueFirst.end()), uniqueFirst.end());

    for (std::size_t i = 0; i < uniqueFirst.size(); ++i)
        std::cout << uniqueFirst[i] << " -> "
        << std::count(first.begin(), first.end(), uniqueFirst[i]) << std::endl;
    std::cout << std::endl;

    std::cout << "Second vector (algorithm)" << std::endl;
    std::vector<int> uniqueSecond = second;
    std::sort(uniqueSecond.begin(), uniqueSecond.end());
    uniqueSecond.erase(std::unique(uniqueSecond.begin(), uniqueSecond.end()), uniqueSecond.end());

    for (std::size_t i = 0; i < uniqueSecond.size(); ++i)
        std::cout << uniqueSecond[i] << " -> "
        << std::count(second.begin(), second.end(), uniqueSecond[i]) << std::endl;
    std::cout << std::endl;

    // Сумма
    // accumulate
    int sumFirst1 = std::accumulate(first.begin(), first.end(), 0);
    int sumSecond1 = std::accumulate(second.begin(), second.end(), 0);

    // for_each + лямбда
    int sumFirst2 = 0;
    int sumSecond2 = 0;
    std::for_each(first.begin(), first.end(), [&sumFirst2](int x) { sumFirst2 += x; });
    std::for_each(second.begin(), second.end(), [&sumSecond2](int x) { sumSecond2 += x; });

    std::cout << "Sums" << std::endl;
    std::cout << "First  vector: accumulate = " << sumFirst1 << ", for_each = " << sumFirst2 << std::endl;
    std::cout << "Second vector: accumulate = " << sumSecond1 << ", for_each = " << sumSecond2 << std::endl;
    std::cout << std::endl;

    // Сумма первых 10 без циклов
    std::size_t nFirst = (first.size() < 10) ? first.size() : 10;
    std::size_t nSecond = (second.size() < 10) ? second.size() : 10;

    int first10 = std::accumulate(first.begin(), first.begin() + nFirst, 0);
    int second10 = std::accumulate(second.begin(), second.begin() + nSecond, 0);

    std::cout << "First 10 elemants" << std::endl;
    std::cout << "First  vector: " << first10 << std::endl;
    std::cout << "Second vector: " << second10 << std::endl;

    return 0;
}