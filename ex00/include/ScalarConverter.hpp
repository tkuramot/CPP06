/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:50:31 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/11 00:39:03 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/06.
//

#ifndef CPP06_EX00_SCALARCONVERTER_HPP_
#define CPP06_EX00_SCALARCONVERTER_HPP_

#include "Option.hpp"
#include <string>

class ScalarConverter {
public:
  typedef struct Result {
    char c;
    int i;
    float f;
    double d;
  } Result;
  typedef struct PossibleType {
    Option<bool> *is_char;
    Option<bool> *is_int;
    Option<bool> *is_float;
    Option<bool> *is_double;
    ~PossibleType();
  } PossibleType;
  template <typename T> static Result *Convert(T value);
  static PossibleType *DetectType(const std::string &literal);
  static Option<bool> *IsConvertableToChar(const std::string &literal);
  static Option<bool> *IsConvertableToInt(const std::string &literal);
  static Option<bool> *IsConvertableToFloat(const std::string &literal);
  static Option<bool> *IsConvertableToDouble(const std::string &literal);
};

template <typename T> ScalarConverter::Result *ScalarConverter::Convert(T value) {
  ScalarConverter::Result *res = new ScalarConverter::Result;
  res->c = static_cast<char>(value);
  res->i = static_cast<int>(value);
  res->f = static_cast<float>(value);
  res->d = static_cast<double>(value);
  return res;
}

#endif // CPP06_EX00_SCALARCONVERTER_HPP_
