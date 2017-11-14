#include "scrabble_score.h"


int scrabble_score::score(const std::string word)
{
	return std::accumulate(
		word.cbegin(),
		word.cend(),
		0,
		[](const int sum_acc, const char letter)
			-> int
		{
			return sum_acc + score(letter);
		}
	);
}

int scrabble_score::score(const char letter)
{
	switch (toupper(letter))
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'L':
	case 'N':
	case 'R':
	case 'S':
	case 'T':
		return 1;
	case 'D':
	case 'G':
		return 2;
	case 'B':
	case 'C':
	case 'M':
	case 'P':
		return 3;
	case 'F':
	case 'H':
	case 'V':
	case 'W':
	case 'Y':
		return 4;
	case 'K':
		return 5;
	case 'J':
	case 'X':
		return 8;
	case 'Q':
	case 'Z':
		return 10;
	default:
		throw INVALID_LETTER_EXCEPT;
	}
}
