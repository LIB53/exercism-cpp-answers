#pragma once

#include <stdexcept>


#define INVALID_PRIME_INDEX(i) std::domain_error("nth prime cannot be found for index: " + i)

namespace prime
{
	int nth(const unsigned int prime_index);
}
