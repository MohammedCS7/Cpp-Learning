#pragma once
#include <cstdlib>

namespace Random
{
	int RandomNumber(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}
}
