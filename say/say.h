#pragma once

#include <cstdint>
#include <functional>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>


#define ONE_MILLION (1000ULL * 1000ULL)
#define ONE_BILLION (1000ULL * ONE_MILLION)
#define ONE_TRILLION (1000ULL * ONE_BILLION)

#define NUMBER_OUT_OF_RANGE_EXCEPT std::domain_error("Number is out of range (1 - 999,999,999,999).")

namespace say
{
	typedef unsigned long long say_number;
	std::string in_english(const say_number number);
}
