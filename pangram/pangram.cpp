#include "pangram.h"

#include <bitset>


namespace pangram
{
	bool is_pangram(const std::string sentence)
	{
		std::bitset<26> alphabet_flags;

		for (const auto c : sentence)
		{
			if (isalpha(c))
			{
				alphabet_flags.set(tolower(c) - 'a');

				if (alphabet_flags.all())
					return true;
			}
		}

		return false;
	}
}
