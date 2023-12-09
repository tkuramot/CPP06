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

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid number of arguments" << std::endl;
    return 1;
  }
  ScalarConverter::Result res = ScalarConverter::Convert(argv[1]);
  std::cout << "char: ";
  if (res.GetCharPtr()->IsSome()) {
    std::cout << '\'' << res.GetCharPtr()->unwrap() << '\'' << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << "int: ";
  if (res.GetIntPtr()->IsSome()) {
    std::cout << res.GetIntPtr()->unwrap() << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << "float: ";
  if (res.GetFloatPtr()->IsSome()) {
    std::cout << std::fixed << std::setprecision(1) << res.GetDoublePtr()->unwrap() << 'f' << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  std::cout << "double: ";
  if (res.GetDoublePtr()->IsSome()) {
    std::cout << res.GetFloatPtr()->unwrap() << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
  return 0;
}