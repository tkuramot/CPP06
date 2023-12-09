//
// Created by k.t. on 2023/12/09.
//

#ifndef CONVERT_EX00_OPTION_HPP_
#define CONVERT_EX00_OPTION_HPP_

template <typename T> class Option {
public:
  Option() {}
  Option(const Option &obj) { (void)obj; }
  virtual ~Option() {}
  Option &operator=(const Option &obj) {
    (void)obj;
    return *this;
  }

  virtual T unwrap() = 0;
  virtual bool IsSome() = 0;
};

#endif // CONVERT_EX00_OPTION_HPP_
