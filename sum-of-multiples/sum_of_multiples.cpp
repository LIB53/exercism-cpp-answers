#include "sum_of_multiples.h"


int sum_of_multiples::to(const std::set<int> integers, const int upper_limit)
{
	const auto& multiples = find_multiples(integers, upper_limit);
	
	const auto& sum = std::accumulate(
		std::cbegin(multiples),
		std::cend(multiples),
		0
	);

	return sum;
}

std::vector<int> sum_of_multiples::find_multiples(
	const std::set<int> integers,
	const int upper_limit)
{
	std::vector<int> multiples_buffer;
	
	for (int candidate = 1; candidate < upper_limit; candidate++)
	{
		bool is_valid_multiple = false;
		{
			for (const auto& i : integers)
				is_valid_multiple |= candidate % i == 0;
		}
		
		if (is_valid_multiple)
			multiples_buffer.push_back(candidate);
	}

	return multiples_buffer;
}
