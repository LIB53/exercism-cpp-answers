#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <math.h>


namespace crypto_square
{
	class cipher
	{
	private:
		const std::string plain_text;
		const std::string normalized_text;
	public:
		std::string normalize_plain_text() const;
		std::vector<std::string> plain_text_segments() const;
		std::string cipher_text() const;
		std::string normalized_cipher_text() const;
		cipher(const std::string s) :
			plain_text{ s },
			normalized_text{ normalize_plain_text() }
		{};
	};
}