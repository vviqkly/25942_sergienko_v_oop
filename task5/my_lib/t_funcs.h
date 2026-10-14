#pragma once
#include <random>

namespace simple
{
    template <typename T>
    T add(const T& a, const T& b)
    {
        return a + b;
    }
}

namespace modified
{
    template <typename T>
    T add(const T& a, const T& b)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> distrib(0, 1);

        T sum = a + b;

        if (distrib(gen) == 1)
        {
            std::uniform_int_distribution<> add_distrib(1, 100);
            sum += static_cast<T>(add_distrib(gen));
        }

        return sum;
    }
}