#include "clock.h"

#include <iomanip>
#include <sstream>


#define DAY_TO_MIN (24 * 60)

namespace date_independent
{
	clock::clock(const int num_minutes)
	{
		const int overflow = num_minutes % DAY_TO_MIN;

		_base_minutes = (DAY_TO_MIN + overflow) % DAY_TO_MIN;
	}
	
	int clock::hours() const
	{
		return _base_minutes / 60;
	}
	
	int clock::minutes() const
	{
		return _base_minutes % 60;
	}
	
	clock clock::plus(const int num_minutes) const
	{
		return clock(_base_minutes + num_minutes);
	}
	
	clock::operator std::string() const
	{
		std::ostringstream to_string_builder;

		to_string_builder
			<< std::setfill('0')
			<< std::setw(2) << hours()
			<< ":"
			<< std::setw(2) << minutes();

		return to_string_builder.str();
	}

	bool clock::operator==(clock other) const
	{
		return this->base_minutes() == other.base_minutes();
	}
	
	clock clock::at(const int num_hours, const int num_minutes)
	{
		return clock{ num_hours * 60 + num_minutes };
	}
}
