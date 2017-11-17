#include "beer_song.h"

#include <sstream>


#define NUM_BOTTLES_STREAM_EXPRESSION(num_bottles) \
	(num_bottles) << " " << ((num_bottles) != 1 ? "bottles" : "bottle") << " "

namespace beer
{
	std::string sing(const verse_id first_verse_number, const verse_id last_verse_number)
	{
		std::ostringstream song_buffer;
		
		for (
			verse_id verse_itr = first_verse_number;
			verse_itr >= last_verse_number;
			verse_itr--
		)
		{
			song_buffer << verse(verse_itr);

			// Maybe add delimiter
			
			if (verse_itr != last_verse_number)
				song_buffer << "\n";
		}

		return song_buffer.str();
	}

	std::string verse(const verse_id verse_number)
	{
		std::ostringstream verse_buffer;

		// Generate line 1

		switch (verse_number)
		{
		case 0:
			verse_buffer
				<< "No more bottles of beer on the wall, "
				"no more bottles of beer.\n";
			break;
		default:
			verse_buffer
				<< NUM_BOTTLES_STREAM_EXPRESSION(verse_number)
				<< "of beer on the wall, "
				<< NUM_BOTTLES_STREAM_EXPRESSION(verse_number)
				<< "of beer.\n";
			break;
		}

		// Generate line 2

		switch (verse_number)
		{
		case 0:
			verse_buffer
				<< "Go to the store and buy some more, "
				"99 bottles of beer on the wall.\n";
			break;
		case 1:
			verse_buffer
				<< "Take it down and pass it around, "
				"no more bottles of beer on the wall.\n";
			break;
		default:
			verse_buffer
				<< "Take one down and pass it around, "
				<< NUM_BOTTLES_STREAM_EXPRESSION(verse_number - 1)
				<< "of beer on the wall.\n";
			break;
		}

		return verse_buffer.str();
	}
}
