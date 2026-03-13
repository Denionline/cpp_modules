#include "Zombie.hpp"

int main(int argc, char *argv[]){

	if (argc == 1) randomChump("Foo");

	for (int i = 1; i < argc; i++){
		randomChump(argv[i]);
	}
}
