#include <iostream>
#include <string>

int main(int argc, char **argv) {
	int nbContacts;
	if (argc < 2)
		nbContacts = 10;
	else
		nbContacts = std::stoi(argv[1]);
	for (int i = 1; i <= nbContacts; i++)
	{
		std::cout << "ADD" << std::endl;
		std::cout << "Contact " << i << std::endl;
		std::cout << "Contact " << i << std::endl;
		std::cout << "Contact " << i << std::endl;
		std::cout << i << std::endl;
		std::cout << "Contact " << i << std::endl;
	}
	std::cout << "SEARCH" << std::endl;
	return (0);
}