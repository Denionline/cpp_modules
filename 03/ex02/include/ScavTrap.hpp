#ifndef		SCAVTRAP_H
# define	SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap( std::string );
		~ScavTrap();
		ScavTrap&	operator=( const ScavTrap& );

		void	attack( const std::string& );
		void	guardGate( void );
};

#endif