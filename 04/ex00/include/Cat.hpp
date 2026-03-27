#ifndef		CAT_H
# define	CAT_H

#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat( const std::string );
		Cat( const Cat& );
		Cat& operator=( const Cat& );
		~Cat();

		void	makeSound( void ) const;
};

#endif