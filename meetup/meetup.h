#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>


namespace meetup
{
	class scheduler
	{
	private:
		boost::gregorian::date dayteenth(const boost::date_time::weekdays day) const;
		boost::gregorian::date nth_day(const int n, const boost::date_time::weekdays day) const;
		boost::gregorian::date first_day(boost::date_time::weekdays day) const { return nth_day(1, day); }
		boost::gregorian::date second_day(boost::date_time::weekdays day) const { return nth_day(2, day); }
		boost::gregorian::date third_day(boost::date_time::weekdays day) const { return nth_day(3, day); }
		boost::gregorian::date fourth_day(boost::date_time::weekdays day) const { return nth_day(4, day); }
		boost::gregorian::date last_day(boost::date_time::weekdays day) const { return nth_day(5, day); }
	public:
		boost::gregorian::greg_month month;
		boost::gregorian::greg_year year;
		scheduler(
			boost::date_time::months_of_year month,
			boost::gregorian::greg_year year
		)
			: month(month), year(year) {}
		
		boost::gregorian::date monteenth() const { return dayteenth(boost::gregorian::Monday); }
		boost::gregorian::date tuesteenth() const { return dayteenth(boost::date_time::Tuesday); }
		boost::gregorian::date wednesteenth() const { return dayteenth(boost::date_time::Wednesday); }
		boost::gregorian::date thursteenth() const { return dayteenth(boost::date_time::Thursday); }
		boost::gregorian::date friteenth() const { return dayteenth(boost::date_time::Friday); }
		boost::gregorian::date saturteenth() const { return dayteenth(boost::date_time::Saturday); }
		boost::gregorian::date sunteenth() const { return dayteenth(boost::date_time::Sunday); }
		
		boost::gregorian::date first_monday() const { return first_day(boost::date_time::Monday); }
		boost::gregorian::date first_tuesday() const { return first_day(boost::date_time::Tuesday); }
		boost::gregorian::date first_wednesday() const { return first_day(boost::date_time::Wednesday); }
		boost::gregorian::date first_thursday() const { return first_day(boost::date_time::Thursday); }
		boost::gregorian::date first_friday() const { return first_day(boost::date_time::Friday); }
		boost::gregorian::date first_saturday() const { return first_day(boost::date_time::Saturday); }
		boost::gregorian::date first_sunday() const { return first_day(boost::date_time::Sunday); }
		
		boost::gregorian::date second_monday() const { return second_day(boost::date_time::Monday); }
		boost::gregorian::date second_tuesday() const { return second_day(boost::date_time::Tuesday); }
		boost::gregorian::date second_wednesday() const { return second_day(boost::date_time::Wednesday); }
		boost::gregorian::date second_thursday() const { return second_day(boost::date_time::Thursday); }
		boost::gregorian::date second_friday() const { return second_day(boost::date_time::Friday); }
		boost::gregorian::date second_saturday() const { return second_day(boost::date_time::Saturday); }
		boost::gregorian::date second_sunday() const { return second_day(boost::date_time::Sunday); }
		
		boost::gregorian::date third_monday() const { return third_day(boost::date_time::Monday); }
		boost::gregorian::date third_tuesday() const { return third_day(boost::date_time::Tuesday); }
		boost::gregorian::date third_wednesday() const { return third_day(boost::date_time::Wednesday); }
		boost::gregorian::date third_thursday() const { return third_day(boost::date_time::Thursday); }
		boost::gregorian::date third_friday() const { return third_day(boost::date_time::Friday); }
		boost::gregorian::date third_saturday() const { return third_day(boost::date_time::Saturday); }
		boost::gregorian::date third_sunday() const { return third_day(boost::date_time::Sunday); }
		
		boost::gregorian::date fourth_monday() const { return fourth_day(boost::date_time::Monday); }
		boost::gregorian::date fourth_tuesday() const { return fourth_day(boost::date_time::Tuesday); }
		boost::gregorian::date fourth_wednesday() const { return fourth_day(boost::date_time::Wednesday); }
		boost::gregorian::date fourth_thursday() const { return fourth_day(boost::date_time::Thursday); }
		boost::gregorian::date fourth_friday() const { return fourth_day(boost::date_time::Friday); }
		boost::gregorian::date fourth_saturday() const { return fourth_day(boost::date_time::Saturday); }
		boost::gregorian::date fourth_sunday() const { return fourth_day(boost::date_time::Sunday); }
		
		boost::gregorian::date last_monday() const { return last_day(boost::date_time::Monday); }
		boost::gregorian::date last_tuesday() const { return last_day(boost::date_time::Tuesday); }
		boost::gregorian::date last_wednesday() const { return last_day(boost::date_time::Wednesday); }
		boost::gregorian::date last_thursday() const { return last_day(boost::date_time::Thursday); }
		boost::gregorian::date last_friday() const { return last_day(boost::date_time::Friday); }
		boost::gregorian::date last_saturday() const { return last_day(boost::date_time::Saturday); }
		boost::gregorian::date last_sunday() const { return last_day(boost::date_time::Sunday); }
	};
}
