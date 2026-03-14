
#ifndef		WEAPON_H
# define	WEAPON_H

#include <iostream>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon( std::string );
		~Weapon();

		void		setType( std::string newType );
		std::string	getType( void ) const;
};

#endif