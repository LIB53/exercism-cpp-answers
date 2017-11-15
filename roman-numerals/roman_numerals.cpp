#include "roman_numerals.h"


namespace roman
{
	std::string convert(const int number)
	{
		if (number > 3000)
			throw std::domain_error("Number exceeds 3000.");

		/*
			Breaks the conversion down into translating each decimal digit.
			Much more complex than the solutions iterating a
			diminishing remainder :(

			On the plus side, this functional style approach could be threaded
		*/

		static const int tens_powers[] = { 1, 10, 100, 1000, 10000 };
		static const char roman_numerals[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

		std::ostringstream roman_numerals_buffer;

		for (int power_itr = 3; power_itr >= 0; power_itr--)
		{
			const auto& power = power_itr;
			
			const auto& numeral = roman_numerals[power * 2];
			const auto& next_mul5_numeral = *(&numeral + 1); // XXX: OK, goes out of bounds
			const auto& next_mul10_numeral = *(&numeral + 2); // XXX: OK, goes out of bounds
			
			const auto push_numerals =
				[&roman_numerals_buffer]
				(const char letter, const int num_letters)
			{
				for (int i = 0; i < num_letters; i++)
					roman_numerals_buffer << letter;
			};
			
			const int decimal_digit =
				(number % tens_powers[power + 1]) / tens_powers[power];

			if (decimal_digit == 9) // subtractive numeral for next power ten
			{
				roman_numerals_buffer
					<< std::string{ numeral, next_mul10_numeral };
			}
			else if (decimal_digit > 4) // multiple of 5 range numeral
			{
				roman_numerals_buffer
					<< std::string{ next_mul5_numeral };
				
				push_numerals(numeral, decimal_digit % 5);
			}
			else if (decimal_digit == 4) // subtractive multiple of 5 numeral
			{
				roman_numerals_buffer
					<< std::string{ numeral, next_mul5_numeral };
			}
			else // current decimal place range
			{
				push_numerals(numeral, decimal_digit);
			}
		}
		
		return roman_numerals_buffer.str();
	}
}
