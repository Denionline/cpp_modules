
#include <iostream>
#include <fstream>
#include <string>

static int	replace(std::string fileName, std::string fromWord, std::string toWord) {
	std::ofstream	newFile;
	std::ifstream	file;
	std::string		line;

	if (fromWord == toWord) {
		std::cout << "The strings <to_replace> and <new_word> are equal '-'" << std::endl;
		return (1);
	}
	file.open(fileName.c_str());
	if (!file) {
		std::cout << "Error to open the file" << std::endl;
		return (1);
	}

	newFile.open((fileName + ".replace").c_str());
	while (std::getline(file, line)) {
		int	size = line.length();

		for (int i = 0; i < size; i++) {
			size_t	pos = line.find(fromWord, i);

			if (pos != std::string::npos) {
				line.erase(pos, fromWord.length());
				line.insert(pos, toWord);
			}
		}
		newFile << line << std::endl;
	}
	file.close();
	return (0);
}

int	main( int argc, char *argv[] ) {
	(--argc, ++argv);

	if (argc != 3) {
		std::cout << "Invalid number of arguments, try:" << std::endl;
		std::cout << "./replace <file_name> <to_replace> <new_word>";
		std::cout << std::endl;
		return (1);
	}
	return (
		replace(argv[0], argv[1], argv[2])
	);
}
