#include "BitcoinExchange.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);
	if (argc != 1) {
		std::cout << "Correct usage: ./btc <file.txt>" << std::endl;
		return (1);
	}
	try	{
		BitcoinExchange	b;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

}