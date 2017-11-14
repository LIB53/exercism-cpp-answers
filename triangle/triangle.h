#pragma once

#include <stdexcept>

#define INVALID_TRIANGLE_LENGTHS_EXCEPT std::domain_error("Triangle defined by length is an invalid triangle.")

namespace triangle
{
	const int scalene = 0;
	const int isosceles = 1;
	const int equilateral = 2;

	int kind(const double a_length, const double b_length, const double c_length);
	bool is_valid(const double a_length, const double b_length, const double c_length);
}
