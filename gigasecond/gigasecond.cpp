#include "gigasecond.h"

using namespace boost::posix_time;


namespace gigasecond
{
	const ptime advance(const ptime& initalTime)
	{
		const uint_fast32_t GIGA = 1000000000;

		return initalTime + seconds(GIGA);

	}
}
