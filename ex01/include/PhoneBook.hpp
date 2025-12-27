
#include "head.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void	AddContact();
	private:
		Contact*			contacts[8];
		unsigned int	length;
};
