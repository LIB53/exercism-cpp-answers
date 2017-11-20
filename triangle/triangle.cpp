#include "triangle.h"


namespace triangle
{
	triangle_kind kind(
		const double a_length,
		const double b_length,
		const double c_length
	)
	{
		if (!is_valid(a_length, b_length, c_length))
			throw INVALID_TRIANGLE_LENGTHS_EXCEPT;

		// TODO: Use double approximate comparator
		
		if (a_length == b_length && b_length == c_length)
			return equilateral;
		else if (
			a_length == b_length
			|| b_length == c_length
			|| c_length == a_length
			)
			return isosceles;
		else
			return scalene;
	}

	bool is_valid(
		const double a_length,
		const double b_length,
		const double c_length
	)
	{
		// TODO: Use double approximate comparator

		// Edge Length is Zero Test

		if (a_length == 0 || b_length == 0 || c_length == 0)
			return false;

		// Triangle Inequality Test

		if (
			a_length + b_length < c_length
			|| b_length + c_length < a_length
			|| c_length + a_length < b_length
		)
			return false;

		// Degenerate Triangle Test

		if (
			a_length + b_length == c_length
			|| b_length + c_length == a_length
			|| c_length + a_length == b_length
		)
			return false;

		return true;
	}
}
