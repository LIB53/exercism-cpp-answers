#include "allergies.h"


namespace allergies
{
	std::string encode_cause(allergy_cause cause)
	{
		switch (cause)
		{
		case allergy_cause::eggs: return "eggs";
		case allergy_cause::peanuts: return "peanuts";
		case allergy_cause::shellfish: return "shellfish";
		case allergy_cause::strawberries: return "strawberries";
		case allergy_cause::tomatoes: return "tomatoes";
		case allergy_cause::chocolate: return "chocolate";
		case allergy_cause::pollen: return "pollen";
		case allergy_cause::cats: return "cats";
		default:
			return std::string{};
		}
	}

	allergy_cause decode_cause_name(std::string cause_name)
	{
		if (cause_name == "eggs")
			return allergy_cause::eggs;
		else if (cause_name == "peanuts")
			return allergy_cause::peanuts;
		else if (cause_name == "shellfish")
			return allergy_cause::shellfish;
		else if (cause_name == "strawberries")
			return allergy_cause::strawberries;
		else if (cause_name == "tomatoes")
			return allergy_cause::tomatoes;
		else if (cause_name == "chocolate")
			return allergy_cause::chocolate;
		else if (cause_name == "pollen")
			return allergy_cause::pollen;
		else if (cause_name == "cats")
			return allergy_cause::cats;
		else
			throw cause_name_decode_error();
	}

	bool allergy_test::is_allergic_to(allergy_cause cause) const
	{
		return _cause_flags.test(cause);
	}

	bool allergy_test::is_allergic_to(std::string cause_name) const
	{
		try
		{
			return _cause_flags.test(decode_cause_name(cause_name));
		}
		catch (cause_name_decode_error)
		{
			return false;
		}
	}
	
	std::unordered_set<std::string> allergy_test::get_allergies() const
	{
		std::unordered_set<std::string> causes_buffer;
		
		for (
			size_t flag_index_itr = 0;
			flag_index_itr < _cause_flags.size();
			flag_index_itr++
			)
		{
			if (_cause_flags.test(flag_index_itr))
			{
				causes_buffer.insert(
					encode_cause(allergy_cause(flag_index_itr))
				);
			}
		}

		return causes_buffer;
	}

	int allergy_test::get_score() const
	{
		unsigned int score_acc = 0;
		
		for (
			size_t flag_index_itr = 0;
			flag_index_itr < _cause_flags.size();
			flag_index_itr++
			)
		{
			if (_cause_flags.test(flag_index_itr))
				score_acc += 1 << flag_index_itr;
		}

		return score_acc;
	}
}
