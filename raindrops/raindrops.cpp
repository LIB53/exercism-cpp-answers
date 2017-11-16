#include "raindrops.h"


namespace raindrops
{
	std::string raindrops::convert(const int number)
	{
		std::ostringstream  output_buffer;
		bool has_special_factor = false;
		
		const auto raise_special_factor =
			[&output_buffer, &has_special_factor](std::string factor_output)
		{
			has_special_factor = true;
			output_buffer << factor_output;
		};

		// Discover special factors
		
		if (number % 3 == 0) raise_special_factor("Pling");
		if (number % 5 == 0) raise_special_factor("Plang");
		if (number % 7 == 0) raise_special_factor("Plong");

		// Format number arg if no special factors found

		if (!has_special_factor)
			output_buffer << number;

		return output_buffer.str();
	}
}
