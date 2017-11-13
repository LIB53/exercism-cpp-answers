#pragma once

#include <set>
#include <vector>


namespace sum_of_multiples
{
	int to(const std::vector<int> integers, const int upper_limit);
	std::vector<int> find_multiples(const std::set<int> integers, const int upper_limit);
	std::vector<int> find_multiples(const int integer, const int upper_limit);
}