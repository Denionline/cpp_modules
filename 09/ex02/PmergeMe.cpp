#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _data_queue(), _data_list()
{}

PmergeMe::PmergeMe( char *args[] , size_t len ) {
	for (size_t i = 0; i < len; i++) {
		int	n = std::atoi(args[i]);

		if (n < 0) throw ExceptionError();
		_data_queue.push(n);
		_data_list.push_back(n);
	}
}

PmergeMe::PmergeMe( const PmergeMe& copy ) {
	*this = copy;
}

PmergeMe&	PmergeMe::operator=( const PmergeMe& copy ) {
	if (this != &copy) {
		this->_data_list = copy._data_list;
		this->_data_queue = copy._data_queue;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

/* Queue Sorting */

static void sortedInsertQueue(std::queue<int>& q, int value) {
	std::queue<int>	temp;
	bool inserted = false;

	while (!q.empty()) {
			if (!inserted && value < q.front()) {
					temp.push(value);
					inserted = true;
			}
			temp.push(q.front());
			q.pop();
	}

	if (!inserted)
			temp.push(value);

	while (!temp.empty()) {
			q.push(temp.front());
			temp.pop();
	}
}

static std::queue<int> getSortedQueue( std::queue<int> input ) {
	if (input.size() <= 1)
			return input;

	std::queue<int> small, large;
	while (!input.empty()) {
			int a = input.front(); input.pop();

			if (input.empty()) {
					small.push(a);
					break;
			}

			int b = input.front(); input.pop();

			small.push(a < b ? a : b);
			large.push(a > b ? a : b);
	}

	std::queue<int> mainChain = getSortedQueue(large);

	while (!small.empty()) {
			int val = small.front();
			small.pop();

			sortedInsertQueue(mainChain, val);
	}

	return (mainChain);
}

void	PmergeMe::FJASqueue( void ) {
	_data_queue = getSortedQueue(_data_queue);
}

/* List Sorting */

static void sortedInsertList(std::list<int>& l, int value) {
	std::list<int>::iterator it = l.begin(), ite = l.end();

	while (it != ite && *it < value)
			++it;
	l.insert(it, value);
}

static std::list<int> getSortedList( std::list<int> input ) {
	if (input.size() <= 1)
			return input;

	std::list<int>::iterator	it = input.begin(), ite = input.end();
	std::list<int>						small, large;
	while (it != ite) {
		int	a = *it++;
		if (it == ite) {
				small.push_back(a);
				break;
		}

		int	b = *it++;

		small.push_back(a < b ? a : b);
		large.push_back(a > b ? a : b);
	}

	std::list<int> mainChain = getSortedList(large);
	for (std::list<int>::iterator cit = small.begin(); cit != small.end(); ++cit)
			sortedInsertList(mainChain, *cit);
	return (mainChain);
}

void	PmergeMe::FJASlist( void ) {
	_data_list = getSortedList(_data_list);
}

std::list<int>	PmergeMe::getData( void ) {
	return (_data_list);
}

std::ostream&	operator<<( std::ostream& o , PmergeMe data ) {
	std::list<int>						c(data.getData());
	std::list<int>::iterator	it = c.begin(), ite = c.end();

	for (int i = 0; it != ite; i++) {
		if (i >= 4) {
			o << "[...]";
			break;
		}
		o  << *(it++) << (it != ite ? " " : "");
	}
	return (o);
}