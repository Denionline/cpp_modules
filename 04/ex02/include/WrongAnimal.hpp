#ifndef		WRONG_ANIMAL_H
# define	WRONG_ANIMAL_H

# include "Brain.hpp"

# pragma once

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal( const std::string );
		WrongAnimal( const WrongAnimal& );
		WrongAnimal& operator=( const WrongAnimal& );
		virtual ~WrongAnimal();

		std::string			getType( void ) const;
		virtual void		makeSound( void ) const;
};

#endif
