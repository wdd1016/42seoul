#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename I, typename F>
void iter(T arr, I len, F &func) {
  for (I i = 0; i < len; i++) {
    func(arr[i]);
  }
};

#endif
