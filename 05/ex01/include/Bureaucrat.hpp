
#ifndef	BUREAUCRAT_H
# define	BUREAUCRAT_H

# include <iostream>
# include <exception>

# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BG_DARK "\033[48;5;235m"

enum eLIMITS {
	maxGrade = 1,
	minGrade = 150
};

class Bureaucrat {
	private:
		const std::string	_name;
		size_t				_grade;
	public:
		/* Orthodoxal */
		Bureaucrat();
		Bureaucrat( const std::string );
		Bureaucrat( const size_t );
		Bureaucrat( const std::string , const size_t );
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
					return ( BOLD RED "Grade Too High" RESET);
				}
		};
		class GradeTooLowException: public std::exception {
			public:
				const char*	what() const throw() {
					return ( BOLD RED "Grade Too Low" RESET);
				}
		};
};

std::ostream&	operator<<( std::ostream& , Bureaucrat& );

#endif