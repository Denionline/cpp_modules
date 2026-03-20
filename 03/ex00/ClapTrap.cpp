#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{}

ClapTrap::~ClapTrap()
{}

static bool	check_status(int status, std::string action) {
	if (status <= 0) {
		std::cout << "Failed to " << action << std::endl;
		return false;
	}
	return true;
}

void	ClapTrap::attack( const std::string& target ) {
	if (!check_status(_hit_points, "attack") || !check_status(_energy_points, "attack")) {
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (!check_status(_hit_points, "take damage")) {
		return;
	}
	_hit_points = amount > _hit_points ? 0 : _hit_points ;
	std::cout << _name << " took " << amount << " of damage." << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (!check_status(_energy_points, "be repaired")) {
		return;
	}
	_energy_points = amount > _energy_points ? 0 : _energy_points ;
	std::cout << _name << " was repaired " << amount << " points" << std::endl;
}
