#include "Account.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void add(std::stringstream &stringstream, int value) {
  if (value < 10)
	stringstream << "0";
  stringstream << value;
}

void grabData(tm *localTime, int &year, int &month, int &day, int &hour,
			  int &min, int &sec) {
  year = localTime->tm_year + 1900;
  month = localTime->tm_mon + 1;
  day = localTime->tm_mday;
  hour = localTime->tm_hour;
  min = localTime->tm_min;
  sec = localTime->tm_sec;
}

void addData(std::stringstream &stringStream, int year, int month, int day,
			 int hour, int min, int sec)
{
  stringStream << year;
  add(stringStream, month);
  add(stringStream, day);
  stringStream << "_";
  add(stringStream, hour);
  add(stringStream, min);
  add(stringStream, sec);

}

std::string getTime() {

  /// Get the current timestamp
  time_t currentTimestamp;
  currentTimestamp = time(NULL);

  /// Convert the timestamp to a local time
  tm *localTime;
  localTime = localtime(&currentTimestamp);

  /// Get the year, month, day, hour, min, sec
  int year, month, day, hour, min, sec;
  grabData(localTime, year, month, day, hour, min, sec);

  /// Create a string stream to store the local time in the format of year_month_day_hour_min_sec
  std::stringstream stringStream;
  addData(stringStream, year, month, day, hour, min, sec);

  return stringStream.str();
}

////////////////////////////////////////////////////// Display the current time required by header
void _displayTimestamp(void) { std::cout << getTime() << std::endl; }

////////////////////////////////////////////////////// Create a log file name based on the current time and with a .log extension
std::string logFileNameCreator(void) {
  std::stringstream stingStream;
  stingStream << getTime() << ".log";
  return stingStream.str();
}

////////////////////////////////////////////////////// Create or append to a log file with time and with the message passed as an argument
void logger(std::string message) {
  std::string logFileNameString = logFileNameCreator();
  const char *logFileName = logFileNameString.c_str();
  std::ofstream logFile(logFileName, std::ios::app);
  logFile << "[" << getTime() << "]"
          << " " << message << std::endl;
  logFile.close();
}

////////////////////////////////////////////////////// Constructor with initial deposit and log the creation of the account
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

////////////////////////////////////////////////////// Destructor and log the closure of the account
Account::~Account() {
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";closed";
  logger(stringStream.str());
}

////////////////////////////////////////////////////// Get the total number of accounts, total amount, total number of deposits, and total number of withdrawals (static)
int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

////////////////////////////////////////////////////// Display the total number of accounts, total amount, total number of deposits, and total number of withdrawals (static)
void Account::displayAccountsInfos(void) {
  std::stringstream stringStream;
  stringStream << "accounts:" << Account::getNbAccounts()
               << ";total:" << Account::getTotalAmount()
               << ";deposits:" << Account::getNbDeposits()
               << ";withdrawals:" << Account::getNbWithdrawals();
  logger(stringStream.str());
}

////////////////////////////////////////////////////// Display the single account index, amount, number of deposits, and number of withdrawals
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
////////////////////////////////////////////////////// Check the amount of the account required by the header
int Account::checkAmount(void) const { return _amount; }

////////////////////////////////////////////////////// Default constructor and log the creation of the account
Account::Account()
    : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  std::stringstream stringStream;
  stringStream << "index:" << _accountIndex << ";amount:" << _amount
               << ";created";
  logger(stringStream.str());
}