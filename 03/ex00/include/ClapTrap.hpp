#ifndef		CLAPTRAP_H
# define	CLAPTRAP_H

#include <iostream>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack_damage;

	public:
		ClapTrap();
		~ClapTrap();

		void	attack( const std::string& );
		void	takeDamage( unsigned int );
		void	beRepaired( unsigned int );
};

#endif