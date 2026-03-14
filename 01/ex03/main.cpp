
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main( void ) {
	{
		Weapon club = Weapon("Sword");
		HumanA bob("Leonidas", club);
		bob.attack();
		club.setType("Axe");
		bob.attack();
	}
	{
		Weapon club = Weapon("Sword");
		HumanB jim("Sr. Arthur");
		jim.setWeapon(club);
		jim.attack();
		club.setType("AK47");
		jim.attack();
	}
}