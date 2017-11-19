#pragma once

#include <stdexcept>


#define INVALID_NTH_PRIME_ARG(i) std::domain_error("nth prime cannot be found for argument: " + i)
#define GEN_PRIME_NO_RESULT std::logic_error("nth prime not found within sieve table range.");

namespace prime
{
	typedef unsigned long prime_number_t;
	typedef unsigned int nth_prime_t;
	
	prime_number_t nth(const int nth);
}
