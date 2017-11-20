#include "bracket_push.h"

#include <stack>


namespace bracket_push
{
	bool check(const std::string s)
	{
		enum class bracket { square, curly, parens };

		std::stack<bracket> bracket_signals;

		const auto is_valid_closing_bracket =
			[&bracket_signals](bracket closing_bracket_type)
		{
			return
				!bracket_signals.empty()
				&& bracket_signals.top() == closing_bracket_type;
		};

		for (const auto& c : s)
		{
			switch (c)
			{
			case '[':
				bracket_signals.push(bracket::square);
				break;
			case ']':
				if (is_valid_closing_bracket(bracket::square))
					bracket_signals.pop();
				else
					return false;
				break;
			case '{':
				bracket_signals.push(bracket::curly);
				break;
			case '}':
				if (is_valid_closing_bracket(bracket::curly))
					bracket_signals.pop();
				else
					return false;
				break;
			case '(':
				bracket_signals.push(bracket::parens);
				break;
			case ')':
				if (is_valid_closing_bracket(bracket::parens))
					bracket_signals.pop();
				else
					return false;
				break;
			}
		}

		return bracket_signals.empty();
	}
}
