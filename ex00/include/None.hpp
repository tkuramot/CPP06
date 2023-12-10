//
// Created by k.t. on 2023/12/09.
//

#ifndef CONVERT_EX00_NONE_HPP_
#define CONVERT_EX00_NONE_HPP_

#include "Option.hpp"
#include <stdexcept>

template <typename T> class None : public Option<T> {
public:
  None() : Option<T>() {}
  None(const Option<T> &obj) : Option<T>(obj) {}
  ~None() {}
  None &operator=(const None<T> &obj) {
    Option<T>::operator=(obj);
    return *this;
  }

  T Unwrap() { throw std::runtime_error("Invalid value"); }
  bool IsSome() { return false; }
  Option<T> *Clone() {
    return new None();
  }
};

#endif // CONVERT_EX00_NONE_HPP_
