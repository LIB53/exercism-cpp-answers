#pragma once

#include <bitset>
#include <string>
#include <unordered_set>


namespace allergies
{
	enum allergy_cause : uint8_t
	{
		eggs,
		peanuts,
		shellfish,
		strawberries,
		tomatoes,
		chocolate,
		pollen,
		cats
	};

	std::string encode_cause(allergy_cause cause);
	allergy_cause decode_cause_name(std::string cause_name);

	class allergy_test
	{
	private:
		std::bitset<8> _cause_flags;
	public:
		allergy_test() = default;
		allergy_test(uint8_t allergy_score) : _cause_flags{allergy_score} {}
		bool is_allergic_to(std::string cause_name) const;
		std::unordered_set<std::string> get_allergies() const;

		/* bonus */
		bool is_allergic_to(allergy_cause cause) const;
		int allergy_test::get_score() const;
	};

	class cause_name_decode_error : std::domain_error
	{
	public:
		cause_name_decode_error() : domain_error("Failed to decode cause name.") {}
	};
}
