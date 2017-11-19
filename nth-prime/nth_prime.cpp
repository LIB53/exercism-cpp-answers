#include "nth_prime.h"

#include <limits>
#include <math.h>
#include <vector>


namespace prime
{
	unsigned long gen_prime(const nth_prime_t nth, const prime_number_t upper_bound)
	{
		// Implements Sieve of Eratosthenes
		
		nth_prime_t th_prime_number = 0;
		prime_number_t prime_number;
		std::vector<bool> composites_work_table(upper_bound - 1, false);

		const auto raise_found_prime_number =
			[&th_prime_number, &prime_number](const prime_number_t number)
		{
			th_prime_number++;
			prime_number = number;
		};
		
		const auto mark_composite =
			[&composites_work_table](const prime_number_t number)
		{
			composites_work_table[number - 2] = true;
		};

		const auto is_marked_composite =
			[&composites_work_table](const prime_number_t number)
			-> bool
		{
			return composites_work_table.at(number - 2);
		};

		for (prime_number_t i = 2; i <= upper_bound; i++)
		{
			if (!is_marked_composite(i))
			{
				raise_found_prime_number(i);

				if (th_prime_number == nth)
					return prime_number;

				for (auto r = i + 1; r <= upper_bound; r++)
					if (r % i == 0)
						mark_composite(r);
			}
		}

		throw GEN_PRIME_NO_RESULT;
	}

	prime_number_t nth_sieve(const nth_prime_t nth)
	{
		if (nth == 0)
			throw INVALID_NTH_PRIME_ARG(nth);
		
		// Approximation of prime counting function. The output
		// is less than or equal to the output of the real prime counting
		// function for the same argument.
		
		const auto prime_count_approx = [](const prime_number_t x)
			-> nth_prime_t
		{
			return (nth_prime_t)(floor(x / log(x)));
		};

		// Linear search the output set of prime counting function to find
		// upper bound in sieve for generating primes.
		
		prime_number_t upper_bound = 2UL;
		for (; prime_count_approx(upper_bound) <= nth; upper_bound++);

		// Use variant of sieve that will return the nth prime number.

		return gen_prime(nth, upper_bound);
	}

	/*
		Exported
	*/
	
	prime_number_t nth(const nth_prime_t nth)
	{
		if (nth <= 0)
			throw INVALID_NTH_PRIME_ARG(nth);
		
		return nth_sieve(nth);
	}
}
