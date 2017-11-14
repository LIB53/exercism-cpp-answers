#pragma once

#include <cstdint>


#define NUM_SQUARES 64

namespace grains
{
	typedef uint_fast64_t grains_count;
	
	grains_count square(const int square_num);
	grains_count total();
}
