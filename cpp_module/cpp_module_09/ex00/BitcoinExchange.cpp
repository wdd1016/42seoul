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
  int year;
  int month;
  int day;

  for (int i = 0; i < 10; i++) {
    if ((i == 4 || i == 7) && date[i] == '-')
      continue;
    else if (std::isdigit(date[i]) == false)
      return false;
  }
  year = std::atoi(date.substr(0, 4).c_str());
  month = std::atoi(date.substr(5, 2).c_str());
  day = std::atoi(date.substr(8, 2).c_str());
  if (month < 1 || month > 12 || day < 1 || day > 31)
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

bool BitcoinExchange::isDecimal(const char *str) {
  bool isDot = false;
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == '.') {
      if (isDot == true) return false;
      isDot = true;
    } else if (std::isdigit(str[i]) == false) {
      return false;
    }
    i++;
  }
  return true;
}

void BitcoinExchange::setData(const char *baseFileName) {
  std::ifstream baseFile(baseFileName);
  std::string buffer;

  if (baseFile.is_open() == false)
    throw std::runtime_error(std::string(baseFileName) + " can't open.");
  std::getline(baseFile, buffer);
  if (baseFile.fail() == true)
    throw std::runtime_error("Error : Failed to read data file.");
  buffer.clear();
  while (baseFile) {
    std::getline(baseFile, buffer);
    if (baseFile.eof() == false && baseFile.fail() == true)
      throw std::runtime_error("Error : Failed to read data file.");
    if (buffer == "") continue;
    if (buffer.size() < 12 || buffer[10] != ',' ||
        checkDate(buffer.substr(0, 10)) == false ||
        isDecimal(buffer.substr(11).c_str()) == false ||
        _data.find(buffer.substr(0, 10)) != _data.end())
      throw std::runtime_error(buffer.insert(0, "Error : bad input => "));
    _data[buffer.substr(0, 10)] = std::atof(buffer.substr(11).c_str());
    buffer.clear();
  }
}

void BitcoinExchange::printValue(const char *inputFileName) {
  std::ifstream inputFile(inputFileName);
  std::string delimiter;
  std::string buffer;
  std::string date;
  std::map<std::string, double>::iterator temp;

  if (inputFile.is_open() == false)
    throw std::runtime_error("Error: could not open file.");
  std::getline(inputFile, buffer);
  if (inputFile.fail() == true)
    throw std::runtime_error("Error : Failed to read input file.");
  if (buffer != "date | value")
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
      else if (std::atof(buffer.substr(13).c_str()) <= 0 ||
               isDecimal(buffer.substr(13).c_str()) == false)
        throw std::runtime_error("Error: not a positive number.");
      else if (std::atof(buffer.substr(13).c_str()) >= 1000)
        throw std::runtime_error("Error: too large a number.");
      temp = _data.lower_bound(date);
      if (temp != _data.find(date)) {
        temp--;
      }
      std::cout << (*temp).first << " => " << buffer.substr(13) << " = "
                << (*temp).second * std::atof(buffer.substr(13).c_str())
                << std::endl;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    buffer.clear();
  }
}
