#pragma once

# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string	_target;

	public:
		/* Orthodoxal */
		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string );
		ShrubberyCreationForm( const ShrubberyCreationForm& );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& );
		~ShrubberyCreationForm();

		std::string	getTarget( void ) const;

		void		execute( const Bureaucrat& ) const;
};
