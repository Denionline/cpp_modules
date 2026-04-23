#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _data()
{}

PmergeMe::PmergeMe( char *args[] , size_t len ) {
	for (size_t i = 0; i < len; i++) {
		_data.push(std::atoi(args[i]));
	}
}

PmergeMe::~PmergeMe()
{}

void

void	PmergeMe::print( void ) {
	std::queue<size_t>	n(_data);
	while (!n.empty()) {
		std::cout << n.front() << std::endl;
		n.pop();
	}
}