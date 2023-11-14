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

int RPN::convertInteger(const std::string &num) {
  const char *temp = num.c_str();
  double numF = std::atof(num.c_str());

  while (*temp == '+' || *temp == '-') temp++;
  while (*temp >= '0' && *temp <= '9') temp++;
  if (*temp != '\0') {
    throw std::runtime_error("Error : Invalid argument.");
  }
  if (numF < -9.0 || numF > 9.0)
    throw std::runtime_error("Error : Out of range number.");
  return std::atoi(num.c_str());
}

void RPN::calculation(const char *str) {
  std::string temp = str;
  std::stringstream ss(temp);

  temp.clear();
  try {
    while (ss >> temp) {
      if (temp == "*" || temp == "/" || temp == "+" || temp == "-") {
        operation(temp[0]);
      } else {
        _numbers.push(convertInteger(temp));
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