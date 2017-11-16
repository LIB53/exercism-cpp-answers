#pragma once

#include <stdexcept>
#include <string>
#include <vector>


#define INVALID_SLICE_LENGTH_EXCEPT std::domain_error("Slice cannot be performed. Invalid length argument passed.")

namespace series
{
	std::vector<int> digits(const std::string number_sequence);
	std::vector<std::vector<int>> slice(const std::string number_sequence, const int length);
}
