#include "BitcoinExchange.hpp"

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return EXIT_FAILURE;
  }

  BitcoinExchange baseData;

  try {
    baseData.setData("data.csv");
    baseData.printValue(argv[1]);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}