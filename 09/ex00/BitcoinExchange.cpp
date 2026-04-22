#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::fstream	file("data.csv");

	if (!file.is_open())
		throw FileNotFound();

	/* Loop for each line */
	std::string	line;
	while (std::getline(file, line)) {
		std::stringstream	sline(line);

		/* Loop for each cell */
		Data				data = {};
		std::string	cell;
		for (int times = 0; std::getline(sline, cell, ','); times++) {
			if (times == 0) {
				data.date.tm_year = std::atoi(cell.substr(0,4).c_str()) - 1900;
				data.date.tm_mon  = std::atoi(cell.substr(5,2).c_str()) - 1;
				data.date.tm_mday = std::atoi(cell.substr(8,2).c_str());
			} else if (times == 1) {
				if (cell.length() > 8)
					throw CSVInvalidRate();
				float	n = std::atof(cell.c_str());
				if (n < 0 || n > 1000)
					throw CSVInvalidRate();
				data.rate = n;
			} else {
				throw CSVInvalidArgument();
			}
		}
	}
}

// BitcoinExchange::BitcoinExchange( const BitcoinExchange& ) {}

// BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& ) {}

BitcoinExchange::~BitcoinExchange()
{}