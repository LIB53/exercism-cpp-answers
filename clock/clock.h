#pragma once

#include <string>
#include <sstream>


namespace date_independent
{
	class clock
	{
	private:
		int _hours;
		int _minutes;
	public:
		clock(const int num_hours, const int num_minutes);
		int hours() const { return _hours; }
		int minutes() const { return _minutes; }
		clock plus(const int num_minutes) const;
		operator std::string() const;
		bool operator==(clock other) const;
		bool operator!=(clock other) const { return !(*this == other); }
		static clock at(const int num_hours, const int num_minutes);
	};
}
