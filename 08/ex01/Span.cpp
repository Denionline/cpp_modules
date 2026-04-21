#include "Span.hpp"

Span::Span( void ): _maxSize(1) {
	_numbers.reserve(1);
}

Span::Span( __int32_t n ): _maxSize(n) {
	_numbers.reserve(n);
}

Span::Span( const Span& copy ) {
	*this = copy;
}

Span&	Span::operator=( const Span& copy ) {
	if (this != &copy) {
		this->_numbers = copy._numbers;
		this->_maxSize = copy._maxSize;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber( int newNumber ) {
	if (_numbers.size() >= _maxSize)
		throw MaxValuesReached();
	_numbers.push_back(newNumber);
}

void	Span::addMultipleNumbers( int newNumbers[] , size_t size ) {
	if ((_numbers.size() + size) > _maxSize)
		throw MaxValuesReached();

	for (size_t i = 0; i < size; i++) {
		_numbers.push_back(newNumbers[i]);
	}
}

void	Span::addMultipleNumbers( std::vector<int> news ) {
	if (_numbers.size() + std::distance(news.begin(), news.end()) > _maxSize)
		throw MaxValuesReached();

	_numbers.insert(_numbers.end(), news.begin(), news.end());
}

size_t	Span::shortestSpan( void ) {
	if (_numbers.size() <= 1)
		throw NotEnoughNumbers();

	std::vector<int>	copy(_numbers);

	std::sort(copy.begin(), copy.end());

	size_t	result = abs(copy[0] - copy[1]);
	size_t		size = copy.size();

	for (size_t i = 0; i < size; i++) {
		if ((i + 1) < size) {
			size_t	check = abs(copy[i] - copy[i + 1]);
			if (check < result) {
				result = check;
			}
		}
	}
	return (result);
}

size_t	Span::longestSpan( void ) {
	if (_numbers.size() <= 1)
		throw NotEnoughNumbers();

	std::vector<int>	copy(_numbers);

	std::sort(copy.begin(), copy.end());

	return (*(copy.end() - 1) - *copy.begin());
}

void	Span::print( void ) {
	std::vector<int>	copy(_numbers);

	std::sort(copy.begin(), copy.end());

	std::cout << "{";
	size_t	size = copy.size();
	for (size_t i = 0; i < size; i++) std::cout << copy[i] << ((i + 1) < size ? ", " : "");
	std::cout << "}" << std::endl;
}

bool	Span::find_number( size_t n ) {
	if (std::find(_numbers.begin(), _numbers.end(), n) != _numbers.end())
		return (true);
	return (false);
}