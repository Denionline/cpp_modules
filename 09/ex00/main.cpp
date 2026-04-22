#include "BitcoinExchange.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);
	if (argc != 1) {
		std::cout << "Correct usage: ./btc <file.txt>" << std::endl;
		return (1);
	}
	BitcoinExchange	b;

	std::vector<Data>	input = BitcoinExchange::parseDataFile(*argv);

	BitcoinExchange::print(input);
}