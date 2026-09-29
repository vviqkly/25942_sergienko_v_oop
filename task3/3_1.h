#pragma once
#include <random>

namespace simple
{
	template <typename t1, typename res>
	res add(const t1& a, const t1& b)
	{
		return static_cast<res>(a + b);
	}
}

namespace modified
{
	template <typename t1, typename res>
	res add(const t1& a, const t1& b)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 1);

		res sum = static_cast<res>(a + b);

		if (distrib(gen) == 1)
		{
			std::uniform_int_distribution<> add_distrib(1, 100);
			sum += static_cast<res>(add_distrib(gen));
		}

		return sum;
	}
}
