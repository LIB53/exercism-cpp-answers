#include "nucleotide_count.h"

using namespace std;


namespace dna
{
	counter::counter(const string& sequence)
	{
		for (char c : sequence)
		{
			switch (c)
			{
			case 'A':
				++A_counter;
				break;
			case 'T':
				++T_counter;
				break;
			case 'C':
				++C_counter;
				break;
			case 'G':
				++G_counter;
				break;
			default:
				throw INVALID_NUCLEOTIDE_EXCEPT;
			}
		}
	}

	nucleotide_count_map counter::nucleotide_counts() const
	{
		return
		{
			{ 'A', A_counter },
			{ 'T', T_counter },
			{ 'C', C_counter },
			{ 'G', G_counter },
		};
	}

	int counter::count(char nucleotide_symbol) const
	{
		switch (nucleotide_symbol)
		{
		case 'A':
			return A_counter;
		case 'T':
			return T_counter;
		case 'C':
			return C_counter;
		case 'G':
			return G_counter;
		default:
			throw INVALID_NUCLEOTIDE_EXCEPT;
		}

		return 0;
	}
}
