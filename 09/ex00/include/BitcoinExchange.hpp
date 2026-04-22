#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>

struct Data {
	std::tm			date;
	float				rate;
};

class BitcoinExchange {
	private:
		std::vector<Data>	data;
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange&	operator=( const BitcoinExchange& );
		~BitcoinExchange();


	class FileNotFound: public std::exception {
		public:
			const char*	what() const throw() {
				return ("Error to open the file");
			}
	};
	class CSVInvalidDate: public std::exception {
		public:
			const char*	what() const throw() {
				return ("There is an invalid date in CSV file");
			}
	};
	class CSVInvalidRate: public std::exception {
		public:
			const char*	what() const throw() {
				return ("There is an invalid rate in CSV file");
			}
	};
	class CSVInvalidArgument: public std::exception {
		public:
			const char*	what() const throw() {
				return ("There is an invalid argument in CSV file");
			}
	};
};
