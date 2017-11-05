#if !defined(ETL_H)
#define ETL_H

#include <map>
#include <vector>
#include <cctype>
#include <algorithm>


namespace etl
{
	typedef std::map<int, std::vector<char>> legacy_map_type;
	typedef std::map<char, int> new_map_type;

	new_map_type transform(const legacy_map_type& old);
}

#endif