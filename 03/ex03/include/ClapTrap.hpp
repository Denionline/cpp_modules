#ifndef		CLAPTRAP_H
# define	CLAPTRAP_H

#include <iostream>
#include <string>
#include <iomanip>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BG_DARK "\033[48;5;235m"

# define MAX_HP 100
# define MAX_EP 100

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap();
		ClapTrap( std::string );
		~ClapTrap();
		ClapTrap&	operator=( const ClapTrap& );

		void	attack( const std::string& );
		void	takeDamage( unsigned int );
		void	beRepaired( unsigned int );

		void	print_status( std::string , int , int , int );
		bool	check_status( std::string , int , std::string );
		void	print_struction( const std::string& , const std::string& , const char* );
};

#endif