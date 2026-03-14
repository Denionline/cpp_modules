
#include "Replace.h"

int	main( int argc, char *argv[] ) {
	(--argc, ++argv);

	if (argc != 3) {
		std::cout << "Invalid number of arguments, try:" << std::endl;
		std::cout << "./replace <file_name> <to_replace> <new_word>";
		std::cout << std::endl;
		return (1);
	}
	return (
		replace(argv[0], argv[1], argv[2])
	);
}
