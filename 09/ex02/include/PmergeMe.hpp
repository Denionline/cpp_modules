#pragma once

#include <iostream>
#include <cstdlib>
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
		~PmergeMe();

		void	FJASqueue( void );
		void	FJASlist( void );

		void	printQueue( void );
		void	printList( void );
	};

