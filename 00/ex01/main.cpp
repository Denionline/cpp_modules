
#include "include/PhoneBook.hpp"

int	main(void) {
	std::cout << "Welcome to [PhoneBook]" << std::endl;
	
	PhoneBook Contacts;
	
	while (true) {
		std::string	prompt;

		std::cout << "Write an option (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, prompt))
			break;
		prompt = trim(prompt);
		if (prompt.empty())
			continue;
		if (prompt == "ADD") {
			if (!Contacts.AddContact()) return (1);
		} else if (prompt == "SEARCH") {
			if (!Contacts.SearchContact()) return (1);
		} else if (prompt == "EXIT") {
			break ;
		} else {
			std::cout << "Invalid option! Try ADD, SEARCH or EXIT" << std::endl;
		}
	}
}
