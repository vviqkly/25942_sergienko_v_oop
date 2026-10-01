#include "funcs.h"
#include <random>

namespace simple
{
	int add(int a, int b)
	{
		return (a + b);
	}
}

namespace modified
{
	int add(int a, int b)
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<> distrib(0, 1);

		int sum = a + b;

		if (distrib(gen) == 1)
		{
			std::uniform_int_distribution<> add_distrib(1, 100);
			sum += add_distrib(gen);
		}

		return sum;
	}
}
