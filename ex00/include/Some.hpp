//
// Created by k.t. on 2023/12/09.
//

#ifndef CONVERT_EX00_SOME_HPP_
#define CONVERT_EX00_SOME_HPP_

#include "Option.hpp"

template <typename T> class Some : public Option<T> {
public:
  Some() {}
  Some(T value) : Option<T>(), value_(value) {}
  Some(const Some<T> &obj) : Option<T>(obj), value_(obj.value_) {}
  Some &operator=(const Some<T> &obj) {
    value_ = obj.value_;
    return *this;
  }

  T Unwrap() { return value_; }
  bool IsSome() { return true; }
  Option<T> *Clone() {
    return new Some(value_);
  }

private:
  T value_;
};

#endif // CONVERT_EX00_SOME_HPP_
