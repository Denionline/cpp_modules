#include "include/Contact.hpp"

int	atoi(string s) {
	const int	size = s.size();
	int			result = 0;
	int			neg = (1);
	int			i = 0;

	if (s.empty()) return (-1);
	while (i < size && std::isspace(s[i])) i++;
	if (s[i] == '+' || s[i] == '-') {
		if (s[i] == '-') neg = (-1);
		i++;
	}
	for (; i < size && std::isdigit(s[i]); i++) {
		result = (result * 10) + (s[i] - '0');
	}
	if (!std::isdigit(s[i])) return (-1);
	return (result * neg);
}

string	trim(const string s) {
	const size_t	size = s.size();
	size_t			start;
	size_t			end = 0;

	for (start = 0; start < size && std::isspace(s[start]); start++);
	for (end = size; end > start && std::isspace(s[end - 1]); end--);
	return (s.substr(start, end - start));
}

static int	prompt(string label, string &result) {
	cout << label;
	if (!getline(cin, result))
		return (false);
	result = trim(result);
	if (result.empty()) {
		cout << "Please fill the field to continue..." << std::endl;
		return (prompt(label, result));
	}
	return (true);
}

bool	Contact::NewContact() {
	if (!prompt("First name: ", this->first_name)) return (false);
	if (!prompt("Last name: ", this->last_name)) return (false);
	if (!prompt("Nickname: ", this->nickname)) return (false);
	if (!prompt("Phone number: ", this->phone_number)) return (false);
	if (!prompt("Tell me a darkest secret ('-'): ", this->secret)) return (false);
	return (true);
}

static string	formatColumn(const string &str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::PrintContact(size_t idx) {
	cout << "|";
	cout << setw(3) << idx << "|";
	cout << setw(10) << formatColumn(this->first_name) << "|";
	cout << setw(10) << formatColumn(this->last_name) << "|";
	cout << setw(10) << formatColumn(this->nickname) << "|";
	cout << std::endl;
}

void	Contact::PrintContactDetailed() {
	cout << "First name: " << this->first_name << std::endl;
	cout << "Last name: " << this->last_name << std::endl;
	cout << "Nickname: " << this->nickname << std::endl;
	cout << "Phone number: " << this->phone_number << std::endl;
	cout << "Secret: " << this->secret << std::endl;
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