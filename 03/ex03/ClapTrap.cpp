#include "ClapTrap.hpp"

/* Orthodox */
ClapTrap::ClapTrap(): _name("('-')"), _hit_points(10), _energy_points(10), _attack_damage(0) {
	print_struction("ClapTrap " + _name, "created", GREEN);
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	print_struction("ClapTrap " + _name, "created", GREEN);
}

ClapTrap::~ClapTrap() {
	print_struction("ClapTrap " + _name, "destroyed", RED);
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& copy ) {
	print_struction(copy._name, "assigned to " + _name, YELLOW);
	if (this != &copy) {
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	return (*this);
}

void	ClapTrap::print_struction(const std::string& name, const std::string& action, const char* color) {
	const std::string	msg = name + " was " + action;
	const int			width = msg.length() + 4;

	std::cout << color << BOLD;
	std::cout << "┌" << std::string(width, '-') << "┐\n";
	std::cout << "│  " << msg << "  │\n";
	std::cout << "└" << std::string(width, '-') << "┘\n";
	std::cout << RESET;
}

bool	ClapTrap::check_status(std::string name, int status, std::string action) {
	if (status <= 0) {
		std::cout << name << " failed to " << action << std::endl;
		return (false);
	}
	return (true);
}


static void print_bar(const std::string& label, unsigned int value, unsigned int max, const char* color) {
	const int barWidth = 20;
	int filled = (max > 0) ? (value * barWidth / max) : 0;

	std::cout << color << BOLD << std::left << label << RESET;
	std::cout << color << "[";
	for (int i = 0; i < barWidth; i++)
		std::cout << (i < filled ? "█" : "░");
	std::cout << "] ";
	std::cout << std::setw(3) << value << "| " << std::setw(3) << max;
	std::cout << RESET;
}

void	ClapTrap::print_status( std::string name , int h , int e , int a ) {
	std::cout << BOLD << std::endl;
	std::cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
	std::cout << "║ " << std::left << std::setw(18) << ("ClapTrap: " + name);
	print_bar(" HP", h, MAX_HP, GREEN);
	print_bar(" EP",  e, MAX_EP, CYAN);
	std::cout << BOLD << RED << std::left << " AD: " << std::setw(7) << a << RESET << "║";
	std::cout << "\n╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝\n" << RESET;

	std::cout << "\n";
}

void	ClapTrap::attack( const std::string& target ) {
	if (!check_status(_name, _hit_points, "attack") || !check_status(_name, _energy_points, "attack")) {
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (!check_status(_name, _hit_points, "take damage")) {
		return;
	}
	_hit_points = amount > _hit_points ? 0 : _hit_points - amount ;
	std::cout << _name << " took " << amount << " of damage." << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (!check_status(_name, _hit_points, "be repaired") || !check_status(_name, _energy_points, "be repaired")) {
		return;
	}
	_energy_points = amount > _energy_points ? 0 : _energy_points - amount ;
	_hit_points += amount;
	std::cout << _name << " was repaired " << amount << " points" << std::endl;
	print_status(_name, _hit_points, _energy_points, _attack_damage);
}
