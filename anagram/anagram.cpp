#include "anagram.h"

using namespace std;


namespace anagram
{
#pragma region Anagram Comparison Data Class

	anagram_comparison_data::anagram_comparison_data(const string word)
	{
		auto base_word_wc = word;
		transform(
			base_word_wc.begin(),
			base_word_wc.end(),
			base_word_wc.begin(),
			::tolower
		);

		auto comparison_key_wc = base_word_wc;
		sort(
			comparison_key_wc.begin(),
			comparison_key_wc.end()
		);

		this->_base_word = base_word_wc;
		this->_comparison_key = comparison_key_wc;
	}

	bool anagram_comparison_data::compare_with(const anagram_comparison_data other)
	{
		return
			this->base_word() != other.base_word()
			&& this->comparison_key() == other.comparison_key();
	}

#pragma endregion


#pragma region Anagram Class

	bool anagram::is_match_with(const string word)
	{
		return
			this->comparison_data.compare_with(anagram_comparison_data(word));
	}

	vector<string> anagram::matches(const vector<string> words)
	{
		vector<string> matches_buffer;

		for (auto w : words)
		{
			if (this->is_match_with(w))
				matches_buffer.push_back(w);
		}

		return matches_buffer;
	}

#pragma endregion

}
