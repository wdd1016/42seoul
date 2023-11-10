#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
 public:
  ~MutantStack() {}
  MutantStack() {}
  MutantStack(const MutantStack &src) { *this = src; }
  MutantStack &operator=(const MutantStack &src) {
    if (this == &src) return (*this);
    this->c = src->c;
    return (*this);
  }

  typedef typename MutantStack::container_type::iterator iterator;
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  typedef typename MutantStack::container_type::const_iterator const_iterator;
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }

  typedef
      typename MutantStack::container_type::reverse_iterator reverse_iterator;
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }

  typedef typename MutantStack::container_type::const_reverse_iterator
      const_reverse_iterator;
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif