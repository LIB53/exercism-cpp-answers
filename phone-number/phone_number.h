#pragma once

#include <sstream>
#include <string>
#include <iostream>


class phone_number
{
public:
	phone_number(const std::string s);
	std::string area_code() const;
	std::string prefix() const;
	std::string line_number() const;
	std::string number() const;
	std::string formatted() const;
	operator std::string() const;
private:
	std::string _area_code;
	std::string _prefix;
	std::string _line_number;
};
