#include "sieve.h"


namespace sieve
{
	std::vector<int> primes(const int max)
	{
		std::vector<int> primes_buffer;
		
		std::set<int> blacklist;

		const auto insert_blacklist_item = [&blacklist](const int item)
		{
			blacklist.insert(item);
		};

		const auto blacklist_contains_item = [&blacklist](const int item)
			-> bool
		{
			return blacklist.find(item) != blacklist.cend();
		};

		for (int i = 2; i <= max; i++)
		{
			if (!blacklist_contains_item(i))
			{
				primes_buffer.push_back(i);

				for (int r = i + 1; r <= max; r++)
					if (r % i == 0)
						insert_blacklist_item(r);
			}
		}

		return primes_buffer;
	}
}
