#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( void ) {
	{
		Animal*	j = new Dog();
		Animal*	i = new Cat();

		delete j;
		delete i;
	}
	{
		class Dog dog;

		dog.thinkSound();
		dog.thinkSound();
		dog.thinkSound();
		dog.showThoughts();
		dog.makeSound();
		dog.forgotSound();
		dog.showThoughts();
	}
	return (0);
}
