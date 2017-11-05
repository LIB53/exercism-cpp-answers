#include "anagram.h"
using namespace std;


namespace anagram
{
#pragma region Anagram Comparison Data Class

	anagram_comparison_data::anagram_comparison_data(const std::string& word)
	{
		auto base_word_buffer = string(word);
		transform(
			base_word_buffer.begin(),
			base_word_buffer.end(),
			base_word_buffer.begin(),
			::tolower
		);

		auto comparison_key_buffer = string(base_word_buffer);
		sort(
			comparison_key_buffer.begin(),
			comparison_key_buffer.end()
		);

		this->_base_word = base_word_buffer;
		this->_comparison_key = comparison_key_buffer;
	}

	bool anagram_comparison_data::compare_with(anagram_comparison_data other)
	{
		return
			this->base_word() != other.base_word()
			&& this->comparison_key() == other.comparison_key();
	}

#pragma endregion


#pragma region Anagram Class

	anagram::anagram(string word)
	{
		this->comparison_data = anagram_comparison_data(word);
	}
	
	bool anagram::is_match_with(const string& word)
	{
		return
			this->comparison_data.compare_with(anagram_comparison_data(word));
	}

	vector<string> anagram::matches(const vector<string>& words)
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
