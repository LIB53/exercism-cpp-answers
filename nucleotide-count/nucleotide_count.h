#pragma once

#include <map>
#include <string>
#include <stdexcept>


#define INVALID_NUCLEOTIDE_EXCEPT invalid_argument("Invalid nucleotide symbol")

namespace dna
{
	typedef std::map<char, int> nucleotide_count_map;

	class counter
	{
	public:
		counter(const std::string& sequence);
		nucleotide_count_map nucleotide_counts() const;
		int count(char nucleotide_symbol) const;
	
	private:
		int A_counter = 0;
		int T_counter = 0;
		int C_counter = 0;
		int G_counter = 0;
	};

}
