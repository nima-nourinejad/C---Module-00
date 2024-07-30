#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string &input) { firstName = input; }

void Contact::setLastName(const std::string &input) { lastName = input; }

void Contact::setNickName(const std::string &input) { nickName = input; }

void Contact::setPhoneNumber(const std::string &input) { phoneNumber = input; }

void Contact::setDarkestSecret(const std::string &input) {
  darkestSecret = input;
}

std::string Contact::getFirstName() const { return (firstName); }

std::string Contact::getLastName() const { return (lastName); }

std::string Contact::getNickName() const { return (nickName); }

std::string Contact::getPhoneNumber() const { return (phoneNumber); }

std::string Contact::getDarkestSecret() const { return (darkestSecret); }
