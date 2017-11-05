# if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <vector>
#include <string>
#include <algorithm>


namespace anagram
{
	class anagram_comparison_data
	{
	public:
		anagram_comparison_data(const std::string& word = "");
		const std::string& base_word() const noexcept { return _base_word; }
		const std::string& comparison_key() const noexcept { return _comparison_key; }
		bool compare_with(const anagram_comparison_data other);

	private:
		std::string _base_word;
		std::string _comparison_key;
	};

	class anagram
	{
	public:
		anagram(std::string word);
		bool is_match_with(const std::string& words);
		std::vector<std::string> matches(const std::vector<std::string>& words);

	private:
		anagram::anagram_comparison_data comparison_data;
	};
}

#endif