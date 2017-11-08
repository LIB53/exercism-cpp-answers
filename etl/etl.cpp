#include "etl.h"

using namespace std;


namespace etl
{
	new_map_type etl::transform(const legacy_map_type& legacy_map)
	{
		new_map_type new_map_buffer;
		
		const auto new_map_put_letter =
			[]
			(new_map_type& new_map, const char letter, const int point_value)
				-> void
			{
				new_map[letter] = point_value;
			};
		
		// Contribute each (letter, point value) pair in legacy map to new map
		
		for (const auto row : legacy_map)
		{
			const int point_value_transformed = row.first;

			for (const auto letter : row.second)
			{
				const char letter_transformed = tolower(letter);

				// Add transformed values to new map
				
				new_map_put_letter(
					new_map_buffer,
					letter_transformed,
					point_value_transformed
				);
			}
		}

		return new_map_buffer;
	}
}
