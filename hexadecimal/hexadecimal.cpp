#include "hexadecimal.h"


int hexadecimal::convert(const std::string sequence)
{
	int hex_value_buffer = 0;
	
	for (char c : sequence)
	{
		// Attempt to convert character
		
		int c_converted;
		
		if (c >= '0' && c <= '9')
		{
			c_converted = c - '0';
		}
		else if (c >= 'a' && c <= 'f')
		{
			c_converted = 10 + (c - 'a');
		}
		else // XXX: invalid format
			return 0;

		// Append hex digit
		
		hex_value_buffer = (hex_value_buffer * 16) + c_converted;
	}

	return hex_value_buffer;
}
