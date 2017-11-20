#pragma once

#include <stdexcept>


#define INVALID_TRIANGLE_LENGTHS_EXCEPT \
	std::domain_error("Triangle that was defined by length is an invalid triangle.")

namespace triangle
{
	enum triangle_kind { scalene, isosceles, equilateral };
	
	triangle_kind kind(const double a_length, const double b_length, const double c_length);
	bool is_valid(const double a_length, const double b_length, const double c_length);
}
