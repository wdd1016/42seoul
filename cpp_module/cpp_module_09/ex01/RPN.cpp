#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) { _numbers = src._numbers; }

RPN &RPN::operator=(const RPN &src) {
  if (this != &src) {
    _numbers = src._numbers;
  }
  return *this;
}

void RPN::operation(char optr) {
  int a;
  int b;

  if (_numbers.empty())
    throw std::runtime_error("Error : Not enough numbers for the operation.");
  b = _numbers.top();
  _numbers.pop();
  if (_numbers.empty())
    throw std::runtime_error("Error : Not enough numbers for the operation.");
  a = _numbers.top();
  _numbers.pop();

  switch (optr) {
    case '+':
      _numbers.push(a + b);
      break;
    case '-':
      _numbers.push(a - b);
      break;
    case '*':
      _numbers.push(a * b);
      break;
    case '/':
      if (b == 0) throw std::runtime_error("Error : Division by zero.");
      _numbers.push(a / b);
      break;
    default:
      break;
  }
}

void RPN::calculation(const char *str) {
  std::string temp = str;
  std::stringstream ss(temp);
  char *str_end;

  temp.clear();
  try {
    while (ss >> temp) {
      if (temp == "*" || temp == "/" || temp == "+" || temp == "-") {
        operation(temp[0]);
      } else {
        errno = 0;
        _numbers.push(std::strtol(temp.c_str(), &str_end, 10));
        if (*str_end != '\0')
          throw std::runtime_error("Error : Invalid argument.");
        else if (errno == ERANGE || _numbers.top() < -9 || _numbers.top() > 9)
          throw std::runtime_error("Error : Out of range number.");
      }
      temp.clear();
    }
    if (_numbers.size() == 1) {
      std::cout << _numbers.top() << std::endl;
      _numbers.pop();
    } else
      throw std::runtime_error("Error : Not enough operators.");
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    while (_numbers.empty() == false) _numbers.pop();
  }
}