#include "PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>

int main(void) {
  PhoneBook phoneBook;
  int index;
  std::string command;
  std::string input;

  std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
  std::getline(std::cin, command);
  while (!std::cin.eof() && command != "EXIT") {
    if (command == "ADD") {
      std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
      while (!std::cin.eof() && true) {
        std::cout << "Enter your first name: ";
        std::getline(std::cin, firstName);
        if (std::cin.eof())
          break;
        if (!firstName.empty())
          break;
        std::cout << "First name cannot be empty. Please try again."
                  << std::endl;
      }
      while (!std::cin.eof() && true) {
        std::cout << "Enter your last name: ";
        std::getline(std::cin, lastName);
        if (!lastName.empty())
          break;
        std::cout << "Last name cannot be empty. Please try again."
                  << std::endl;
      }
      while (!std::cin.eof() && true) {
        std::cout << "Enter your nickname: ";
        std::getline(std::cin, nickName);
        if (std::cin.eof())
          break;
        if (!nickName.empty())
          break;
        std::cout << "Nickname cannot be empty. Please try again." << std::endl;
      }
      while (!std::cin.eof() && true) {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phoneNumber);
        if (std::cin.eof())
          break;
        if (!phoneNumber.empty())
          break;
        std::cout << "Phone number cannot be empty. Please try again."
                  << std::endl;
      }
      while (!std::cin.eof() && true) {
        std::cout << "Enter your darkest secret: ";
        std::getline(std::cin, darkestSecret);
        if (std::cin.eof())
          break;
        if (!darkestSecret.empty())
          break;
        std::cout << "Darkest secret cannot be empty. Please try again."
                  << std::endl;
      }
      if (std::cin.eof()) {
        std::cout << std::endl;
        break;
      }
      Contact contact(firstName, lastName, nickName, phoneNumber,
                      darkestSecret);
      phoneBook.addContact(contact);
    } else if (command == "SEARCH") {
      phoneBook.showContactsInSearch();
      std::cout << "Enter the index of the contact you want to see: ";
      std::getline(std::cin, input);
      if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
        index = input[0] - '0';
        phoneBook.showOneContact(index);
      } else
        std::cout << "Invalid index." << std::endl;
    }
    std::getline(std::cin, command);
  }
  return (0);
}
