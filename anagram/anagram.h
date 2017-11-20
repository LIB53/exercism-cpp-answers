#pragma once

#include <string>
#include <vector>


namespace anagram
{
	class anagram_comparison_data
	{
	public:
		anagram_comparison_data(const std::string word);
		std::string base_word() const { return _base_word; }
		std::string comparison_key() const { return _comparison_key; }
		bool operator==(const anagram_comparison_data other) const;

	private:
		std::string _base_word;
		std::string _comparison_key;
	};

	class anagram
	{
	public:
		anagram(const std::string word) : _comparison_data{ word } {}
		std::vector<std::string> matches(const std::vector<std::string> words) const;
	private:
		anagram_comparison_data _comparison_data;
	};
}
