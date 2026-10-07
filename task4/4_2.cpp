#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>

int check(char c)
{
    return (c >= '0' && c <= '9') || (c == '-');
}

int binOp(int acc, int x)
{
    if (x % 2 == 0) return acc + x;
    else return acc - x;
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


    // другой способ чтения 
    //std::ifstream in1("file1.txt");
    //std::stringstream buffer;
    //buffer << in1.rdbuf();
    //std::string content = buffer.str();

    //for (std::size_t i = 0; i < content.size(); ++i)
    //    if (content[i] == ',') content[i] = ' ';

    //std::istringstream iss(content);
    //int x;
    //while (iss >> x)
    //    first.push_back(x);
    //in1.close();

    // Уникальные значения
    std::vector<int> uniqueFirst = first;
    std::sort(uniqueFirst.begin(), uniqueFirst.end());
    uniqueFirst.erase(std::unique(uniqueFirst.begin(), uniqueFirst.end()), uniqueFirst.end());

    std::vector<int> uniqueSecond = second;
    std::sort(uniqueSecond.begin(), uniqueSecond.end());
    uniqueSecond.erase(std::unique(uniqueSecond.begin(), uniqueSecond.end()), uniqueSecond.end());

    // Бинарная операция через accumulate
    int binFirst = std::accumulate(first.begin(), first.end(), 0, binOp);

        int binSecond = std::accumulate(second.begin(), second.end(), 0, binOp);

    std::cout << "Binary op" << std::endl;
    std::cout << "First  vector: " << binFirst << std::endl;
    std::cout << "Second vector: " << binSecond << std::endl;
    std::cout << std::endl;

    // Числа, встречающиеся: - в second >= 2 раз
    //                       - в first  >  3 раз

    // second: >= 2 раз
    std::cout << "Second: >= 2 times" << std::endl;
    std::vector<int> dupSecond;
    for (std::size_t i = 0; i < uniqueSecond.size(); ++i)
    {
        int cnt = std::count(second.begin(), second.end(), uniqueSecond[i]);
        if (cnt >= 2)
        {
            std::cout << uniqueSecond[i] << " -> " << cnt << std::endl;
            dupSecond.push_back(uniqueSecond[i]);
        }
    }
    std::cout << std::endl;

    // first: > 3 раз
    std::cout << "First: > 3 times" << std::endl;
    std::vector<int> dupFirst;
    for (std::size_t i = 0; i < uniqueFirst.size(); ++i)
    {
        int cnt = std::count(first.begin(), first.end(), uniqueFirst[i]);
        if (cnt > 3)
        {
            std::cout << uniqueFirst[i] << " -> " << cnt << std::endl;
            dupFirst.push_back(uniqueFirst[i]);
        }
    }
    std::cout << std::endl;

    // Подсчет пересечений через for
    std::cout << "Intersection (for)" << std::endl;
    for (std::vector<int>::iterator it = dupSecond.begin(); it != dupSecond.end(); ++it)
    {
        int x = *it;

        bool inDupFirst = false;
        for (std::vector<int>::iterator j = dupFirst.begin(); j != dupFirst.end(); ++j)
        {
            if (*j == x) { inDupFirst = true; break; }
        }

        if (inDupFirst)
        {
            int cntInFirst = std::count(first.begin(), first.end(), x);
            int cntInSecond = std::count(second.begin(), second.end(), x);

            std::cout << x
                << ": in first = " << cntInFirst
                << ", in second = " << cntInSecond << std::endl;
        }
    }
    std::cout << std::endl;

    // Подсчет пересечений через <algorithm> + лямбда
    std::cout << "Intersection (algorithm + lambda)" << std::endl;
    std::for_each(dupSecond.begin(), dupSecond.end(),
        [&first, &second, &dupFirst](int x)
        {
            bool inDupFirst =
                (std::find(dupFirst.begin(), dupFirst.end(), x) != dupFirst.end());

            if (inDupFirst)
            {
                int cntInFirst = std::count(first.begin(), first.end(), x);
                int cntInSecond = std::count(second.begin(), second.end(), x);

                std::cout << x
                    << ": in first = " << cntInFirst
                    << ", in second = " << cntInSecond << std::endl;
            }
        });
    std::cout << std::endl;

    return 0;
}