#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _data_queue(), _data_list()
{}

PmergeMe::PmergeMe( char *args[] , size_t len ) {
	for (size_t i = 0; i < len; i++) {
		size_t	n = std::atoi(args[i]);

		_data_queue.push(n);
		_data_list.push_back(n);
	}
}

PmergeMe::~PmergeMe()
{}



void	PmergeMe::print( void ) {
	std::queue<size_t>	n(_data_queue);

	while (!n.empty()) {
		std::cout << n.front() << std::endl;
		n.pop();
	}
}

std::queue<size_t>	PmergeMe::getQueue( void ) {
	return (_data_queue);
}

std::list<size_t>	PmergeMe::getList( void ) {
	return (_data_list);
}

/* Sorting Functions */

void binaryInsert(std::vector<size_t>& arr, size_t value) {
    std::vector<size_t>::iterator pos =
        std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}

std::vector<size_t> buildInsertionOrder(size_t n) {
    std::vector<size_t> order;
    std::vector<bool> used(n, false);

    size_t step = 1;
    while ((size_t)order.size() < n)
    {
        for (size_t i = step - 1; i < n; i += step * 2)
        {
            if (!used[i])
            {
                order.push_back(i);
                used[i] = true;
            }
        }
        step *= 2;
    }
    return order;
}

std::vector<size_t>	FJASort( std::vector<size_t> data ) {
	size_t	size = data.size();

	if (size < 2)
		return (data);

	std::vector< std::pair<size_t, size_t> >	pairs;
	for (size_t i = 0; i < size; i += 2) {
		pairs.push_back(std::make_pair(data[i], data[i + (i + 1 < size)]));
	}
	
	std::vector<size_t>	small;
	std::vector<size_t>	large;

	for (size_t i = 0; i < pairs.size(); i++) {
		size_t a = pairs[i].first, b = pairs[i].second;

		small.push_back(a < b ? a : b);
		large.push_back(a > b ? a : b);
	}

	std::vector<size_t> mainChain = FJASort(large);

    std::vector<size_t> order = buildInsertionOrder(small.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx < (size_t)small.size())
            binaryInsert(mainChain, small[idx]);
    }

    return mainChain;
}