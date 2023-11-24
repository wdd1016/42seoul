#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <limits>
#include <string>

class Scalarconverter {
 private:
  Scalarconverter();
  Scalarconverter(Scalarconverter const &copy);
  Scalarconverter &operator=(Scalarconverter const &copy);

  static void decimalPrint(const double &doubleNumber, const bool &isZero);
  static void nonDecimalPrint(const char *str, const double &doubleNumber);

 public:
  ~Scalarconverter();
  static void convert(const char *str);
};

#endif