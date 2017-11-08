#include "difference_of_squares.h"


namespace squares
{
	int squares::square_of_sums(const int n)
	{
		return SQUARE_INT((n * (n + 1)) / 2);
	}

	int squares::sum_of_squares(const int n)
	{
		return n * (n + 1) * (2 * n + 1) / 6;
	}

	int squares::difference(const int n)
	{
		return square_of_sums(n) - sum_of_squares(n);
	}
}
