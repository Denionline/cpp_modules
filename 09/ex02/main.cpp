#include "PmergeMe.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);

	if (!argc) {
		std::cout
		<< "Correct use: ./PmergeMe [positive numbers...]"
		<< std::endl;
		return (1);
	}

	PmergeMe	numbers(argv, argc);

	numbers.print();
}
