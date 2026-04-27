#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _data_queue(), _data_list()
{}

PmergeMe::PmergeMe( char *args[] , size_t len ) {
	for (size_t i = 0; i < len; i++) {
		size_t	n = std::atoi(args[i]);

		_data_queue.push(n);
		_data_list.push_front(n);
	}
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

	while (!temp.empty())
	{
			q.push(temp.front());
			temp.pop();
	}
}

static std::queue<int> getSortedQueue( std::queue<int> input ) {
	if (input.size() <= 1)
			return input;

	std::queue<int> small;
	std::queue<int> large;

	while (!input.empty()) {
			int a = input.front(); input.pop();

			if (input.empty()) {
					small.push(a);
					break;
			}

			int b = input.front(); input.pop();

			if (a < b) {
					small.push(a);
					large.push(b);
			}
			else {
					small.push(b);
					large.push(a);
			}
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

void	PmergeMe::printQueue( void ) {
	std::queue<int>	c(_data_queue);

	std::cout << "Container {";
	while (!c.empty()) {
		std::cout << c.front() << (c.size() > 1 ? ", " : "");
		c.pop();
	}
	std::cout << "}" << std::endl;
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

	std::list<int> small, large;
	std::list<int>::iterator it = input.begin(), ite = input.end();
	while (it != ite) {
		int	a = *it++;
		int	b = *it++;

		if (it == ite) {
				small.push_back(a);
				break;
		}

		small.push_back(a < b ? a : b);
		large.push_back(a > b ? a : b);
	}

	std::list<int> mainChain = getSortedList(large);

	for (std::list<int>::iterator sit = small.begin(); sit != small.end(); ++sit)
			sortedInsertList(mainChain, *sit);

	return (mainChain);
}

void	PmergeMe::printList( void ) {
	std::list<int>	c(_data_list);
	std::list<int>::iterator it = c.begin(), ite = c.end();

	std::cout << "Container {";
	while (it != ite) {
		std::cout << *(ite++) << (it != ite ? ", " : "");
	}
	std::cout << "}" << std::endl;
}

void	PmergeMe::FJASlist( void ) {
	_data_list = getSortedList(_data_list);
}