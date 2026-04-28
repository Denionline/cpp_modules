#pragma once

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
/* Containers */
#include <queue>
#include <list>

class PmergeMe {
	private:
		std::queue<int>	_data_queue;
		std::list<int>	_data_list;
	public:
		PmergeMe();
		PmergeMe( char *[] , size_t );
		PmergeMe( const PmergeMe& );
		PmergeMe&	operator=( const PmergeMe& );
		~PmergeMe();

		void	FJASqueue( void );
		void	FJASlist( void );

		std::list<int>	getData( void );

		class ExceptionError: public std::exception {
			public:
				const char* what() const throw() {
					return ("Error");
				}
		};
};

std::ostream&	operator<<( std::ostream& o , PmergeMe data );
