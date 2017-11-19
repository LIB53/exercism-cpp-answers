#include "nth_prime.h"

#include <limits>
#include <math.h>
#include <vector>


namespace prime
{
	unsigned int gen_prime(const int nth, const int upper_bound)
	{
		// Implements Sieve of Eratosthenes
		
		unsigned int th_prime_number = 0, prime_number;
		std::vector<bool> composites_work_table(upper_bound - 1, false);

		const auto raise_found_prime_number =
			[&th_prime_number, &prime_number](const unsigned int number)
		{
			th_prime_number++;
			prime_number = number;
		};
		
		const auto mark_composite = [&composites_work_table](const int number)
		{
			composites_work_table[number - 2] = true;
		};

		const auto is_marked_composite = [&composites_work_table](const int number)
			-> bool
		{
			return composites_work_table.at(number - 2);
		};

		for (int i = 2; i <= upper_bound; i++)
		{
			if (!is_marked_composite(i))
			{
				raise_found_prime_number(i);

				if (th_prime_number == nth)
					return prime_number;

				for (int r = i + 1; r <= upper_bound; r++)
					if (r % i == 0)
						mark_composite(r);
			}
		}

		throw GEN_PRIME_NO_RESULT;
	}

	unsigned int nth_sieve(const unsigned int nth)
	{
		if (nth == 0)
			throw INVALID_NTH_PRIME_ARG(nth);
		
		// Approximation of prime counting function. The output
		// is less than or equal to the output of the real prime counting
		// function for the same argument.
		
		const auto prime_count_approx = [](const unsigned int x)
			-> unsigned int
		{
			return (unsigned int)(floor(x / log(x)));
		};

		// Linear search the output set of prime counting function to find
		// upper bound in sieve for generating primes.
		
		unsigned int upper_bound = 2;
		for (; prime_count_approx(upper_bound) <= nth; upper_bound++);

		// Use variant of sieve that will return the nth prime number.

		return gen_prime(nth, upper_bound);
	}

	//bool is_prime(const unsigned int number)
	//{
	//	for (
	//		unsigned int divisor_itr = 2;
	//		divisor_itr <= unsigned int(ceil(sqrt(number)));
	//		divisor_itr++
	//		)
	//	{
	//		if (number % divisor_itr == 0)
	//			return false;
	//	}

	//	return true;
	//}

	//unsigned int nth_simple(const unsigned int nth)
	//{
	//	if (nth == 0)
	//		throw INVALID_NTH_PRIME_ARG(nth);
	//	
	//	unsigned int prime_counter = 1, prime_buffer = 2;

	//	for (
	//		unsigned int candidate = 3;
	//		prime_counter < nth;
	//		candidate++
	//		)
	//	{
	//		if (is_prime(candidate))
	//		{
	//			prime_counter++;
	//			prime_buffer = candidate;
	//		}
	//	}

	//	return prime_buffer;
	//}

	/*
		Exported
	*/
	
	int nth(const int nth)
	{
		if (nth <= 0)
			throw INVALID_NTH_PRIME_ARG(nth);
		
		return nth_sieve(nth);
	}
}
