#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main(void) {
  PhoneBook phoneBook;
  std::string command;

  std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
  while (!std::cin.eof())
  {
	std::getline(std::cin, command);
    if (command == "ADD")
	 	phoneBook.add();
    else if (command == "SEARCH")
		phoneBook.search();
	else if (command == "EXIT")
		break;
  }
  if (std::cin.eof())
	std::cin.clear();
  return (0);
}
