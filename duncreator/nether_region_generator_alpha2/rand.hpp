#pragma once
#include<iostream>
#include<random>
#include"rand2.h"

template<typename T>
T& rngFrom( std::vector<T>& toPick)
{
	int i = rng(0, toPick.size() - 1);
	return toPick[i];
}

template<typename U>
U rngGeom(const std::vector<U>& toPick)
{
	std::random_device dev;
	std::default_random_engine generator(dev());
	std::geometric_distribution<int> dist(0.3);
	int i;
	do
	{
		i = dist(generator);
		switch (i)
		{
		case 0: i = 0; break;
		case 1: i = 0; break;
		case 2: i = 1; break;
		case 3: i = 1; break;
		case 4: i = 2; break;
		case 5: i = 2; break;
		default: i = 10; break;
		}
	} while (i == 10);
	return toPick[i];
}