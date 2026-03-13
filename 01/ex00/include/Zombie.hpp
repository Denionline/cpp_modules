#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

using std::string;
using std::cout;
using std::cin;

class Zombie {
	public:
		Zombie(string name);
		~Zombie();

		void	announce(void);
		Zombie*	newZombie(string name);
	private:
		string	name;
};

Zombie*	newZombie(string name);
void	randomChump(string name);

#endif