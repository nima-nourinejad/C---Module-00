#include "Account.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account() {}
std::string getTime() {
  time_t currentTimestamp;
  currentTimestamp = time(NULL);

  tm *localTime;
  localTime = localtime(&currentTimestamp);

  std::stringstream stringStream;
  stringStream << "[" << localTime->tm_year + 1900 << localTime->tm_mon + 1
               << localTime->tm_mday << "_" << localTime->tm_hour
               << localTime->tm_min << localTime->tm_sec << "]";
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
  logFile << getTime() << " " << message << std::endl;
  logFile.close();
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts - 1), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";created";
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
    : _accountIndex(_nbAccounts - 1), _amount(0), _nbDeposits(0),
      _nbWithdrawals(0) {}