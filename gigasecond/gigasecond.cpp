#include "gigasecond.h"

using namespace boost::posix_time;

namespace gigasecond
{
	const ptime advance(const ptime& initalTime)
	{
		const uint32_t GIGA = 1000000000U;

		return initalTime + seconds(GIGA);
	}
}
