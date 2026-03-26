#ifndef		SCAVTRAP_H
# define	SCAVTRAP_H

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap( std::string );
		~FragTrap();
		FragTrap&	operator=( const FragTrap& );

		void	highFivesGuys( void );
};

#endif