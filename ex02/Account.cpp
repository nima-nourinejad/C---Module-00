#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>

Account::Account(){}
Account::~Account(){}
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


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

void _displayTimestamp(void) {
	std::cout << getTime() << std::endl;
}

std::string logFileNameCreator() {
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

Account::Account(int initial_deposit) : _amount(initial_deposit), _accountIndex(_nbAccounts - 1), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::stringstream stringStream;
	stringStream << "index:" << _accountIndex << ";amount:" << _amount << ";created";
	logger(stringStream.str());
}