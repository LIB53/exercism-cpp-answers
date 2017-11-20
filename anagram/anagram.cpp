#include "anagram.h"

#include <algorithm>


namespace anagram
{
#pragma region Anagram Comparison Data Class

	anagram_comparison_data::anagram_comparison_data(const std::string word)
	{
		auto base_word_lower = word;
		transform(
			base_word_lower.begin(),
			base_word_lower.end(),
			base_word_lower.begin(),
			::tolower
		);

		auto comparison_key_wc = base_word_lower;
		sort(
			comparison_key_wc.begin(),
			comparison_key_wc.end()
		);

		this->_base_word = base_word_lower;
		this->_comparison_key = comparison_key_wc;
	}

	bool anagram_comparison_data::operator==(const anagram_comparison_data other) const
	{
		return
			this->base_word() != other.base_word()
			&& this->comparison_key() == other.comparison_key();
	}

#pragma endregion


#pragma region Anagram Class

	std::vector<std::string> anagram::matches(const std::vector<std::string> words) const
	{
		std::vector<std::string> matches_buffer;

		for (const auto w : words)
		{
			if (_comparison_data == anagram_comparison_data(w))
				matches_buffer.push_back(w);
		}

		return matches_buffer;
	}

#pragma endregion

}
