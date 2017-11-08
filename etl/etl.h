#pragma once

#include <algorithm>
#include <cctype>
#include <map>
#include <vector>


namespace etl
{
	typedef std::map<int, std::vector<char>> legacy_map_type;
	typedef std::map<char, int> new_map_type;

	new_map_type transform(const legacy_map_type& old);
}
