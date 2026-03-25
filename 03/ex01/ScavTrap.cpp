#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_hit_points = MAX_HP;
	_energy_points = MAX_EP;
	_attack_damage = MAX_AD;
	print_struction("ScavTrap " + _name, "created", GREEN);
}

ScavTrap::ScavTrap( std::string name ) {
	_name = name;
	_hit_points = MAX_HP;
	_energy_points = MAX_EP;
	_attack_damage = MAX_AD;
	print_struction("ScavTrap " + _name, "created", GREEN);
}

ScavTrap::~ScavTrap() {
	print_struction("ScavTrap " + _name, "destroyed", RED);
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& copy ) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	print_struction(copy._name, "assigned to " + _name, YELLOW);
	return (*this);
}

static bool	check_status(int status, std::string action) {
	if (status <= 0) {
		std::cout << "Failed to " << action << std::endl;
		return false;
	}
	return true;
}

void	ScavTrap::attack( const std::string& target ) {
	if (!check_status(_hit_points, "attack") || !check_status(_energy_points, "attack")) {
		return;
	}
	std::cout << "ScavTrap " << _name << " punch " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}