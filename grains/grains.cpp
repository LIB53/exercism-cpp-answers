#include "grains.h"


namespace grains
{
	grains_count grains::square(const int square_num)
	{
		const auto pow_of_2 = [](int n)
			-> grains_count
		{
			return grains_count(1) << n;
		};

		return pow_of_2((square_num - 1));
	}
	
	grains_count total()
	{
		return square(NUM_SQUARES + 1) - 1;
	}
}
