#ifndef		WRONG_CAT_H
# define	WRONG_CAT_H

# include "WrongAnimal.hpp"

# pragma once

class WrongCat: public WrongAnimal {
	public:
		/* Orthodoxal */
		WrongCat();
		WrongCat( const std::string );
		WrongCat( const WrongCat& );
		WrongCat& operator=( const WrongCat& );
		~WrongCat();
};

#endif