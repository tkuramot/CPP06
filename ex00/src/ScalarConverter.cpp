/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:50:31 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/09 21:02:19 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/06.
//

#include "ScalarConverter.hpp"
#include "None.tpp"
#include "Some.tpp"
#include <string>

ScalarConverter::Result::Result(Option<char> *char_ptr, Option<int> *int_ptr,
                                Option<float> *float_ptr,
                                Option<double> *double_ptr)
    : char_ptr_(char_ptr), int_ptr_(int_ptr), float_ptr_(float_ptr),
      double_ptr_(double_ptr) {}

ScalarConverter::Result::Result(const ScalarConverter::Result &obj) {
  (void)obj;
}

ScalarConverter::Result::~Result() {
  delete char_ptr_;
  delete int_ptr_;
  delete float_ptr_;
  delete double_ptr_;
}

ScalarConverter::Result &
ScalarConverter::Result::operator=(const ScalarConverter::Result &obj) {
  (void)obj;
  return *this;
}

Option<char> *ScalarConverter::Result::GetCharPtr() const { return char_ptr_; }

Option<int> *ScalarConverter::Result::GetIntPtr() const { return int_ptr_; }

Option<float> *ScalarConverter::Result::GetFloatPtr() const {
  return float_ptr_;
}

Option<double> *ScalarConverter::Result::GetDoublePtr() const {
  return double_ptr_;
}

ScalarConverter::Result ScalarConverter::Convert(const std::string &literal) {
  return ScalarConverter::Result(
      ConvertStrToChar(literal), ConvertStrToInt(literal),
      ConvertStrToFloat(literal), ConvertStrToDouble(literal));
}

Option<char> *ScalarConverter::ConvertStrToChar(const std::string &literal) {
  int i;
  try {
    i = std::stoi(literal);
  } catch (std::exception &e) {
    return new None<char>();
  }
  if (i < ' ' || i > '~') {
    return new None<char>();
  }
  return new Some<char>(static_cast<char>(i));
}

Option<int> *ScalarConverter::ConvertStrToInt(const std::string &literal) {
  int i;
  try {
    i = std::stoi(literal);
  } catch (std::exception &e) {
    return new None<int>();
  }
  return new Some<int>(static_cast<int>(i));
}

Option<float> *ScalarConverter::ConvertStrToFloat(const std::string &literal) {
  float f;
  try {
    f = std::stof(literal);
  } catch (std::exception &e) {
    return new None<float>();
  }
  return new Some<float>(static_cast<float>(f));
}

Option<double> *
ScalarConverter::ConvertStrToDouble(const std::string &literal) {
  double d;
  try {
    d = std::stof(literal);
  } catch (std::exception &e) {
    return new None<double>();
  }
  return new Some<double>(static_cast<double>(d));
}
