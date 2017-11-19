#include "sieve.h"


namespace sieve
{
	std::vector<int> primes(const int max)
	{
		std::vector<int> primes_buffer;
		
		std::vector<bool> composites_work_table(max - 1, false);

		const auto mark_composite = [&composites_work_table](const int number)
		{
			composites_work_table[number - 2] = true;
		};

		const auto is_marked_composite = [&composites_work_table](const int number)
			-> bool
		{
			return composites_work_table.at(number - 2);
		};

		for (int i = 2; i <= max; i++)
		{
			if (!is_marked_composite(i))
			{
				primes_buffer.push_back(i);

				for (int r = i + 1; r <= max; r++)
					if (r % i == 0)
						mark_composite(r);
			}
		}

		return primes_buffer;
	}
}
