#include"rand2.h"

int rng(const int min, const int max)
{
	std::random_device dev;
	std::default_random_engine generator(dev());
	std::uniform_int_distribution<int> range(min, max);
	return range(generator);
}

bool rngProb(const float prob)
{
	std::random_device dev;
	std::default_random_engine generator(dev());
	std::bernoulli_distribution dist(prob);
	return dist(generator);
}
