#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
	std::fstream file;

	file.open("text.txt",std::ios::out);

	std::cout << argc << std::endl;

	file << argv[1];

	file.close();

	return 0;
}
