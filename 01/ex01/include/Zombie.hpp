#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;

class Zombie {
	public:
		Zombie();
		~Zombie();

		void	announce( void );
		void	setName( string );
	private:
		string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif