
#ifndef		ANIMAL_H
# define	ANIMAL_H

#pragma once

#include <iostream>

# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BG_DARK "\033[48;5;235m"

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal( const std::string );
		Animal( const Animal& );
		Animal& operator=( const Animal& );
		virtual ~Animal();

		std::string			getType( void ) const;
		virtual void		makeSound( void ) const;
};

#endif
