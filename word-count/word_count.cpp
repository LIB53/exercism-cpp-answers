#include "word_count.h"

using namespace std;


namespace word_count
{
	string to_normalized_word(const string& raw_word)
	{
		auto word_wc = raw_word;
		
		transform(
			word_wc.begin(),
			word_wc.end(),
			word_wc.begin(),
			::tolower
		);

		return word_wc;
	}
	
	words_container scan_words_in_phrase(const string& phrase)
	{
		static const regex word_selector("(\\w([A-Z]|[a-z])*'\\w+)|(\\w+)");
		static const regex_iterator<string::const_iterator> regex_itr_end;
		
		words_container scanned_words_buffer;
		
		for
			(
				regex_iterator<string::const_iterator> word_selector_itr(
					phrase.cbegin(),
					phrase.cend(),
					word_selector
				);
				word_selector_itr != regex_itr_end;
				++word_selector_itr
			)
		{
			const auto& scanned_word = word_selector_itr->str();
			const auto normalized_word = to_normalized_word(scanned_word);
			
			scanned_words_buffer.push_back(normalized_word);
		}

		return scanned_words_buffer;
	}

	word_count_map to_word_count_map(const words_container& words)
	{
		word_count_map word_count_map_buffer;
		
		for (auto w : words)
			++(word_count_map_buffer[w]);

		return word_count_map_buffer;
	}
	
	word_count_map words(const string& phrase)
	{
		return to_word_count_map(scan_words_in_phrase(phrase));
	}
}
