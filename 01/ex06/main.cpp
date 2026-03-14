
#include "Harl.hpp"

int	main( int argc, char *argv[] ) {
	(--argc, ++argv);

	if (argc != 1) {
		std::cout << "Invalid number of arguments, try:" << std::endl;
		std::cout << "./harl <DEBUG || INFO || WARNING || ERROR>" << std::endl;
		return (1);
	}

	Harl	harl;

	harl.complain(argv[0]);
	return (0);
}
