#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>

struct Data {
	std::tm			date;
	std::string		sdate;
	float				rate;
	std::string		srate;
};

class BitcoinExchange {
	private:
		std::vector<Data>	_data;
	public:
		/* Orthodoxal */
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange&	operator=( const BitcoinExchange& );
		~BitcoinExchange();

		static std::tm						convertDate( std::string );
		static std::vector<Data>	parseDataFile( std::string );

		void											executeExchange( std::vector<Data> );

	class ExceptionError: public std::exception {
		private:
			std::string	_msg;
		public:
			ExceptionError( std::string msg ): _msg("Error: " + msg)
			{}
			virtual ~ExceptionError() throw() {}
			virtual const char*	what() const throw() {
				return _msg.c_str();
			}
	};
};
