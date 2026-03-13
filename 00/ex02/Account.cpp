
#include "Account.hpp"

#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	// Locally
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	// Globally
	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	// Print
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account() {
	// Print
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int		Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	// Print
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	// Print
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << (_amount += deposit) << ";";
	std::cout << "nb_deposits:" << (_nbDeposits += 1) << std::endl;
	
	// Globally
	(_totalNbDeposits += 1, _totalAmount += deposit);
}
bool	Account::makeWithdrawal( int withdrawal ) {
	// Print
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";

	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}

	std::cout << withdrawal << ";";
	std::cout << "amount:" << (_amount -= withdrawal) << ";";
	std::cout << "nb_withdrawals:" << (_nbWithdrawals += 1) << std::endl;
	
	// Globally
	(_totalNbWithdrawals += 1, _totalAmount -= withdrawal);
	return (true);
}

int		Account::checkAmount() const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	// Print
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	*date = localtime(&now);

	// Print
	std::cout << "[";
	std::cout << std::setfill('0') << std::setw(4) << (date->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (date->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << (date->tm_mday);
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << (date->tm_hour);
	std::cout << std::setfill('0') << std::setw(2) << (date->tm_min);
	std::cout << std::setfill('0') << std::setw(2) << (date->tm_sec);
	std::cout << "] ";
}
