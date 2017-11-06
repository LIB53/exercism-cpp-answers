#include "difference_of_squares.h"

using namespace std;


//int squares::square_of_sums(const int n)
//{
//	vector<int> computation_buffer(n);
//
//	// Map non-zero index (counting from 1)
//	
//	for (size_t i = 0; i < computation_buffer.size(); ++i)
//	{
//		const int non_zero_index = i + 1;
//		computation_buffer[i] = non_zero_index;
//	}
//
//	// Summation
//
//	const int sum =
//		accumulate(computation_buffer.cbegin(), computation_buffer.cend(), 0);
//
//	// Square sums
//	
//	const int squared_sums = SQUARE_INT(sum);
//
//	return squared_sums;
//}

int squares::square_of_sums(const int n)
{
	return SQUARE_INT(n * (n + 1) / 2);
}

//int squares::sum_of_squares(const int n)
//{
//	vector<int> computation_buffer(n);
//
//	// Map non-zero index (counting from 1), squared
//
//	for (size_t i = 0; i < computation_buffer.size(); ++i)
//	{
//		const int non_zero_index = i + 1;
//		computation_buffer[i] = SQUARE_INT(non_zero_index);
//	}
//
//	// Summation
//
//	const int sum =
//		accumulate(computation_buffer.cbegin(), computation_buffer.cend(), 0);
//}

int squares::sum_of_squares(const int n)
{
	return (n * (n + 1) * (2 * n + 1) / 6);
}

int squares::difference(const int n)
{
	return square_of_sums(n) - sum_of_squares(n);
}
