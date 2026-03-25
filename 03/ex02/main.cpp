
#include "ScavTrap.hpp"

int	main( void ) {
	ClapTrap	bob("Bob");
	ScavTrap	alice("Alice");
	ClapTrap	copia;

	copia = bob;

	bob.attack("Alice");
	alice.takeDamage(5);
	alice.guardGate();
	alice.beRepaired(3);
	alice.attack("Bob");
	bob.takeDamage(30);
	bob.beRepaired(15);
	return 0;
}