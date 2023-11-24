#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>

class BitcoinExchange {
 private:
  std::map<std::string, double> _data;

  BitcoinExchange(const BitcoinExchange &src);
  BitcoinExchange &operator=(const BitcoinExchange &src);

  bool checkDate(const std::string &date);

 public:
  BitcoinExchange();
  ~BitcoinExchange();

  void setData(const char *baseFileName);
  void printValue(const char *inputFileName);
};

#endif