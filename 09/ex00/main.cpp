#include "BitcoinExchange.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);
	try {

		BitcoinExchange	b;

		std::vector<Data>	input = BitcoinExchange::parseDataFile(*argv);

		b.executeExchange(input);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

}