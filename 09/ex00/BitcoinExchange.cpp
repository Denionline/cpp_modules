#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _data(parseDataFile("data.csv"))
{}

// BitcoinExchange::BitcoinExchange( const BitcoinExchange& ) {}

// BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& ) {}

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
	char							del = ',';
	size_t						rate_limit = 100000;

	if (fileName.find(".csv")) {
		del = '|';
		rate_limit = 1000;
	}

	try {
		if (!file.is_open())
			throw FileNotFound();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << ": " << fileName << std::endl;
	}

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream	sline(line);
		std::string				cell;
		Data							data = {};

		for (int times = 0; std::getline(sline, cell, del); times++) {
			if (cell.empty()) continue;
			if (times == 0) {
				data.date =	convertDate(cell);
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
	return (array);
}

std::tm	BitcoinExchange::convertDate( std::string s ) {
	const std::string	y = s.substr(0,4);
	const std::string	m = s.substr(5,2);
	const std::string d = s.substr(8,2);

	if (!(y.length() == 4 && m.length() == 2 && d.length() == 2))
		throw InvalidDate();
	if (!(isAllDigit(y) && isAllDigit(m) && isAllDigit(d)))
		throw InvalidDate();

	std::tm	t = {};
	t.tm_year = std::atoi(y.c_str()) - 1900;
	t.tm_mon  = std::atoi(m.c_str()) - 1;
	t.tm_mday = std::atoi(d.c_str());

	if (std::mktime(&t) == -1)
		throw InvalidDate();
	return (t);
}

void	BitcoinExchange::print( std::vector<Data> data ) {
	std::vector<Data>::iterator	it = data.begin();
	std::vector<Data>::iterator	ite = data.end();
	for (int i = 0; it != ite; i++) {
		std::cout
		<< (i < 10 ? "0" : "") << i
		<< std::setw(5) << " "
		<< (*it).sdate
		<< ((*it).srate.empty() ? "" : " - ")
		<< (*it).srate
		<< std::endl;
		it++;
	}
}