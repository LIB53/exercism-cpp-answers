#include "hamming.h"

using namespace std;


namespace hamming
{
	int compute(const string& a, const string& b)
	{
		if (a.length() != b.length())
			throw domain_error("Length of strings do not match.");

		int counter = 0;

		for (
			auto a_itr = a.cbegin(), b_itr = b.cbegin();
			a_itr != a.cend();
			++a_itr, ++b_itr
		)
		{
			if (*a_itr != *b_itr)
				++counter;
		}

		return counter;
	}
}
