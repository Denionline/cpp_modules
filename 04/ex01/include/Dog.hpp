#ifndef		DOG_H
# define	DOG_H

#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog( const std::string );
		Dog( const Dog& );
		Dog& operator=( const Dog& );
		~Dog();

		void	makeSound( void ) const;
};

#endif