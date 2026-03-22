
#include "Fixed.hpp"

Fixed::Fixed( const Fixed& copy ) {
	*this = copy;
}

Fixed::Fixed( const float number ):
	_number(roundf(number * (1 << _fract)))
{}

Fixed::Fixed( const int number ):
	_number(number << _fract)
{}


Fixed::Fixed(): _number(0)
{}

Fixed::~Fixed()
{}

void	Fixed::setRawBits( int const raw ) {
	_number = raw;
}

int		Fixed::getRawBits( void ) const {
		return (_number);
}

float	Fixed::toFloat() const {
	return ((float)_number / (1 << _fract));
}

int		Fixed::toInt() const {
	return (_number >> _fract);
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_number = other.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>( const Fixed& other ) const {
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<( const Fixed& other ) const {
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==( const Fixed& other ) const {
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=( const Fixed& other ) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+( const Fixed& other ) {
	return (
		Fixed(this->getRawBits() + other.getRawBits())
	);
}

Fixed	Fixed::operator-( const Fixed& other ) {
	return (
		Fixed(this->getRawBits() - other.getRawBits())
	);
}

Fixed	Fixed::operator*( const Fixed& other ) {
	Fixed	f;
	long	result;

	result = this->getRawBits() * other.getRawBits();
	f.setRawBits(result >> _fract);
	return (f);
}

Fixed	Fixed::operator/( const Fixed& other ) {
	return (
		Fixed(this->getRawBits() / other.getRawBits())
	);
}

Fixed&	Fixed::operator++( void ) {
	this->_number = (this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	f;

	f.setRawBits(this->getRawBits());
	this->_number++;
	return (f);
}

Fixed&	Fixed::operator--( void ) {
	this->_number = (this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	f;

	f.setRawBits(this->getRawBits());
	this->_number--;
	return (f);
}

Fixed&	Fixed::max( Fixed& f1, Fixed& f2 ) {
	return ( f1 > f2 ? f1 : f2);
}

const Fixed&	Fixed::max( const Fixed& f1, const Fixed& f2 ) {
	return ( f1 > f2 ? f1 : f2);
}

Fixed&	Fixed::min( Fixed& f1, Fixed& f2 ) {
	return ( f1 < f2 ? f1 : f2);
}

const Fixed&	Fixed::min( const Fixed& f1, const Fixed& f2 ) {
	return ( f1 < f2 ? f1 : f2);
}

std::ostream&	operator<<( std::ostream& o, const Fixed& f ) {
	return (o << f.toFloat());
}