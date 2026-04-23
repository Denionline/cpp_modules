#include "BitcoinExchange.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);

	std::string	inputFile = !argc ? "" : *argv;

	BitcoinExchange	b;

	std::vector<Data>	input = BitcoinExchange::parseDataFile(inputFile);

	b.executeExchange(input);
}