#include "sum_of_multiples.h"


int sum_of_multiples::to(const std::vector<int> integers, const int upper_limit)
{
	int sum_buffer = 0;

	const auto& multiples = find_multiples(
		std::set<int>(integers.cbegin(), integers.cend()), 
		upper_limit
	);

	for (auto m : multiples)
		sum_buffer += m;

	return sum_buffer;
}

std::vector<int> sum_of_multiples::find_multiples(
	const std::set<int> integers,
	const int upper_limit)
{
	std::set<int> multiples_buffer;
	
	for (const auto i : integers)
	{
		const auto& multiples = find_multiples(i, upper_limit);

		for (auto m : multiples)
			multiples_buffer.insert(m);
	}

	return 
		std::vector<int>(multiples_buffer.cbegin(), multiples_buffer.cend());
}

std::vector<int> sum_of_multiples::find_multiples(
	const int integer,
	const int upper_limit)
{
	std::vector<int> multiples_buffer;

	for (int candidate = 1; candidate < upper_limit; candidate++)
	{
		const bool is_valid_multiple = candidate % integer == 0;
		
		if (is_valid_multiple)
			multiples_buffer.push_back(candidate);
	}

	return multiples_buffer;
}
