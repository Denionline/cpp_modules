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

		void											executeExchange( std::vector<Data> );

	class InvalidDate: public std::exception {
		private:
			std::string	_msg;
		public:
			InvalidDate( std::string date ): _msg("Error: bad input => " + date)
			{}
			virtual ~InvalidDate() throw() {}
			virtual const char*	what() const throw() {
				return _msg.c_str();
			}
	};
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
