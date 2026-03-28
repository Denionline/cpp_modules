#ifndef		DOG_H
# define	DOG_H

# include "Animal.hpp"

# pragma once

class Dog: public Animal {
	private:
		Brain*		brain;
	public:
		Dog();
		Dog( const std::string );
		Dog( const Dog& );
		Dog& operator=( const Dog& );
		~Dog();

		void	makeSound( void ) const;
};

#endif