#include "leap.h"
#include "leap.h"


namespace leap
{
	bool is_leap_year(int year)
	{
		// Guard new century year exception
		/*
			If year is evenly divisible by 100,
			then it is not a leap year,
			UNLESS it is also divisible by 400.
		*/
		if (year % 100 == 0 && !(year % 400 == 0))
			return false;

		// Test is leap year
		if (year % 4 == 0)
			return true;

		return false;
	}
}