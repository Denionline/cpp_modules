#ifndef		DOG_H
# define	DOG_H

# include "Animal.hpp"

# pragma once

class Dog: public Animal {
	private:
		Brain*		brain;
	public:
		/* Orthodoxal */
		Dog();
		Dog( const std::string );
		Dog( const Dog& );
		Dog& operator=( const Dog& );
		~Dog();

		/* Mandatory functions */
		void	makeSound( void ) const;

		/* Extra functions */
		void	thinkSound( void );
		void	forgotSound( void );
		void	showThoughts( void );
};

#endif