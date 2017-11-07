#include "food_chain.h"

using namespace std;


namespace food_chain
{
	string sing(const song_def_t* song_definition)
	{
		return verses(1, song_definition->size(), song_definition);
	}

	string verse(
		const int verse_number,
		const song_def_t* song_definition
	)
	{
		verse_identifier verse_id = verse_identifier(verse_number - 1);
		
		ostringstream verse_builder;
		verse_builder
			<< gen_verse_beginning_lines(&SONG_DEFINITION, verse_id)
			<< gen_verse_middle_lines(&SONG_DEFINITION, verse_id)
			<< gen_verse_last_lines(&SONG_DEFINITION, verse_id);

		return verse_builder.str();
	}

	string verses(
		const int start_verse_number,
		const int end_verse_number,
		const song_def_t* song_definition
	)
	{
		ostringstream verses_builder;
		for (int i = start_verse_number; i <= end_verse_number; i++)
			verses_builder << verse(i, song_definition) << "\n";

		return verses_builder.str();
	}

	string gen_verse_beginning_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	)
	{
		const auto& verse_info = song_definition->at(verse_id);

		ostringstream lines_builder;

		lines_builder
			<< "I know an old lady who swallowed a "
			<< verse_info.creature_name
			<< ".\n";

		if (!verse_info.remark.empty())
		{
			lines_builder
				<< verse_info.remark
				<< "\n";
		}

		return lines_builder.str();
	}

	string gen_verse_middle_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	)
	{
		if (
			verse_id == find_first_verse_id(song_definition)
			|| verse_id == find_last_verse_id(song_definition)
			)
		{
			return string();
		}
		else
		{
			return gen_common_verse_middle_lines(song_definition, verse_id);
		}
	}

	string gen_common_verse_middle_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	)
	{
		// Build song lines (store in intermediate buffer)
		
		const auto gen_song_line =
			[]
			(
				const verse_data& prev_verse_info,
				const verse_data& current_verse_info
			)
			-> string
			{
				ostringstream line_builder;

				line_builder
					<< "She swallowed the "
					<< current_verse_info.creature_name << " "
					<< "to catch the "
					<< prev_verse_info.creature_name;

				if (!prev_verse_info.creature_epithet.empty())
					line_builder << " " << prev_verse_info.creature_epithet;

				line_builder << ".\n";

				return line_builder.str();
			};
		
		stack<string> song_lines_buffer;
		{
			auto song_definition_itr = song_definition->cbegin();
			const auto song_definition_itr_end = song_definition->cend();

			do
			{
				const auto prev_verse_info = song_definition_itr->second;
				const auto current_verse_info = (++song_definition_itr)->second;

				song_lines_buffer.push(
					gen_song_line(prev_verse_info, current_verse_info)
				);
			} while (
				song_definition_itr->first < verse_id
				&& song_definition_itr != song_definition_itr_end
				);
		}
		
		// Morph song lines buffer to string (XXX: consumes buffer object)
		
		ostringstream middle_lines_builder;
		
		while (!song_lines_buffer.empty())
		{
			middle_lines_builder << song_lines_buffer.top();
			song_lines_buffer.pop();
		}

		const string middle_lines = middle_lines_builder.str();

		return middle_lines;
	}

	string gen_verse_last_lines(
		const song_def_t* song_definition,
		const verse_identifier verse_id
	)
	{
		if (verse_id != find_last_verse_id(song_definition))
		{
			ostringstream final_line_builder;
			final_line_builder
				<< "I don't know why she swallowed the "
				<< find_first_verse_info(song_definition).creature_name << ". "
				<< "Perhaps she'll die.\n";
			
			return final_line_builder.str();
		}
		else
		{
			return "She's dead, of course!\n";
		}
	}

	verse_identifier find_first_verse_id(const song_def_t* song_definition)
	{
		return song_definition->begin()->first;
	}

	verse_identifier find_last_verse_id(const song_def_t* song_definition)
	{
		return song_definition->rbegin()->first;
	}

	verse_data find_first_verse_info(const song_def_t* song_definition)
	{
		return song_definition->at(find_first_verse_id(song_definition));
	}
}
