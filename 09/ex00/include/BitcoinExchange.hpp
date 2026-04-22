#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>
#include <iomanip>

struct Data {
	std::tm			date;
	std::string			sdate;
	float				rate;
	std::string			srate;
};

class BitcoinExchange {
	private:
		std::vector<Data>	_data;
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange&	operator=( const BitcoinExchange& );
		~BitcoinExchange();

		static std::tm						convertDate( std::string );
		static std::vector<Data>	parseDataFile( std::string );

		static void								print( std::vector<Data> );


	class FileNotFound: public std::exception {
		public:
			const char*	what() const throw() {
				return ("Error to open the file");
			}
	};
	class InvalidDate: public std::exception {
		public:
			const char*	what() const throw() {
				return ("There is an invalid date in file");
			}
	};
	class InvalidRate: public std::exception {
		public:
			const char*	what() const throw() {
				return ("There is an invalid rate in file");
			}
	};
	class InvalidArgument: public std::exception {
		public:
			const char*	what() const throw() {
				return ("There is an invalid argument in file");
			}
	};
};
