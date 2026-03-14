#include "HumanB.hpp"

HumanB::HumanB( std::string name ):
	_name(name)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
}

void	HumanB::attack( void ) {
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << (_weapon ? (*_weapon).getType() : "NULL");
	std::cout << std::endl;
}
