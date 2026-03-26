
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {
	ClapTrap	bob("Bob");
	FragTrap	alice("Alice");
	ClapTrap	copia;

	copia = bob;

	bob.attack("Alice");
	alice.takeDamage(50);
	alice.takeDamage(49);
	alice.highFivesGuys();
	alice.beRepaired(29);
	alice.attack("Bob");
	bob.takeDamage(30);
	bob.beRepaired(15);
	return 0;
}