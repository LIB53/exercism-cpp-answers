#pragma once

#include <numeric>
#include <stdexcept>
#include <string>


#define INVALID_LETTER_EXCEPT std::domain_error("Invalid letter argument.");

namespace scrabble_score
{
	int score(const std::string word);
	int score(const char letter);
}
