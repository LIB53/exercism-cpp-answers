#pragma once

#include <map>
#include <sstream>
#include <stack>
#include <string>


namespace food_chain
{
	enum class verse_identifier
	{
		fly,
		spider,
		bird,
		cat,
		dog,
		goat,
		cow,
		horse
	};

	struct verse_data
	{
		const std::string creature_name;
		const std::string remark;
		const std::string creature_epithet;
	};

	typedef std::map<verse_identifier, verse_data> song_def_t;

	const auto FLY_VERSE_INFO		= verse_data{"fly", "", ""};
	const auto SPIDER_VERSE_INFO	= verse_data{"spider", "It wriggled and jiggled and tickled inside her.", "that wriggled and jiggled and tickled inside her"};
	const auto BIRD_VERSE_INFO		= verse_data{"bird", "How absurd to swallow a bird!", ""};
	const auto CAT_VERSE_INFO		= verse_data{"cat", "Imagine that, to swallow a cat!", ""};
	const auto DOG_VERSE_INFO		= verse_data{"dog", "What a hog, to swallow a dog!", ""};
	const auto GOAT_VERSE_INFO		= verse_data{"goat", "Just opened her throat and swallowed a goat!", ""};
	const auto COW_VERSE_INFO		= verse_data{"cow", "I don't know how she swallowed a cow!", ""};
	const auto HORSE_VERSE_INFO		= verse_data{"horse", "", ""};

	const song_def_t SONG_DEFINITION
	{
		{ verse_identifier::fly,	FLY_VERSE_INFO },
		{ verse_identifier::spider,	SPIDER_VERSE_INFO },
		{ verse_identifier::bird,	BIRD_VERSE_INFO },
		{ verse_identifier::cat,	CAT_VERSE_INFO },
		{ verse_identifier::dog,	DOG_VERSE_INFO },
		{ verse_identifier::goat,	GOAT_VERSE_INFO },
		{ verse_identifier::cow,	COW_VERSE_INFO },
		{ verse_identifier::horse,	HORSE_VERSE_INFO }
	};

	std::string sing();
	
	std::string verse(const int verse_number);
	
	std::string verses(const int start_verse_number, const int end_verse_number);
	
	std::string gen_verse_beginning_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	);

	std::string gen_verse_middle_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	);

	std::string gen_common_verse_middle_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	);

	std::string gen_verse_last_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	);

	verse_identifier get_first_verse_id(
		const song_def_t* song_definition
	);

	verse_identifier get_last_verse_id(
		const song_def_t* song_definition
	);

	verse_data get_first_verse_info(
		const song_def_t* song_definition
	);
}
