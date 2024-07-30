#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  ~Contact();

  void setFirstName(const std::string &input);
  void setLastName(const std::string &input);
  void setNickName(const std::string &input);
  void setPhoneNumber(const std::string &input);
  void setDarkestSecret(const std::string &input);

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickName() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;

private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif // CONTACT_HPP
