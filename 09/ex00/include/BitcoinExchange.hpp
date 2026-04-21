#pragma once

#include <iostream>


class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange&	operator=( const BitcoinExchange& );
		~BitcoinExchange();
}
