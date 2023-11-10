#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  std::cout << "Make a MutantStack<int>, push(5, 17) and top(), pop(), size()"
            << std::endl;
  mstack.push(5);
  mstack.push(17);
  std::cout << "MutantStack top : " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "MutantStack size : " << mstack.size() << std::endl << std::endl;
  std::cout << "push(3, 5, 737, 0) and iterating by MutantStack<int>::iterator"
            << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << std::endl;

  std::cout << "Make a std::stack<int> by copy MutantStack & print top of "
               "stack in pop all elements."
            << std::endl;
  std::stack<int> s(mstack);
  while (s.size() > 0) {
    std::cout << s.top() << std::endl;
    s.pop();
  }
  std::cout << std::endl;

  std::list<int> lst;
  std::cout << "Make a std::list<int>, push_back(5, 17) and back(), "
               "pop_back(), size()"
            << std::endl;
  lst.push_back(5);
  lst.push_back(17);
  std::cout << "list back: " << lst.back() << std::endl;
  lst.pop_back();
  std::cout << "list size: " << lst.size() << std::endl << std::endl;
  std::cout
      << "push_back(3, 5, 737, 0) and iterating by std::list<int>::iterator"
      << std::endl;
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  //[...]
  lst.push_back(0);
  std::list<int>::iterator itl = lst.begin();
  std::list<int>::iterator itle = lst.end();
  ++itl;
  --itl;
  while (itl != itle) {
    std::cout << *itl << std::endl;
    ++itl;
  }

  return 0;
}
