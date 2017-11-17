#pragma once

#include <string>


namespace date_independent
{
	class clock
	{
	private:
		int _base_minutes;
	public:
		clock(const int num_minutes);
		int base_minutes() const { return _base_minutes; }
		int hours() const;
		int minutes() const;
		clock plus(const int num_minutes) const;
		operator std::string() const;
		bool operator==(clock other) const;
		bool operator!=(clock other) const { return !(*this == other); }
		static clock at(const int num_hours, const int num_minutes);
	};
}
