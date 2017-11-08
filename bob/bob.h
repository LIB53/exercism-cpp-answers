#pragma once

#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>


namespace bob
{
	#define REPLY_WHATEVER "Whatever."
	#define REPLY_CHILL_OUT "Whoa, chill out!"
	#define REPLY_SURE "Sure."
	#define REPLY_FINE "Fine. Be that way!"

	std::string hey(const std::string& message);
	std::string scan_alpha_only(const std::string& strArg);
}
