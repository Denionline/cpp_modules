#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( int argc , char *argv[] ) {
	(--argc, ++argv);
	if (argc != 1) return (1);

	const unsigned int	number_of_animals = (unsigned int)strtol(*argv, NULL, 10);
	Animal*				animals[number_of_animals];

	if (number_of_animals % 2) return (1);

	for (unsigned int i = 0; i < number_of_animals; i++) {
		if (i % 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (unsigned int i = 0; i < number_of_animals; i++) {
		animals[i]->makeSound();
		animals[i]->thinkSound();
		animals[i]->thinkSound();
		animals[i]->thinkSound();
		animals[i]->showThoughts();
	};

	for (unsigned int i = 0; i < number_of_animals; i++) delete animals[i];

	return (0);
}
