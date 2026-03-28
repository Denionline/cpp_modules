#ifndef		CAT_H
# define	CAT_H

# include "Animal.hpp"

# pragma once

class Cat: public Animal {
	private:
		Brain*		brain;
	public:
		Cat();
		Cat( const std::string );
		Cat( const Cat& );
		Cat& operator=( const Cat& );
		~Cat();

		void	makeSound( void ) const;
};

#endif