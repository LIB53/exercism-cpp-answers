#include "say.h"


namespace say
{
	/*
		Internal
	*/
	
	std::string format_section(
		const uint_fast64_t quantity,
		const std::string section_name,
		const std::function<std::string(const say_number)> in_english_formatter
	)
	{
		std::ostringstream section_builder;

		section_builder
			<< in_english_formatter(quantity)
			<< " "
			<< section_name;

		return section_builder.str();
	}
	
	std::string format_sections(const std::vector<std::string> sections)
	{
		std::ostringstream word_buffer;

		for (size_t i = 0; i < sections.size(); i++)
		{
			const auto& current = sections.at(i);

			word_buffer << current;

			// Maybe add delimiter

			if (i != sections.size() - 1)
				word_buffer << " ";
		}

		return word_buffer.str();
	}

	std::string in_english_0_99(const say_number number)
	{

		const uint_fast8_t tens_place = (number % 100) / 10;
		const uint_fast8_t ones_place = number % 10;

		std::string prefix = "", digit_word = "";

		switch (tens_place)
		{
		case 0: break;
		case 1:
			switch (ones_place)
			{
			case 0: return "ten";
			case 1: return "eleven";
			case 2: return "twelve";
			case 3: return "thirteen";
			case 4: return "fourteen";
			case 5: return "fifteen";
			case 6: return "sixteen";
			case 7: return "seventeen";
			case 8: return "eighteen";
			case 9: return "nineteen";
			}
			break;
		case 2: prefix = "twenty"; break;
		case 3: prefix = "thirty"; break;
		case 4: prefix = "forty"; break;
		case 5: prefix = "fifty"; break;
		case 6: prefix = "sixty"; break;
		case 7: prefix = "seventy"; break;
		case 8: prefix = "eighty"; break;
		case 9: prefix = "ninety"; break;
		}


		switch (ones_place)
		{
		case 0:
			if (tens_place == 0) return "zero";
			break;
		case 1: digit_word = "one"; break;
		case 2: digit_word = "two"; break;
		case 3: digit_word = "three"; break;
		case 4: digit_word = "four"; break;
		case 5: digit_word = "five"; break;
		case 6: digit_word = "six"; break;
		case 7: digit_word = "seven"; break;
		case 8: digit_word = "eight"; break;
		case 9: digit_word = "nine"; break;
		}

		return
			(tens_place == 0) ?
				digit_word
				:
				(ones_place == 0) ?
					prefix
					:
					prefix + "-" + digit_word
			;
	}
	
	std::string in_english_0_999(const say_number number)
	{
		std::vector<std::string> sections_buffer;

		// Build sections

		// - Hundreds section
		{
			const uint_fast16_t num_hundreds = (number % 1000) / 100;

			if (num_hundreds != 0)
				sections_buffer.push_back(
					format_section(num_hundreds, "hundred", in_english_0_99)
				);
		}

		// - 0-99 section
		{
			const bool omit_0_99_section = number > 99 && number % 100 == 0;

			if (!omit_0_99_section)
				sections_buffer.push_back(
					in_english_0_99(number)
				);
		}
		
		// Compile sections

		return format_sections(sections_buffer);
	}


	/*
		Exported
	*/

	std::string in_english(const say_number number)
	{
		if (number < 0 || number >= ONE_TRILLION)
			throw NUMBER_TOO_LARGE_EXCEPT;

		// Build sections
		
		std::vector<std::string> sections_buffer;

		// - Billions section
		{
			const uint_fast64_t num_billions = (number % ONE_TRILLION) / ONE_BILLION;

			if (num_billions != 0)
				sections_buffer.push_back(
					format_section(num_billions, "billion", in_english_0_999)
				);
		}
		
		// - Million section
		{
			const uint_fast32_t num_millions = (number % ONE_BILLION) / ONE_MILLION;

			if (num_millions != 0)
				sections_buffer.push_back(
					format_section(num_millions, "million", in_english_0_999)
				);
		}
		
		// - Thousand section
		{
			const uint_fast32_t num_thousands = (number % ONE_MILLION) / 1000;

			if (num_thousands != 0)
				sections_buffer.push_back(
					format_section(num_thousands, "thousand", in_english_0_999)
				);
		}

		// - 0-999 section
		{
			const auto hundreds_section = in_english_0_999(number);

			if (hundreds_section != std::string{}) // XXX: omit
				sections_buffer.push_back(hundreds_section);
		}
		
		// Compile sections

		return format_sections(sections_buffer);
	}
}
