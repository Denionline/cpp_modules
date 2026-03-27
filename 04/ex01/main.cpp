#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		const Animal* animal = new Animal();


		std::cout << dog->getType() << " " << std::endl;
		dog->makeSound();
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		std::cout << animal->getType() << " " << std::endl;
		animal->makeSound();

		delete dog;
		delete cat;
		delete animal;
	}

	{
		const WrongAnimal* animal = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout << animal->getType() << " " << std::endl;
		animal->makeSound();
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();

		delete animal;
		delete cat;
	}
	return (0);
}
