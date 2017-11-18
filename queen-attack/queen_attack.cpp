#include "queen_attack.h"

#include <iomanip>
#include <math.h>
#include <sstream>


namespace queen_attack
{
	bool chess_board::can_attack() const
	{
		// Test same row
		
		if (white().first == black().first
			|| white().second == black().second)
			return true;

		// Test diagonal
		
		if (abs(white().first - black().first)
			== abs(white().second - black().second))
			return true;

		return false;
	}
	
	chess_board::operator std::string() const
	{
		const auto solve_piece_image_index = [](const int row, const int col)
		{
			return ((8 * 2) * row) + (col * 2);
		};
		
		const int white_index =
			solve_piece_image_index(white().first, white().second);

		const int black_index =
			solve_piece_image_index(black().first, black().second);

		std::string board_image =
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n"
			"_ _ _ _ _ _ _ _\n";
		board_image[white_index] = 'W';
		board_image[black_index] = 'B';

		return board_image;
	}
}
