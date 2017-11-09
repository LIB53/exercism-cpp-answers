#include "phone_number.h"

using namespace std;


phone_number::phone_number(const string s)
{
	// Parse numbers

	ostringstream parse_buffer;

	for (char c : s)
		if (c >= '0' && c <= '9')
			parse_buffer << c;

	string parse_buffer_formatted = parse_buffer.str();

	string parsed_number;
	{
		// Validate & Resolve
		
		if (parse_buffer_formatted.length() == 11
			&& parse_buffer_formatted.at(0) == '1')
		{
			parsed_number =
				parse_buffer_formatted.substr(
					1,
					parse_buffer_formatted.length() - 1
				);
		}
		else if (parse_buffer_formatted.length() == 10)
		{
			parsed_number = parse_buffer_formatted;
		}
		else /* invalid phone number */
		{
			parsed_number = "0000000000";
		}
	}

	// Decode

	_area_code = parsed_number.substr(0, 3);
	_prefix = parsed_number.substr(3, 3);
	_line_number = parsed_number.substr(6, 4);
}

string phone_number::area_code() const { return _area_code; }

string phone_number::prefix() const { return _prefix; }

string phone_number::line_number() const { return _line_number; }

string phone_number::number() const
{
	ostringstream number_builder;

	number_builder
		<< area_code()
		<< prefix()
		<< line_number();

	return number_builder.str();
}

string phone_number::formatted() const
{
	ostringstream formatting_buffer;

	formatting_buffer
		<< "(" << area_code() << ")"
		<< " "
		<< prefix()
		<< "-"
		<< line_number();

	return formatting_buffer.str();
}

phone_number::operator string() const
{
	return formatted();
}
