#include "prime_factors.h"


namespace prime_factors
{
	std::vector<int> of(const int number)
	{
		std::vector<int> prime_numbers;
		
		for (int candidate = 2, upper = number; candidate <= upper;)
		{
			if (upper % candidate == 0)
			{
				prime_numbers.push_back(candidate);
				upper /= candidate;
			}
			else
				candidate++;
		}

		return prime_numbers;
	}
}
