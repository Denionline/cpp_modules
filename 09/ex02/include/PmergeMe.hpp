#pragma once

#include <iostream>
#include <cstdlib>
/* Containers */
#include <queue>
#include <list>

class PmergeMe {
	private:
		std::queue<size_t>	_data;
	public:
		PmergeMe();
		PmergeMe( char *[] , size_t );
		~PmergeMe();

		void	print( void );
};