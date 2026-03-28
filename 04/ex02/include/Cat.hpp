#ifndef		CAT_H
# define	CAT_H

# include "Animal.hpp"

# pragma once

class Cat: public Animal {
	private:
		Brain*		brain;
	public:
		/* Orthodoxal */
		Cat();
		Cat( const std::string );
		Cat( const Cat& );
		Cat& operator=( const Cat& );
		~Cat();

		/* Mandatory functions */
		void	makeSound( void ) const;

		/* Extra functions */
		void	thinkSound( void );
		void	forgotSound( void );
		void	showThoughts( void );
};

#endif