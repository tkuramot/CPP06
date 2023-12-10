/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:12:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/10 23:12:03 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/10.
//

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  {
    std::cout << "==============NORMAL==============" << std::endl;
    Data *data_ptr = new Data("title", "content");
    std::cout << "original ptr: " << data_ptr << std::endl;
    std::cout << "title: " << data_ptr->GetTitle() << std::endl;
    std::cout << "content: " << data_ptr->GetContent() << std::endl;
    uintptr_t uintptr = Serializer::Serialize(data_ptr);
    std::cout << "serialized ptr: " << uintptr << std::endl;

    Data *deserialized_ptr = Serializer::Deserialize(uintptr);
    std::cout << "deserialized ptr: " << deserialized_ptr << std::endl;
    std::cout << "title: " << deserialized_ptr->GetTitle() << std::endl;
    std::cout << "content: " << deserialized_ptr->GetContent() << std::endl;
    delete data_ptr;
  }
  {
    std::cout << "==============NULL==============" << std::endl;
    Data *data_ptr = NULL;
    std::cout << "original ptr: " << data_ptr << std::endl;
    uintptr_t uintptr = Serializer::Serialize(data_ptr);
    std::cout << "serialized ptr: " << uintptr << std::endl;

    Data *deserialized_ptr = Serializer::Deserialize(uintptr);
    std::cout << "deserialized ptr: " << deserialized_ptr << std::endl;
    delete data_ptr;
  }
}