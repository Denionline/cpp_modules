#include "PmergeMe.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, argv++);

	if (!argc) {
		std::cout
		<< "Correct use: ./PmergeMe [positive numbers...]"
		<< std::endl;
		return (1);
	}

	try {
		PmergeMe	numbers(argv, argc);


		std::cout << "Before: ";
		numbers.printList();

		timeval	s, e;
		gettimeofday(&s, NULL);
		numbers.FJASlist();
		gettimeofday(&e, NULL);

		double listElapsed = (e.tv_sec - s.tv_sec) * 1e6 + (e.tv_usec - s.tv_usec);

		(void)listElapsed;

	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
