#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
public:
  Contact();
  Contact(const std::string &str1, const std::string &str2,
          const std::string &str3, const std::string &str4,
          const std::string &str5);
  ~Contact();
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickName() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;
  int getContactIndex() const;

private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
  static int totalContacts;
  int 		contactIndex;
};

#endif // CONTACT_HPP
