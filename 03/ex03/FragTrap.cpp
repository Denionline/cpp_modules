#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	print_struction("FragTrap " + _name, "spawned", GREEN);
}

FragTrap::FragTrap( std::string name ) {
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	print_struction("FragTrap " + _name, "spawned", GREEN);
}

FragTrap::~FragTrap() {
	print_struction("FragTrap " + _name, "disappeared", RED);
}

FragTrap&	FragTrap::operator=( const FragTrap& copy ) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	print_struction(copy._name, "assigned to " + _name, YELLOW);
	return (*this);
}

void	FragTrap::highFivesGuys( void ) {
	if (!check_status(_name, _hit_points, "high five")) {
		return;
	}
	std::cout << "FragTrap " << _name << " did a high five" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}
