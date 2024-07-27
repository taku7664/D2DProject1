#include "pch.h"
#include "Random.h"

std::random_device Random::seed;
std::mt19937	   Random::engine(seed());