/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:50:31 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/06 14:50:40 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/06.
//

#ifndef CPP06_EX00_SCALARCONVERTER_HPP_
#define CPP06_EX00_SCALARCONVERTER_HPP_

#include "Option.tpp"
#include <string>

class ScalarConverter {
public:
  class Result {
  public:
    Result(Option<char> *char_ptr, Option<int> *int_ptr,
           Option<float> *float_ptr, Option<double> *double_ptr);
    Result(const Result &obj);
    ~Result();
    Result &operator=(const Result &obj);
    Option<char> *GetCharPtr() const;
    Option<int> *GetIntPtr() const;
    Option<float> *GetFloatPtr() const;
    Option<double> *GetDoublePtr() const;

  private:
    Option<char> *char_ptr_;
    Option<int> *int_ptr_;
    Option<float> *float_ptr_;
    Option<double> *double_ptr_;
  };
  static Result Convert(const std::string &literal);
  static Option<char> *ConvertStrToChar(const std::string &literal);
  static Option<int> *ConvertStrToInt(const std::string &literal);
  static Option<float> *ConvertStrToFloat(const std::string &literal);
  static Option<double> *ConvertStrToDouble(const std::string &literal);
};

#endif // CPP06_EX00_SCALARCONVERTER_HPP_
