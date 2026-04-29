#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _data(parseDataFile("data.csv"))
{}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) {
	*this = copy;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& copy ) {
	if (this != &copy) {
		this->_data = copy._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

static bool	isAllDigit( std::string s ) {
	for (size_t i = 0; i < s.length(); i++ ) {
		if (!std::isdigit(s.at(i)))
			return (false);
		}
	return (true);
}

std::vector<Data>	BitcoinExchange::parseDataFile( std::string fileName ) {
	std::vector<Data>	array;
	std::fstream			file(fileName.c_str());
	char							del = fileName.find("data.csv") != std::string::npos ? ',' : '|';

	try {
		if (fileName.empty() || !file.is_open())
			throw ExceptionError("could not open file.");
		std::string	line;
		std::getline(file, line);
		while (std::getline(file, line)) {
			if (line.empty()) continue;
			std::stringstream	sline(line);
			std::string				cell;
			Data							data = {};

			for (int times = 0; std::getline(sline, cell, del); times++) {
				if (cell.empty()) continue;
				if (times == 0) {
					if (del == ',')
						data.date = convertDate(cell);
					data.sdate = cell;
				} else if (times == 1) {
					data.rate = std::atof(cell.c_str());
					data.srate = cell;
				} else {
					break;
				}
			}
			array.push_back(data);
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (array);
}

static bool	isValidDate( std::tm t ) {
	if (t.tm_mon < 0 || t.tm_mon > 11)
		return (false);
	if (t.tm_mday < 0 || t.tm_mday > 31)
		return (false);
	if (t.tm_mon == 1 && t.tm_mday > 29)
		return (false);
	if (std::mktime(&t) == -1)
		return (false);
	return (true);
}

std::tm	BitcoinExchange::convertDate( std::string s ) {
	if (s.length() < 10)
		throw ExceptionError("bad input => " + s);
	const std::string	y = s.substr(0,4), m = s.substr(5,2), d = s.substr(8,2);

	if (!(y.length() == 4 && m.length() == 2 && d.length() == 2))
		throw ExceptionError("bad input => " + s);
	if (!(isAllDigit(y) && isAllDigit(m) && isAllDigit(d)))
		throw ExceptionError("bad input => " + s);

	std::tm	t = {};
	t.tm_year = std::atoi(y.c_str()) - 1900;
	t.tm_mon  = std::atoi(m.c_str()) - 1;
	t.tm_mday = std::atoi(d.c_str());

	if (!isValidDate(t))
		throw ExceptionError("bad input => " + s);

	return (t);
}

static float	getClosestCurrency( std::vector<Data> db , std::string sdate ) {
	std::vector<Data>::iterator	it = db.begin(), ite = db.end();
	Data												result;

	std::tm	date = BitcoinExchange::convertDate(sdate);

	result = (*it);
	while (it != ite) {
		Data	t = (*it);
		if (std::mktime(&t.date) > std::mktime(&result.date) && std::mktime(&t.date) <= std::mktime(&date)) {
			result = t;
		}
		it++;
	}
	return (result.rate);
}

void	BitcoinExchange::executeExchange( std::vector<Data> source ) {
	std::vector<Data>::iterator	it = source.begin(), ite = source.end();

	while (it != ite) {
		Data	d = (*it);

		try {
			d.rate = std::atof(d.srate.c_str());
			if (d.rate < 0)
				throw ExceptionError("not a positive number.");
			if (d.rate > 1000)
				throw ExceptionError("too large a number.");
			float	nConvert = d.rate * getClosestCurrency(_data, d.sdate);
			std::cout << d.sdate << " => " << d.rate << " = " << nConvert << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		it++;
	}
}
