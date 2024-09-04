#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main(void) {
  PhoneBook phoneBook;
  std::string command;
  while (!std::cin.eof())
  {
	if (std::cin.eof())
		break;
	else
		std::cout << "Enter ADD, SEARCH or EXIT: ";
	std::getline(std::cin, command);
    if (command == "ADD")
	 	phoneBook.add();
    else if (command == "SEARCH")
		phoneBook.search();
	else if (command == "EXIT")
		break;
  }
  if (std::cin.eof())
  {
	std::cout << std::endl;
	std::cout << "End of input detected (EOF). Exiting the program." << std::endl;
	std::cin.clear();
  }
  return (0);
}
