#ifndef		CLAPTRAP_H
# define	CLAPTRAP_H

#include <iostream>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap();
		~ClapTrap();

		void	attack( const std::string& );
		void	takeDamage( unsigned int );
		void	beRepaired( unsigned int );
};

#endif