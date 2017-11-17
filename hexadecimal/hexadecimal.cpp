#include "hexadecimal.h"


int hexadecimal::convert(const std::string sequence)
{
	unsigned int hex_value_buffer = 0;
	
	for (char c : sequence)
	{
		// Attempt to convert character
		
		uint_fast8_t c_converted;
		
		if (c >= '0' && c <= '9')
		{
			c_converted = c - '0';
		}
		else if (c >= 'a' && c <= 'f')
		{
			c_converted = 10 + (c - 'a');
		}
		else if (c >= 'A' && c <= 'F')
		{
			c_converted = 10 + (c - 'A');
		}
		else // XXX: invalid format
			return 0;

		// Append hex digit
		
		hex_value_buffer = (hex_value_buffer << 4) | c_converted;
	}

	return hex_value_buffer;
}
