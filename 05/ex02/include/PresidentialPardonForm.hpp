#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;

	public:
		/* Orthodoxal */
		PresidentialPardonForm();
		PresidentialPardonForm( const std::string );
		PresidentialPardonForm( const PresidentialPardonForm& );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& );
		~PresidentialPardonForm();

		std::string	getTarget( void ) const;

		void		execute( Bureaucrat const& ) const;
};
