#include "Account.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


std::string getTime() {
  time_t currentTimestamp;
  currentTimestamp = time(NULL);

  tm *localTime;
  localTime = localtime(&currentTimestamp);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  int hour = localTime->tm_hour;
  int min = localTime->tm_min;
  int sec = localTime->tm_sec;

  std::stringstream stringStream;
  stringStream << year;
  if (month < 10)
    stringStream << "0";
  stringStream << month;
  if (day < 10)
    stringStream << "0";
  stringStream << day;
  stringStream << "_";
  if (hour < 10)
    stringStream << "0";
  stringStream << hour;
  if (min < 10)
    stringStream << "0";
  stringStream << min;
  if (sec < 10)
    stringStream << "0";
  stringStream << sec;

  return stringStream.str();
}

void _displayTimestamp(void) { std::cout << getTime() << std::endl; }

std::string logFileNameCreator(void) {
  std::stringstream stingStream;
  stingStream << getTime() << ".log";
  return stingStream.str();
}

void logger(std::string message) {
  std::string logFileName = logFileNameCreator();
  std::ofstream logFile(logFileName, std::ios::app);
  logFile << "[" << getTime() << "]"
          << " " << message << std::endl;
  logFile.close();
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";created";
  logger(stringStream.str());
}
Account::~Account() {
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";closed";
  logger(stringStream.str());
}

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  std::stringstream stringStream;
  stringStream << "accounts:" << Account::getNbAccounts()
               << ";total:" << Account::getTotalAmount()
               << ";deposits:" << Account::getNbDeposits()
               << ";withdrawals:" << Account::getNbWithdrawals();
  logger(stringStream.str());
}

void Account::displayStatus(void) const {
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";deposits:" << _nbDeposits
               << ";withdrawals:" << _nbWithdrawals;
  logger(stringStream.str());
}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::stringstream stringStream;
  int p_amount = _amount - deposit;
  stringStream << "index:" << _accountIndex << ";p_amount:" << p_amount
               << ";deposit:" << deposit << ";amount:" << _amount
               << ";nb_deposits:" << _nbDeposits;
  logger(stringStream.str());
}

bool Account::makeWithdrawal(int withdrawal) {
  std::stringstream stringStream;
  if (withdrawal > _amount) {
    stringStream << "index:" << _accountIndex << ";p_amount:" << _amount
                 << ";withdrawal:refused";
    logger(stringStream.str());
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  int p_amount = _amount + withdrawal;
  stringStream << "index:" << _accountIndex << ";p_amount:" << p_amount
               << ";withdrawal:" << withdrawal << ";amount:" << _amount
               << ";nb_withdrawals:" << _nbWithdrawals;
  logger(stringStream.str());
  return true;
}

int Account::checkAmount(void) const { return _amount; }

Account::Account()
    : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";created";
  logger(stringStream.str());
}