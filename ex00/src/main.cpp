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

void PrintResult(Option<char> *char_ptr) {
  std::cout << "char: ";
  if (char_ptr->IsSome()) {
    char c = char_ptr->Unwrap();
    if (c < ' ' || c > '~') {
      std::cout << "Non displayable" << std::endl;
      return;
    }
    std::cout << '\'' << c << '\'' << std::endl;
    return;
  }
  std::cout << "impossible" << std::endl;
}

void PrintResult(Option<int> *int_ptr) {
  std::cout << "int: ";
  if (int_ptr->IsSome()) {
    std::cout << int_ptr->Unwrap() << std::endl;
    return;
  }
  std::cout << "impossible" << std::endl;
}

void PrintResult(Option<float> *float_ptr) {
  std::cout << "float: ";
  if (float_ptr->IsSome()) {
    std::cout << float_ptr->Unwrap() << 'f' << std::endl;
    return;
  }
  std::cout << "impossible" << std::endl;
}

void PrintResult(Option<double> *double_ptr) {
  std::cout << "double: ";
  if (double_ptr->IsSome()) {
    std::cout << double_ptr->Unwrap() << std::endl;
    return;
  }
  std::cout << "impossible" << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid number of arguments" << std::endl;
    return 1;
  }
  ScalarConverter::Result res = ScalarConverter::Convert(argv[1]);
  PrintResult(res.GetCharPtr());
  PrintResult(res.GetIntPtr());
  std::cout << std::fixed << std::setprecision(1);
  PrintResult(res.GetFloatPtr());
  PrintResult(res.GetDoublePtr());
  return 0;
}