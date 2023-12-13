/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:50:31 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/11 00:39:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/06.
//

#include "ScalarConverter.hpp"
#include "None.hpp"
#include "Some.hpp"
#include <iostream>
#include <string>

ScalarConverter::PossibleType::~PossibleType() {
  delete is_char;
  delete is_int;
  delete is_float;
  delete is_double;
}

ScalarConverter::PossibleType *
ScalarConverter::DetectType(const std::string &literal) {
  ScalarConverter::PossibleType *res = new ScalarConverter::PossibleType;
  res->is_char = ScalarConverter::IsConvertableToChar(literal);
  res->is_int = ScalarConverter::IsConvertableToInt(literal);
  res->is_float = ScalarConverter::IsConvertableToFloat(literal);
  res->is_double = ScalarConverter::IsConvertableToDouble(literal);
  return res;
}

Option<bool> *ScalarConverter::IsConvertableToChar(const std::string &literal) {
  if (literal.size() != 3) {
    try {
      std::stoi(literal);
    } catch (std::exception &e) {
      return new None<bool>();
    }
    return new Some<bool>(false);
  }
  if (literal.front() != '\'' || literal.back() != '\'') {
    if (!isdigit(literal.front()) ||
        !(isdigit(literal.back()) || literal.back() == 'f'))
      return new None<bool>();
    return new Some<bool>(false);
  }
  return new Some<bool>(true);
}

Option<bool> *ScalarConverter::IsConvertableToInt(const std::string &literal) {
  try {
    std::stoi(literal);
  } catch (std::exception &e) {
    return new None<bool>();
  }
  // 小数点がある場合
  if (literal.find('.') != std::string::npos) {
    return new Some<bool>(false);
  }
  return new Some<bool>(true);
}

Option<bool> *
ScalarConverter::IsConvertableToFloat(const std::string &literal) {
  try {
    std::stof(literal);
  } catch (std::exception &e) {
    return new None<bool>();
  }
  if (literal.find('f') == std::string::npos) {
    return new Some<bool>(false);
  }
  return new Some<bool>(true);
}

Option<bool> *
ScalarConverter::IsConvertableToDouble(const std::string &literal) {
  try {
    std::stof(literal);
  } catch (std::exception &e) {
    return new None<bool>();
  }
  if (literal.find('f') != std::string::npos) {
    return new Some<bool>(false);
  }
  return new Some<bool>(true);
}