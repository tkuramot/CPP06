//
// Created by k.t. on 2023/12/09.
//

#ifndef CONVERT_EX00_SOME_HPP_
#define CONVERT_EX00_SOME_HPP_

#include "Option.tpp"

template <typename T> class Some : public Option<T> {
public:
  Some() {}
  Some(T value) : Option<T>(), value_(value) {}
  Some(const Option<T> &obj) : Option<T>(obj) { (void)obj; }
  T unwrap() { return value_; }
  bool IsSome() { return true; }
  T GetValue() const { return value_; }
  void SetValue(T value) { value_ = value; }

private:
  T value_;
};

#endif // CONVERT_EX00_SOME_HPP_
