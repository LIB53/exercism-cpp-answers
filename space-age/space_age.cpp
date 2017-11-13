#include "space_age.h"


double space_age::space_age::round_to_hundredth(const double d) const
{
	return round(d * 100.0f) / 100.0f;
}

uint64_t space_age::space_age::seconds() const
{
	return _seconds;
}

double space_age::space_age::on_earth() const
{
	const double age_in_sec = double(seconds()) / earth_year_in_sec;
	
	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_mercury() const
{
	const double age_in_sec = double(seconds()) / mercury_year_in_sec;

	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_venus() const
{
	const double age_in_sec = double(seconds()) / venus_year_in_sec;

	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_mars() const
{
	const double age_in_sec = double(seconds()) / mars_year_in_sec;

	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_jupiter() const
{
	const double age_in_sec = double(seconds()) / jupiter_year_in_sec;

	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_saturn() const
{
	const double age_in_sec = double(seconds()) / saturn_year_in_sec;

	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_uranus() const
{
	const double age_in_sec = double(seconds()) / uranus_year_in_sec;

	return round_to_hundredth(age_in_sec);
}

double space_age::space_age::on_neptune() const
{
	const double age_in_sec = double(seconds()) / neptune_year_in_sec;

	return round_to_hundredth(age_in_sec);
}
