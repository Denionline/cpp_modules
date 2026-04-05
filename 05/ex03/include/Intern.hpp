#pragma once

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& );
		Intern& operator=(const Intern& );
		~Intern();

		AForm*	makeForm( std::string , std::string );

		class FormNameNotFound: public std::exception {
			public:
				const char*	what() const throw() {
					return (BOLD RED "Form name not found" RESET);
				}
		};
};