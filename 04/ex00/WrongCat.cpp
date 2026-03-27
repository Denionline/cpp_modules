#include "WrongCat.hpp"

// Orthodoxal
WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "Wow there is a " << getType() << " here :)" << std::endl;
}

WrongCat::WrongCat( const std::string newType ) {
	type = newType;
	std::cout << "Wow there is a " << getType() << " here :)" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) {
	std::cout << "An " << getType() << " was copied" << std::endl;
	*this = copy;
}
WrongCat&	WrongCat::operator=( const WrongCat& copy ) {
	std::cout << "The " << copy.getType() << " now is " << copy.type << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "The " << getType() << " passed away :(" << std::endl;
}
