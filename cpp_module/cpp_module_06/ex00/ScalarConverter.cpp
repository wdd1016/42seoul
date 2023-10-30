#include "ScalarConverter.hpp"

Scalarconverter::Scalarconverter() {}

Scalarconverter::~Scalarconverter() {}

Scalarconverter::Scalarconverter(Scalarconverter const &copy) { *this = copy; }

Scalarconverter &Scalarconverter::operator=(Scalarconverter const &copy) {
  if (this != &copy) {
    return *this;
  }
  return *this;
}

bool Scalarconverter::isDecimal(const char *str, bool &isZero) {
  bool isDot = false;
  bool isScientificNotation = false;
  int i = 0;

  while (std::isspace(str[i]) == true) i++;
  if (str[i] == '+' || str[i] == '-') i++;
  if (str[i] == '\0') return false;
  while (str[i] == '0') i++;
  while (str[i] != '\0') {
    if (str[i] == '.') {
      if (isDot == true) return false;
      isDot = true;
    } else if (str[i] == 'e' || str[i] == 'E') {
      if (isScientificNotation == true) return false;
      isScientificNotation = true;
      if (str[i + 1] == '+' || str[i + 1] == '-') {
        i++;
      }
    } else if (std::isdigit(str[i]) == false) {
      if (str[i] == 'f' && str[i + 1] == '\0')
        return true;
      else
        return false;
    } else if (isZero == true && isScientificNotation == false &&
               str[i] != '0') {
      isZero = false;
    }
    i++;
  }
  if (isZero == true && (isDot == true || isScientificNotation == true))
    return false;
  else
    return true;
}

void Scalarconverter::decimalPrint(const double &doubleNumber,
                                   const bool &isZero) {
  int temp_int;
  float temp_float;

  temp_int = static_cast<int>(doubleNumber);
  if (doubleNumber == temp_int && temp_int >= -128 && temp_int <= 127) {
    if (temp_int >= 32 && temp_int <= 126)
      std::cout << "char: '" << static_cast<char>(temp_int) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  if (doubleNumber >= std::numeric_limits<int>::max() + 1.0 ||
      doubleNumber <= std::numeric_limits<int>::min() - 1.0) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << temp_int << std::endl;
  }
  temp_float = static_cast<float>(doubleNumber);
  if ((isZero == false && temp_float == 0.0) ||
      temp_float == std::numeric_limits<float>::infinity() ||
      temp_float == -std::numeric_limits<float>::infinity())
    std::cout << "float: impossible" << std::endl;
  else if (temp_float == temp_int && temp_float < 1000000 &&
           temp_float > -1000000)
    std::cout << "float: " << temp_float << ".0f" << std::endl;
  else
    std::cout << "float: " << temp_float << "f" << std::endl;
  if ((isZero == false && doubleNumber == 0.0) ||
      doubleNumber == std::numeric_limits<double>::infinity() ||
      doubleNumber == -std::numeric_limits<double>::infinity())
    std::cout << "double: impossible" << std::endl;
  else if (doubleNumber == temp_int && doubleNumber < 1000000 &&
           doubleNumber > -1000000)
    std::cout << "double: " << doubleNumber << ".0" << std::endl;
  else
    std::cout << "double: " << doubleNumber << std::endl;
}

void Scalarconverter::nonDecimalPrint(const char *str,
                                      const double &doubleNumber) {
  int temp;
  float temp_float;
  double temp_double;

  if (doubleNumber == std::numeric_limits<double>::infinity() ||
      doubleNumber == -std::numeric_limits<double>::infinity() ||
      doubleNumber != doubleNumber) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << doubleNumber << "f" << std::endl;
    std::cout << "double: " << doubleNumber << std::endl;
  }  // Infinity or NaN
  else if (str[0] != '\0' && str[1] == '\0') {
    if (str[0] >= 32 && str[0] <= 126)
      std::cout << "char: '" << str[0] << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
    temp = static_cast<int>(str[0]);
    std::cout << "int: " << temp << std::endl;
    temp_float = static_cast<float>(temp);
    std::cout << "float: " << temp_float << ".0f" << std::endl;
    temp_double = static_cast<double>(temp);
    std::cout << "double: " << temp_double << ".0" << std::endl;
  }  // char
  else {
    throw std::invalid_argument("Invalid argument");
  }  // Invalid argument
}

void Scalarconverter::convert(const char *str) {
  double doubleNumber = std::atof(str);
  bool isZero = true;

  if (isDecimal(str, isZero) == true) {
    decimalPrint(doubleNumber, isZero);
  } else {
    nonDecimalPrint(str, doubleNumber);
  }
}
