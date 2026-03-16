
#include "Fixed.hpp"

Fixed::Fixed( Fixed& copy ) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
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

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_number);
}