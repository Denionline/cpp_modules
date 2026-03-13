#include "include/Contact.hpp"

bool	isNumber(std::string str) {
	const int	size = str.length();

	for (int i = 0; i < size; i++) {
		if (!std::isdigit(str[i])) return (false);
	}
	return (true);
}

std::string	trim(const std::string s) {
	const size_t	size = s.size();
	size_t			start;
	size_t			end = 0;

	for (start = 0; start < size && std::isspace(s[start]); start++);
	for (end = size; end > start && std::isspace(s[end - 1]); end--);
	return (s.substr(start, end - start));
}

static int	prompt(std::string label, std::string &result, bool number) {
	std::cout << label;
	if (!getline(std::cin, result))
		return (false);
	result = trim(result);
	if (number && !isNumber(result)) {
		std::cout << "Only numbers allowed!" << std::endl;
		return (prompt(label, result, number));
	}
	if (result.empty()) {
		std::cout << "Please fill the field to continue..." << std::endl;
		return (prompt(label, result, number));
	}
	return (true);
}

bool	Contact::NewContact() {
	if (!prompt("First name: ", this->first_name, false)) return (false);
	if (!prompt("Last name: ", this->last_name, false)) return (false);
	if (!prompt("Nickname: ", this->nickname, false)) return (false);
	if (!prompt("Phone number: ", this->phone_number, true)) return (false);
	if (!prompt("Tell me a darkest secret ('-'): ", this->secret, false)) return (false);
	return (true);
}

static std::string	formatColumn(const std::string &str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::PrintContact(size_t idx) {
	std::cout << "|";
	std::cout << std::setw(3) << idx << "|";
	std::cout << std::setw(10) << formatColumn(this->first_name) << "|";
	std::cout << std::setw(10) << formatColumn(this->last_name) << "|";
	std::cout << std::setw(10) << formatColumn(this->nickname) << "|";
	std::cout << std::endl;
}

void	Contact::PrintContactDetailed() {
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Secret: " << this->secret << std::endl;
}

bool	Contact::is_valid() {
	if (this->first_name.empty())
		return (false);
	if (this->last_name.empty())
		return (false);
	if (this->nickname.empty())
		return (false);
	if (this->phone_number.empty())
		return (false);
	if (this->secret.empty())
		return (false);
	return (true);
}

Contact::Contact() {
}

Contact::~Contact(){

}