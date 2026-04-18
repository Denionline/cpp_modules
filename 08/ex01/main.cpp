#include "Span.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, ++argv);
	if (!(!argc || std::string(*argv).length() > 5)) {
		size_t	size = strtol(*argv, NULL, 10);
		try {
			Span array(size);

			std::vector<int>	starts;

			starts.push_back(42);
			starts.push_back(24);

			array.addMultipleNumbers(starts);

			std::srand(std::time(NULL));
			for (size_t i = 0; i < size - 2;) {
				size_t	randN = std::rand() % 99999;
				if (array.find_number(randN))
					continue;
				array.addNumber(randN);
				i++;
			}

			array.print();

			std::cout << "The shortest number distance is => "
			<< array.shortestSpan()
			<< std::endl;

			std::cout << "The longest number distance is => "
			<< array.longestSpan()
			<< std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}