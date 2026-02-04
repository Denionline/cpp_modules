
#include "include/PhoneBook.hpp"

int	main(void) {
	cout << "Welcome to [PhoneBook]" << std::endl;
	
	PhoneBook Contacts;
	
	while (true) {
		string	prompt;

		cout << "Write an option (ADD, SEARCH, EXIT): ";
		if (!getline(cin, prompt))
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
			cout << "Invalid option! Try ADD, SEARCH or EXIT" << std::endl;
		}
	}
}
