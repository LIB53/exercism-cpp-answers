#include "nth_prime.h"

#include <math.h>


namespace prime
{
	/*
		Internal
	*/
	
	bool is_prime(const unsigned int number)
	{
		for (
			unsigned int divisor_itr = 2;
			divisor_itr <= unsigned int(ceil(sqrt(number)));
			divisor_itr++
			)
		{
			if (number % divisor_itr == 0)
				return false;
		}

		return true;
	}


	/*
		Exported
	*/

	int nth(const unsigned int prime_index)
	{
		if (prime_index == 0)
			throw INVALID_PRIME_INDEX(prime_index);
		
		unsigned int prime_counter = 1, prime_buffer = 2;

		for (
			unsigned int candidate = 3;
			prime_counter < prime_index;
			candidate++
			)
		{
			if (is_prime(candidate))
			{
				prime_counter++;
				prime_buffer = candidate;
			}
		}

		return prime_buffer;
	}
}
