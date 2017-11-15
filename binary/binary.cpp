#include "binary.h"


namespace binary
{
	int convert(std::string s)
	{
		int buffer = 0;
		
		for (char c : s)
		{
			switch (c)
			{
			case '0':
				buffer = buffer << 1;
				break;
			case '1':
				buffer = (buffer << 1) + 1;
				break;
			default: // XXX: if invalid format
				return 0;
			}
		}

		return buffer;
	}
}
