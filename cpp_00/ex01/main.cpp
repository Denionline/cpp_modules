
#include "include/PhoneBook.hpp"

int	main(void) {
	cout << "Welcome to [PhoneBook]" << std::endl;
	
	PhoneBook Contacts;
	
	while (true) {
		string	prompt;

		cout << "Write an option (ADD, SEARCH, EXIT): ";
		getline(cin, prompt);
		if (prompt.empty())
			continue;
		if (prompt == "ADD") {
			Contacts.AddContact();
		} else if (prompt == "SEARCH") {
			Contacts.SearchContact();
		} else if (prompt == "EXIT") {
			break ;
		} else {
			cout << "Invalid option! Try ADD, SEARCH or EXIT" << std::endl;
		}
	}
}