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
		if (argc > 3000) throw PmergeMe::ExceptionError();
		PmergeMe	numbers(argv, argc);


		std::cout << "Before: " << numbers << std::endl;

		timeval	s, e;
		gettimeofday(&s, NULL);
		numbers.FJASlist();
		gettimeofday(&e, NULL);

		double listElapsed = (e.tv_sec - s.tv_sec) * 1e6 + (e.tv_usec - s.tv_usec);

		gettimeofday(&s, NULL);
		numbers.FJASqueue();
		gettimeofday(&e, NULL);

		double queueElapsed = (e.tv_sec - s.tv_sec) * 1e6 + (e.tv_usec - s.tv_usec);

		std::cout << "After:  " << numbers << std::endl;

		std::cout
		<< "Time to process a range of "
		<< argc
		<< " elements with std::list : "
		<< std::fixed << std::setprecision(5) << listElapsed / 1e6 << " us"
		<< std::endl;

		std::cout
		<< "Time to process a range of "
		<< argc
		<< " elements with std::queue : "
		<< std::fixed << std::setprecision(5) << queueElapsed / 1e6 << " us"
		<< std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
