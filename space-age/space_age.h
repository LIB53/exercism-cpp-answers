#pragma once

#include <cmath>
#include <cstdint>

namespace space_age
{
	class space_age
	{
	private:
		const double earth_year_in_sec = 31557600.0f;
		const double mercury_year_in_sec = earth_year_in_sec * 0.2408467f;
		const double venus_year_in_sec = earth_year_in_sec * 0.61519726f;
		const double mars_year_in_sec = earth_year_in_sec * 1.8808158f;
		const double jupiter_year_in_sec = earth_year_in_sec * 11.862615f;
		const double saturn_year_in_sec = earth_year_in_sec * 29.447498f;
		const double uranus_year_in_sec = earth_year_in_sec * 84.016846f;
		const double neptune_year_in_sec = earth_year_in_sec * 164.79132f;
		const uint64_t _seconds;
		double round_to_hundredth(const double d) const;
	public:
		space_age(const uint64_t seconds) : _seconds(seconds) {}
		uint64_t seconds() const;
		double on_earth() const;
		double on_mercury() const;
		double on_venus() const;
		double on_mars() const;
		double on_jupiter() const;
		double on_saturn() const;
		double on_uranus() const;
		double on_neptune() const;
	};
}
