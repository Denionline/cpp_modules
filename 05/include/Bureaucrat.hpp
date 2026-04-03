
#ifndef	BUREAUCRAT_H
# define	BUREAUCRAT_H

# include <iostream>
# include <exception>

class Bureaucrat {
	private:
		const std::string	_name;
		size_t				_grade;
	public:
		/* Orthodoxal */
		Bureaucrat();
		Bureaucrat( const std::string );
		Bureaucrat( const Bureaucrat& );
		Bureaucrat&	operator=( const Bureaucrat& );
		~Bureaucrat();

		std::string	getName( void );

		size_t		getGrade( void );
		void		increaseGrade( void );
		void		decreaseGrade( void );

		class GradeTooHighException: public std::exception {
			public:
				const char*	what() const throw() {

				}
		}
};

#endif