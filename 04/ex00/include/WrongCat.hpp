#ifndef		WRONG_CAT_H
# define	WRONG_CAT_H

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat( const std::string );
		WrongCat( const WrongCat& );
		WrongCat& operator=( const WrongCat& );
		~WrongCat();
};

#endif