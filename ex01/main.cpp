#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
    std::getline(std::cin, command);

    while (command != "EXIT")
    {
        if (command == "ADD")
        {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

            while (true)
            {
                std::cout << "Enter your first name: ";
                std::getline(std::cin, firstName);
                if (!firstName.empty())
                    break;
                std::cout << "First name cannot be empty. Please try again." << std::endl;
            }

            while (true)
            {
                std::cout << "Enter your last name: ";
                std::getline(std::cin, lastName);
                if (!lastName.empty())
                    break;
                std::cout << "Last name cannot be empty. Please try again." << std::endl;
            }

            while (true)
            {
                std::cout << "Enter your nickname: ";
                std::getline(std::cin, nickName);
                if (!nickName.empty())
                    break;
                std::cout << "Nickname cannot be empty. Please try again." << std::endl;
            }

            while (true)
            {
                std::cout << "Enter your phone number: ";
                std::getline(std::cin, phoneNumber);
                if (!phoneNumber.empty())
                    break;
                std::cout << "Phone number cannot be empty. Please try again." << std::endl;
            }

            while (true)
            {
                std::cout << "Enter your darkest secret: ";
                std::getline(std::cin, darkestSecret);
                if (!darkestSecret.empty())
                    break;
                std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
            }

            Contact contact;
            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setNickName(nickName);
            contact.setPhoneNumber(phoneNumber);
            contact.setDarkestSecret(darkestSecret);
            phoneBook.addContact(contact);
        }
		else if (command == "SEARCH"){
			phoneBook.showContactsSearch();
			while (true)
			{
				std::cout << "Enter the index of the contact you want to see: ";
				int index;
				std::cin >> index;
				
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid index. Try again" << std::endl;
				}
				else
				{
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					phoneBook.showContact(index);
					break;
				}
			}
		}
        std::getline(std::cin, command);
    }
	phoneBook.~PhoneBook();
    return 0;
}
