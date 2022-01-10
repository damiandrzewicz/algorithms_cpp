#pragma once

#include <random>
#include <functional>

class RandomFactory
{
public:

	auto create_mersenne_int_engine(int lower_bound, int upper_bound)
	{
		std::random_device rnd_device;
		std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
		std::uniform_int_distribution<int> dist {lower_bound, upper_bound};

		return std::bind(dist, mersenne_engine);
	}

private:
};
