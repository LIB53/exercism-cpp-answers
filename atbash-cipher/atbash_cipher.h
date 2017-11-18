#pragma once

#include <string>


namespace atbash
{
	std::string encode(const std::string s);
	std::string decode(const std::string s);

	class character_mapping_error : std::domain_error
	{
	public:
		character_mapping_error(const char invalid_char)
			: domain_error("Cannot map character: " + invalid_char) {}
	};
}
