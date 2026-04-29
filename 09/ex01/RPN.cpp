#include "RPN.hpp"

static bool isArgValid( char c ) {
	if (c == '+') return (true);
	if (c == '-') return (true);
	if (c == '*') return (true);
	if (c == '/') return (true);
	if (std::isdigit(c)) return (true);
	return (false);
}

RPN::RPN() {}


RPN::RPN( std::string s ) {
	if (s.empty()) {
		throw ExceptionError();
	}

	std::stringstream	ss(s);
	std::string				arg;
	while (std::getline(ss, arg, ' ')) {
		if (arg.empty()) continue;
		if (arg.length() > 1 || !isArgValid(arg.at(0))) {
			throw ExceptionError();
		}
		_data.push_back(arg.at(0));
	}
}

RPN::RPN( const RPN& copy ) {
	*this = copy;
}

RPN&	RPN::operator=( const RPN& copy ) {
	if (this != &copy) {
		this->_data = copy._data;
	}
	return (*this);
}

RPN::~RPN()
{}

static int	resolveCalc( int n1 , int n2 , char sig ) {
	if (sig == '+') return (n1 + n2);
	if (sig == '-') return (n1 - n2);
	if (sig == '*') return (n1 * n2);
	if (sig == '/') return (n1 / n2);
	return (0);
}

void	RPN::resolveNotation( void ) {
	const size_t			size = _data.size();
	std::deque<int>	numbers;

	if (size < 3)
		throw ExceptionError();
	for (size_t i = 0; i < size; i++) {
		if (std::isdigit(_data[i])) {
			numbers.push_back(_data[i] - '0');
		} else {
			if (numbers.size() < 2)
				throw ExceptionError();

			const size_t	nSize = numbers.size();
			int	n1 = numbers[nSize - 1], n2 = numbers[nSize - 2];
			int	n = resolveCalc(n2, n1, _data[i]);
			numbers.pop_back();
			numbers.pop_back();
			numbers.push_back(n);
		}
	}
	std::cout << numbers[0] << std::endl;
}
