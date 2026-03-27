#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_name = "Scavex";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	print_struction("ScavTrap " + _name, "created", GREEN);
}

ScavTrap::ScavTrap( std::string name ) {
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	print_struction("ScavTrap " + _name, "created", GREEN);
}

ScavTrap::ScavTrap( const ScavTrap& copy) {
	*this = copy;
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

ScavTrap::~ScavTrap() {
	print_struction("ScavTrap " + _name, "destroyed", RED);
}

void	ScavTrap::attack( const std::string& target ) {
	if (!check_status(_name, _hit_points, "attack") || !check_status(_name,_energy_points, "attack")) {
		return;
	}
	std::cout << "ScavTrap " << _name << " punch " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}

void	ScavTrap::guardGate( void ) {
	if (!check_status(_name, _hit_points, "guard gate")) {
		return;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}