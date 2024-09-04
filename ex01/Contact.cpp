#include "Contact.hpp"

int Contact::totalContacts = 0;
Contact::Contact()
    : firstName(""), lastName(""), nickName(""), phoneNumber(""),
      darkestSecret(""), contactIndex(totalContacts) {
		contactIndex = totalContacts;
		totalContacts++;}

Contact::Contact(const std::string &str1, const std::string &str2,
                 const std::string &str3, const std::string &str4,
                 const std::string &str5)
    : firstName(str1), lastName(str2), nickName(str3), phoneNumber(str4),
      darkestSecret(str5), contactIndex(totalContacts) {totalContacts++;}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return (firstName); }
std::string Contact::getLastName() const { return (lastName); }
std::string Contact::getNickName() const { return (nickName); }
std::string Contact::getPhoneNumber() const { return (phoneNumber); }
std::string Contact::getDarkestSecret() const { return (darkestSecret); }
int Contact::getContactIndex() const { return (contactIndex); }
