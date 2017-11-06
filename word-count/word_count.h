#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>


namespace word_count
{
	typedef std::map<std::string, int> word_count_map;
	typedef std::vector<std::string> words_container;

	std::string to_normalized_word(const std::string& raw_word);
	words_container scan_words_in_phrase(const std::string& phrase);
	word_count_map to_word_count_map(const words_container& words);
	word_count_map words(const std::string& phrase);
}

#endif