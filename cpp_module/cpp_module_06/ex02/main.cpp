#include "Base.hpp"

Base *generate() {
  int i = rand() % 3;

  switch (i) {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
    default:
      return NULL;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "Type A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "Type B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "Type C" << std::endl;
  else
    std::cout << "Type Error" << std::endl;
}

void identify(Base &p) {
  try {
    A &tmpA = dynamic_cast<A &>(p);
    (void)tmpA;
    std::cout << "Type A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    B &tmpB = dynamic_cast<B &>(p);
    (void)tmpB;
    std::cout << "Type B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    C &tmpC = dynamic_cast<C &>(p);
    (void)tmpC;
    std::cout << "Type C" << std::endl;
  } catch (std::exception &e) {
  }
}

int main() {
  srand(time(NULL));

  std::cout << "First test" << std::endl;
  Base *base = generate();
  std::cout << "Identify by pointer : ";
  identify(base);
  std::cout << "Identify by reference : ";
  identify(*base);
  delete base;

  std::cout << std::endl << "Second test" << std::endl;
  base = generate();
  std::cout << "Identify by pointer : ";
  identify(base);
  std::cout << "Identify by reference : ";
  identify(*base);
  delete base;

  std::cout << std::endl << "Third test" << std::endl;
  base = generate();
  std::cout << "Identify by pointer : ";
  identify(base);
  std::cout << "Identify by reference : ";
  identify(*base);
  delete base;

  return 0;
}
