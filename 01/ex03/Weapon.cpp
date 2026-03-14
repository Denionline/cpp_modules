
#include "Weapon.hpp"

Weapon::Weapon( std::string type ):
	_type(type)
{}

Weapon::~Weapon()
{}

void	Weapon::setType( std::string newType ) {
	_type = newType;
}

std::string	Weapon::getType( void ) const {
	return (_type);
}