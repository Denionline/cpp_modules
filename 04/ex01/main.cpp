#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( void ) {
	const unsigned int	number_of_animals = 4;
	Animal*				animals[number_of_animals];

	if (number_of_animals % 2) return (1);

	for (unsigned int i = 0; i < number_of_animals; i++) {
		if (i % 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (unsigned int i = 0; i < number_of_animals; i++) animals[i]->makeSound();

	for (unsigned int i = 0; i < number_of_animals; i++) delete animals[i];

	return (0);
}
