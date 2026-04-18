#include "Span.hpp"

Span::Span( void ) {
	_numbers.reserve(1);
}

Span::Span( __int32_t n ) {
	_numbers.reserve(n);
}

Span::~Span()
{}


void	Span::addNumber( int newNumber ) {
	_numbers.push_back(newNumber);
}

__int32_t	Span::shortestSpan( void ) {
	std::vector<int>	copy(_numbers);

	std::sort(copy.begin(), copy.end());

	__int32_t	result = abs(copy[0] - copy[1]);
	size_t		size = copy.size();

	for (size_t i = 0; i < size; i++) {
		if ((i + 1) < size) {
			__int32_t	check = abs(copy[i] - copy[i + 1]);
			if (check < result) {
				result = check;
			}
		}
	}
	return (result);
}

__int32_t	Span::longestSpan( void ) {
	std::vector<int>	copy(_numbers);

	std::sort(copy.begin(), copy.end());

	__int32_t	result = abs(copy[0] - copy[1]);
	size_t		size = copy.size();

	for (size_t i = 0; i < size; i++) {
		if ((i + 1) < size) {
			__int32_t	check = abs(copy[i] - copy[i + 1]);
			if (check > result) {
				result = check;
			}
		}
	}
	return (result);
}

void	Span::print( void ) {
	std::vector<int>	copy(_numbers);

	std::sort(copy.begin(), copy.end());

	std::cout << "{";
	size_t	size = copy.size();
	for (size_t i = 0; i < size; i++) std::cout << copy[i] << ((i + 1) < size ? ", " : "");
	std::cout << "}" << std::endl;
}
