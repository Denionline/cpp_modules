
#include "ScalarConverter.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, ++argv);

	if (argc != 1) {
		std::cout << "Correct usage: ./exec <number>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(std::string(*argv));
	return (0);
}