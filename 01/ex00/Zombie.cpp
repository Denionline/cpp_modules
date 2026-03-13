#include "Zombie.hpp"

Zombie::Zombie(string name) {
	this->name = name;
}

Zombie::~Zombie() {}

void	Zombie::announce(void) {
	cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}