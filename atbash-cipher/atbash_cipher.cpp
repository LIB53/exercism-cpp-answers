#include "atbash_cipher.h"

#include <sstream>


namespace atbash
{
	char map(const char c)
	{
		if (isdigit(c))
		{
			return c;
		}
		else if (c >= 'a' && c <= 'z')
		{
			return 'z' - (c - 'a');
		}
		else if (c >= 'A' && c <= 'Z')
		{
			return 'z' - (c - 'A');
		}
		else
			throw character_mapping_error(c);
	}
	
	std::string gen_cipher(const std::string s)
	{
		std::ostringstream encode_buffer;

		for (const auto& c : s)
		{
			if (isalnum(c))
				encode_buffer << map(c);
		}

		return encode_buffer.str();
	}

	std::string encode(const std::string s)
	{
		const auto& cipher = gen_cipher(s);
		
		std::ostringstream format_buffer;

		for (size_t i = 0, end = cipher.length(); i != end; i++)
		{
			format_buffer << cipher[i];

			/*
				Add delimiter if
					end of 5 character sequence,
					and not the last character.
			*/
			
			if ((i + 1) % 5 == 0 && (i + 1) != end)
				format_buffer << " ";
		}

		return format_buffer.str();
	}
	
	std::string decode(std::string s)
	{
		return gen_cipher(s);
	}
}
