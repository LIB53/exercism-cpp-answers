#include "trinary.h"


namespace trinary
{
	int to_decimal(std::string serialized_number)
	{
		int dec_value_buffer = 0;
		
		for (char serialized_digit : serialized_number)
		{
			switch (serialized_digit)
			{
			case '0':
				dec_value_buffer = dec_value_buffer * 3;
				break;
			case '1':
				dec_value_buffer = (dec_value_buffer * 3) + 1;
				break;
			case '2':
				dec_value_buffer = (dec_value_buffer * 3) + 2;
				break;
			default: // XXX: if invalid format
				return 0;
			}
		}

		return dec_value_buffer;
	}
}
