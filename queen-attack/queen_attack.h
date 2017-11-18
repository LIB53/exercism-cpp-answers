#pragma once

#include <utility>
#include <stdexcept>
#include <string>


#define OVERLAPPING_POSITIONS_EXCEPT std::domain_error("Positions cannot overlap.")

namespace queen_attack
{
	class chess_board
	{
	private:
		std::pair<int, int> _white = { 0, 3 };
		std::pair<int, int> _black = { 7, 3 };
	public:
		std::pair<int, int> white() const { return _white; }
		std::pair<int, int> black() const { return _black; }
		
		chess_board() = default;

		chess_board(
			std::pair<int, int> white_pos,
			std::pair<int, int> black_pos
		)
			: _white{ white_pos }, _black{ black_pos }
		{
			if (_white == _black) throw OVERLAPPING_POSITIONS_EXCEPT;
		}

		bool can_attack() const;
		operator std::string() const;
	};
}
