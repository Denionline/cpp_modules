#include "RPN.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);

	if (argc != 1) {
		std::cout
		<< "Correct usage: ./RPN \"<Reverse Polish Notation>\""
		<< std::endl;
		return (1);
	}

	try {
		RPN	notation(*argv);

		notation.resolveNotation();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
