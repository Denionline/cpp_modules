#ifndef		ANIMAL_H
# define	ANIMAL_H

# include "Brain.hpp"

# pragma once

class Animal {
	protected:
		std::string	type;
	public:
		/* Orthodoxal */
		Animal();
		Animal( const std::string );
		Animal( const Animal& );
		Animal& operator=( const Animal& );
		virtual ~Animal();

		/* Mandatory functions */
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;

		/* Extra functions */
		virtual void	thinkSound( void ) = 0;
		virtual void	forgotSound( void ) = 0;
		virtual void	showThoughts( void ) = 0;
};

#endif
