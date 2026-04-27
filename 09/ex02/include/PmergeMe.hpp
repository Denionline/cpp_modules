#pragma once

#include <iostream>
#include <cstdlib>
/* Containers */
#include <queue>
#include <list>
#include <vector>

class PmergeMe {
	private:
		std::queue<size_t>	_data_queue;
		std::list<size_t>	_data_list;
	public:
		PmergeMe();
		PmergeMe( char *[] , size_t );
		~PmergeMe();

		void	print( void );

		std::queue<size_t>	getQueue( void );
		std::list<size_t>	getList( void );
};

std::vector<size_t>	FJASort( std::vector<size_t> );
std::vector<size_t> buildInsertionOrder( size_t );
void binaryInsert( std::vector<int>& , size_t );