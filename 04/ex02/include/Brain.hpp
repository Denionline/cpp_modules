#ifndef		BRAIN_H
# define	BRAIN_H

#include "Head.h"

class Brain {
	private:
		std::string	ideas[MAX_IDEAS];
	public:
		/* Orthodoxal */
		Brain();
		Brain( std::string* );
		Brain( const Brain& );
		Brain& operator=( const Brain& );
		~Brain();

		/* Extra functions */
		void	newIdea( std::string );
		void	forgotIdea( void );
		void	showIdeas( void );
};

#endif