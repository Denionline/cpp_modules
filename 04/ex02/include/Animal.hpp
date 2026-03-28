#ifndef		ANIMAL_H
# define	ANIMAL_H

# include "Brain.hpp"

# pragma once

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal( const std::string );
		Animal( const Animal& );
		Animal& operator=( const Animal& );
		virtual ~Animal();

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
};

#endif
