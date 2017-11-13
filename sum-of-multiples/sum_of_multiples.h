#pragma once

#include <numeric>
#include <set>
#include <vector>


namespace sum_of_multiples
{
	int to(const std::set<int> integers, const int upper_limit);
	std::vector<int> find_multiples(const std::set<int> integers, const int upper_limit);
}
