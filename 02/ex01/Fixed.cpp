
#include "Fixed.hpp"

Fixed::Fixed( const Fixed& copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const float number ) {
	std::cout << "Float constructor called" << std::endl;
	_number = roundf(number * (1 << _fract));
}

Fixed::Fixed( const int number ) {
	std::cout << "Int constructor called" << std::endl;
	_number = (number << _fract);
}


Fixed::Fixed() {
	_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_number = other.getRawBits();
	}
	return (*this);
}

void	Fixed::setRawBits( int const raw ) {
		_number = raw;
		std::cout << "setRawBits member function called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
		std::cout << "getRawBits member function called" << std::endl;
		return (_number);
}


float	Fixed::toFloat() const {
	return ((float)_number / (1 << _fract));
}

int		Fixed::toInt() const {
	return (_number >> _fract);
}

std::ostream&	operator<<( std::ostream& o, const Fixed& f ) {
	o << f.toFloat();
	return (o);
}