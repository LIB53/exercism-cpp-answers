#include "clock.h"


namespace date_independent
{
	/*
		Internal
	*/
	
	int hours_at(const int num_hours, const int num_minutes)
	{
		const int minutes_rollover =
			(num_minutes >= 60) ?
				num_minutes / 60 // positive rollover
				:
				(num_minutes < 0) ?
					(num_minutes / 60) - 1 // negative rollover
					:
					0;
		
		const int hours_rollover = num_hours % 24;
		
		const int overflow = (minutes_rollover + hours_rollover) % 24;

		return (24 + overflow) % 24;
	}

	int minutes_at(const int num_minutes)
	{
		const int overflow = num_minutes % 60;

		return (60 + overflow) % 60;
	}
	

	/*
		Exported
	*/
	
	clock::clock(const int num_hours, const int num_minutes)
	{
		_hours = hours_at(num_hours, num_minutes);
		_minutes = minutes_at(num_minutes);
	}

	clock clock::plus(const int num_minutes) const
	{
		return clock(hours(), minutes() + num_minutes);
	}
	
	clock::operator std::string() const
	{
		const auto format_numerals =
			[]
			(const int numerals)
			-> std::string
			{
				std::ostringstream formatter;

				formatter
					<< (numerals < 10 ? "0" : "")
					<< numerals;

				return formatter.str();
			};

		std::ostringstream to_string_builder;

		to_string_builder
			<< format_numerals(hours())
			<< ":"
			<< format_numerals(minutes());

		return to_string_builder.str();
	}

	bool clock::operator==(clock other) const
	{
		return
			this->hours() == other.hours()
			&& this->minutes() == other.minutes();
	}

	clock clock::at(const int num_hours, const int num_minutes)
	{
		return clock{ num_hours, num_minutes };
	}
}
