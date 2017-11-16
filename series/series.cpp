#include "series.h"


namespace series
{
	std::vector<int> digits(const std::string number_sequence)
	{
		std::vector<int> digits_buffer;

		for (char c : number_sequence)
		{
			if (c >= '0' && c <= '9')
				digits_buffer.push_back(c - '0');
		}

		return digits_buffer;
	}

	std::vector<std::vector<int>> slice(
		const std::string number_sequence,
		const int length
	)
	{
		if ((length <= 0) || size_t(length) > number_sequence.length())
			throw INVALID_SLICE_LENGTH_EXCEPT;

		const auto guard_substr =
			[]
			(
				const std::string& s,
				const size_t& pos_arg,
				const size_t& length_arg
			)
			-> bool
			{
				return (pos_arg + (length_arg - 1)) < s.length();
			};
		
		std::vector<std::vector<int>> slices_buffer;

		for (
			size_t i_pos = 0;
			guard_substr(number_sequence, i_pos, length); // XXX: truncates remainder
			++i_pos
		)
		{
			slices_buffer.push_back(
				digits(number_sequence.substr(i_pos, length))
			);
		}

		return slices_buffer;
	}
}
