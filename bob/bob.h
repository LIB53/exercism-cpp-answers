#if !defined(BOB_H)
#define BOB_H

#include <string>
#include <sstream>
#include <regex>
#include <boost/algorithm/string.hpp>

namespace bob
{
	static const std::string REPLY_WHATEVER = "Whatever.";
	static const std::string REPLY_CHILL_OUT = "Whoa, chill out!";
	static const std::string REPLY_SURE = "Sure.";
	static const std::string REPLY_FINE = "Fine. Be that way!";

	std::string hey(const std::string& message);
	std::string scan_alpha_only(const std::string& strArg);
}

#endif