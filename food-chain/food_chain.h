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
		const std::string creature_epithet;
		const std::string remark;
	};

	typedef std::map<verse_identifier, verse_data> song_def_t;

	const song_def_t SONG_DEFINITION
	{
		{ verse_identifier::fly,	{"fly", "", ""} },
		{ verse_identifier::spider,	{"spider", "that wriggled and jiggled and tickled inside her", "It wriggled and jiggled and tickled inside her."} },
		{ verse_identifier::bird,	{"bird", "", "How absurd to swallow a bird!"} },
		{ verse_identifier::cat,	{"cat", "", "Imagine that, to swallow a cat!"} },
		{ verse_identifier::dog,	{"dog", "", "What a hog, to swallow a dog!"} },
		{ verse_identifier::goat,	{"goat", "", "Just opened her throat and swallowed a goat!"} },
		{ verse_identifier::cow,	{"cow", "", "I don't know how she swallowed a cow!"} },
		{ verse_identifier::horse,	{"horse", "", ""} }
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

	verse_identifier find_first_verse_id(
		const song_def_t* song_definition
	);

	verse_identifier find_last_verse_id(
		const song_def_t* song_definition
	);

	verse_data find_first_verse_info(
		const song_def_t* song_definition
	);
}
