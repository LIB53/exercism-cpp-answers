#if !defined(DIFFERENCE_OF_SQUARES_H)
#define DIFFERENCE_OF_SQUARES_H

#include <vector>
#include <numeric>
#include <algorithm>


#define SQUARE_INT(N) N * N

namespace squares
{
	int square_of_sums(const int n);
	int sum_of_squares(const int n);
	int difference(const int n);
}

#endif