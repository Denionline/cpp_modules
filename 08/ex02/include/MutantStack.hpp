#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::iterator	reverse_iterator;

		typedef typename std::stack<T>::container_type::iterator	const_iterator;
		typedef typename std::stack<T>::container_type::iterator	const_reverse_iterator;

		/* Orthodoxal */
		MutantStack() {};
		MutantStack( const MutantStack& copy ) {
			*this = copy;
		}
		MutantStack&	operator=( const MutantStack& copy ) {
			if (this != &copy) {
				std::stack<T>::operator=(copy);
			}
			return (*this);
		}
		~MutantStack() {};

		/* Member Functions */
		iterator	begin( void ) {
			return (this->c.begin());
		}
		iterator	end( void ) {
			return (this->c.end());
		}

		iterator	rbegin( void ) {
			return (this->c.begin());
		}
		iterator	rend( void ) {
			return (this->c.end());
		}

		/* Const Member Functions */
		const_iterator	begin( void ) const {
			return (this->c.begin());
		}
		const_iterator	end( void ) const {
			return (this->c.end());
		}

		const_reverse_iterator	rbegin( void ) const {
			return (this->c.begin());
		}
		const_reverse_iterator	rend( void ) const {
			return (this->c.end());
		}

};