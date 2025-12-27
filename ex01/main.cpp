
#include "include/head.hpp"

int	main(void) {
	cout << "Welcome to [PhoneBook]" << std::endl;

	PhoneBook Contacts;

	
	while (true) {
		string	prompt;

		cin >> prompt;
		if (prompt.empty())
			continue;
		if (prompt == "ADD") {
			
		} else if (prompt == "SEARCH") {

		} else if (prompt == "EXIT") {

		} else {
			cout << "Invalid option! Try ADD, SEARCH or EXIT" << std::endl;
		}
	}
}