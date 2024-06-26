#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  if (this != &src) {
    _data = src._data;
  }
  return (*this);
}

bool BitcoinExchange::checkDate(const std::string &date) {
  char *str_end;
  int year;
  int month;
  int day;

  if (date[4] != '-' || date[7] != '-') return false;
  year = std::strtol(date.substr(0, 4).c_str(), &str_end, 10);
  if (*str_end != '\0') return false;
  month = std::strtol(date.substr(5, 2).c_str(), &str_end, 10);
  if (*str_end != '\0') return false;
  day = std::strtol(date.substr(8, 2).c_str(), &str_end, 10);
  if (*str_end != '\0' || month < 1 || month > 12 || day < 1 || day > 31)
    return false;
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  else if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      if (day > 29) return false;
    } else if (day > 28)
      return false;
  }
  return true;
}

void BitcoinExchange::setData(const char *baseFileName) {
  std::ifstream baseFile(baseFileName);
  std::string buffer;
  double price;
  char *str_end = NULL;

  if (baseFile.is_open() == false)
    throw std::runtime_error(std::string(baseFileName) + " can't open.");
  std::getline(baseFile, buffer);
  if (baseFile.fail() == true)
    throw std::runtime_error("Error : Failed to read data file.");
  else if (buffer != "date,exchange_rate")
    throw std::runtime_error(buffer.insert(0, "Error : bad input => "));
  buffer.clear();
  while (baseFile) {
    std::getline(baseFile, buffer);
    if (baseFile.fail() == true && baseFile.eof() == false)
      throw std::runtime_error("Error : Failed to read data file.");
    if (buffer == "") continue;
    if (buffer.size() < 12 || buffer[10] != ',' ||
        checkDate(buffer.substr(0, 10)) == false ||
        _data.find(buffer.substr(0, 10)) != _data.end())
      throw std::runtime_error(buffer.insert(0, "Error : bad input => "));
    price = std::strtod(buffer.substr(11).c_str(), &str_end);
    if (*str_end != '\0' || price < 0 ||
        price == std::numeric_limits<double>::infinity())
      throw std::runtime_error(buffer.insert(0, "Error : bad input => "));
    _data[buffer.substr(0, 10)] = price;
    buffer.clear();
  }
}

void BitcoinExchange::printValue(const char *inputFileName) {
  std::ifstream inputFile(inputFileName);
  std::string buffer;
  std::string date;
  double price;
  char *str_end = NULL;
  std::map<std::string, double>::iterator temp;

  if (inputFile.is_open() == false)
    throw std::runtime_error("Error: could not open file.");
  std::getline(inputFile, buffer);
  if (inputFile.fail() == true)
    throw std::runtime_error("Error : Failed to read input file.");
  else if (buffer != "date | value")
    throw std::runtime_error(buffer.insert(0, "Error : bad input => "));
  buffer.clear();
  while (inputFile) {
    std::getline(inputFile, buffer);
    if (inputFile.eof() == false && inputFile.fail() == true) {
      throw std::runtime_error("Error : Failed to read input file.");
    } else if (buffer == "") {
      continue;
    }
    try {
      date = buffer.substr(0, 10);
      if (buffer.size() < 14 || buffer.find(" | ") != 10 ||
          checkDate(date) == false || date < (*_data.begin()).first)
        throw std::runtime_error(buffer.insert(0, "Error : bad input => "));
      price = std::strtod(buffer.substr(13).c_str(), &str_end);
      if (price <= 0 || *str_end != '\0')
        throw std::runtime_error("Error: not a positive number.");
      else if (price >= 1000)
        throw std::runtime_error("Error: too large a number.");
      temp = _data.lower_bound(date);
      if (temp != _data.find(date) || temp == _data.end()) {
        temp--;
      }
      std::cout << date << " => " << price << " = " << (*temp).second * price
                << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    buffer.clear();
  }
}
