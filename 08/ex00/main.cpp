#include "easyfind.hpp"

int	main( void ) {
	std::vector<int> n;
	n.push_back(3);
	n.push_back(5);

	try {
		std::cout << *(::easyfind(n, 5)) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	const std::vector<int> nconst(n);
	try {
		std::cout << *(::easyfind(n, 5)) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
