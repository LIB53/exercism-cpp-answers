#include "meetup.h"


namespace meetup
{
	boost::gregorian::date meetup::scheduler::dayteenth(
		const boost::date_time::weekdays day) const
	{
		const auto thirteenth = boost::gregorian::date(
			year,
			month,
			boost::gregorian::greg_day(13)
		);

		const int month_start_offset = 7 - thirteenth.day_of_week();
		
		return boost::gregorian::date(
			year,
			month,
			((month_start_offset + day) % 7) + 13
		);
	}

	boost::gregorian::date meetup::scheduler::nth_day(
		const int n,
		const boost::date_time::weekdays day) const
	{
		return boost::gregorian::nth_day_of_the_week_in_month(
			boost::gregorian::nth_day_of_the_week_in_month::week_num(n),
			boost::gregorian::greg_weekday(day),
			month
		).get_date(year);
	}
}
