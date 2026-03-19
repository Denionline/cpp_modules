#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{}

ClapTrap::~ClapTrap()
{}

void	ClapTrap::attack( const std::string& target ) {
	if (_hit <= 0) {
		std::cout << "Fail to attack (Not enough hit points)" << std::endl;
	}
	if (_energy <= 0) {
		std::cout << "Fail to attack (Not enough energy points)" << std::endl;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	
}
