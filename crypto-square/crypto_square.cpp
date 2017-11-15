#include "crypto_square.h"


namespace crypto_square
{
	std::string cipher::normalize_plain_text() const
	{
		std::ostringstream buffer;

		for (char c : plain_text)
		{
			const char c_lower = tolower(c);

			if (isalnum(c_lower))
				buffer << c_lower;
		}

		return buffer.str();
	}
	
	std::vector<std::string> cipher::plain_text_segments() const
	{
			const size_t num_cols =
				int(ceil(sqrt(normalized_text.length())));

			std::vector<std::string> segments_buffer;
			std::ostringstream row_buffer;
			
			size_t col_counter = 1;
			for (const char c : normalized_text)
			{
				row_buffer << c;

				if (col_counter < num_cols)
				{
					col_counter++;
				}
				else // segment complete
				{
					col_counter = 1;
					segments_buffer.push_back(row_buffer.str());
					row_buffer = std::ostringstream{};
				}
			}

			/*
				XXX: Maybe push last row.
				
				If segments are uneven,
				then the last row was not pushed.
			*/
			if (col_counter != 1)
				segments_buffer.push_back(row_buffer.str());

			return segments_buffer;
	}

	std::string cipher::cipher_text() const
	{

		const auto segments = plain_text_segments();

		// Guard
		
		if (segments.empty())
			return "";
		
		// Parse segments column-wise
		
		const auto parse_column =
			[]
			(
				const std::vector<std::string>& segments,
				const size_t column_index
			)
			-> std::string
			{
				std::ostringstream buffer;
			
				for (const auto segment : segments)
				{
					if (column_index < segment.length())
						buffer << segment.at(column_index);
				}

				return buffer.str();
			};

		std::ostringstream buffer;
		
		for (
			size_t column_index_itr = 0;
			column_index_itr < segments.front().length();
			column_index_itr++
		) // for each column
		{
			buffer << parse_column(segments, column_index_itr);
		}

		return buffer.str();
	}

	std::string cipher::normalized_cipher_text() const
	{
		const auto normalized_text = normalize_plain_text();
		
		const size_t num_cols =
			int(sqrt(normalized_text.length()));
		
		const size_t num_rows =
			int(ceil(sqrt(normalized_text.length())));

		// Map text to rows

		std::vector<std::ostringstream> text_rows_buffer(num_rows);
		{
			size_t row_itr = 0;
			for (const char c : normalized_text)
			{
				text_rows_buffer[row_itr % num_rows] << c;
				row_itr++;
			}
		}

		// Format and compile rows into string

		std::ostringstream text_buffer;

		for (size_t row_itr = 0; row_itr < num_rows; row_itr++)
		{
			// Format text
			
			auto formatted_row_text = text_rows_buffer[row_itr].str();
			formatted_row_text.resize(num_cols, ' ');
			
			// Compile formatted text
			
			text_buffer << formatted_row_text;

			// - maybe append delimiter
			
			if (row_itr != num_rows - 1)
				text_buffer << ' ';
		}

		return text_buffer.str();
	}
}
