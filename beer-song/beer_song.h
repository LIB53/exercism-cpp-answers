#pragma once

#include <string>


namespace beer
{
	typedef int verse_id;
	
	std::string sing(const verse_id first_verse_number, const verse_id last_verse_number = 0);
	std::string verse(const verse_id verse_number);
}
