/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:01 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/06 14:47:01 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/06.
//

#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>

void Print(ScalarConverter::PossibleType *possible_type,
           ScalarConverter::Result *res) {
  std::cout << "char: ";
  if (possible_type->is_char->IsSome()) {
    if (!isprint(res->c)) {
      std::cout << "Non displayable" << std::endl;
    } else {
      std::cout << '\'' << res->c << '\'' << std::endl;
    }
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << "int: ";
  if (possible_type->is_int->IsSome() || possible_type->is_char->IsSome()) {
    std::cout << res->i << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << "float: ";
  std::cout << std::fixed << std::setprecision(1);
  if (possible_type->is_float->IsSome() || possible_type->is_char->IsSome()) {
    std::cout << res->f << 'f' << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << "double: ";
  if (possible_type->is_double->IsSome() || possible_type->is_char->IsSome()) {
    std::cout << res->d << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << std::fixed << std::setprecision(0);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./convert literal" << std::endl;
    return 1;
  }
  std::string literal = std::string(argv[1]);
  ScalarConverter::PossibleType *possible_type =
      ScalarConverter::DetectType(literal);
  ScalarConverter::Result *res;
  if (possible_type->is_char->IsSome() && possible_type->is_char->Unwrap()) {
    res = ScalarConverter::Convert(literal[1]);
    Print(possible_type, res);
  } else if (possible_type->is_int->IsSome() &&
             possible_type->is_int->Unwrap()) {
    res = ScalarConverter::Convert(std::stoi(literal));
    Print(possible_type, res);
  } else if (possible_type->is_float->IsSome() &&
             possible_type->is_float->Unwrap()) {
    res = ScalarConverter::Convert(std::stof(literal));
    Print(possible_type, res);
  } else if (possible_type->is_double->IsSome() &&
             possible_type->is_double->Unwrap()) {
    res = ScalarConverter::Convert(std::stod(literal));
    Print(possible_type, res);
  } else {
    res = ScalarConverter::Convert(0);
    Print(possible_type, res);
  }
  delete possible_type;
  delete res;
  return 0;
}