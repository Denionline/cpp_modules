#include "Span.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, ++argv);
	if (!argc || std::string(*argv).length() > 8) return (1);

	size_t	size = strtol(*argv, NULL, 10);
	Span array(size);

	std::srand(std::time(NULL));
	for (size_t i = 0; i < size; i++) {
		array.addNumber(std::rand() % 100);
	}

	array.print();

	std::cout << "The shortest number distance is => "
	<< array.shortestSpan()
	<< std::endl;
	std::cout << "The longest number distance is => "
	<< array.longestSpan()
	<< std::endl;
}