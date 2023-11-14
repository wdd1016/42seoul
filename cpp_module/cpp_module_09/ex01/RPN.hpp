#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
 private:
  std::stack<int> _numbers;

  RPN(const RPN &src);
  RPN &operator=(const RPN &src);
  void operation(char optr);
  int convertInteger(const std::string &num);

 public:
  RPN();
  ~RPN();
  void calculation(const char *str);
};

#endif