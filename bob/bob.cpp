#include "bob.h"

using namespace std;
using namespace boost;

namespace bob
{
	string hey(const string& message)
	{
		const string message_trimmed = trim_copy(message);

		// Guard - empty strings / Check if message is empty

		if (message_trimmed.empty())
			return REPLY_FINE;

		// Check if message is all caps

		const string message_alpha_only = scan_alpha_only(message_trimmed);

		if (message_alpha_only.length() > 0 /* XXX: short-circuit guards */
			&& equals(message_alpha_only, to_upper_copy(message_alpha_only)))
			return REPLY_CHILL_OUT;

		// Check if end of message is '?' character
		
		if (message_trimmed.back() == '?')
			return REPLY_SURE;

		return REPLY_WHATEVER;
	}

	string scan_alpha_only(const string& strArg)
	{
		// Scan
		
		stringstream scanBuffer;
		for (auto itr = strArg.cbegin(); itr != strArg.cend(); ++itr)
		{
			char current = *itr;
			
			if (current >= 'a' && current <= 'z'
				|| current >= 'A' && current <= 'Z')
				scanBuffer << current;
		}

		return scanBuffer.str();
	}
}