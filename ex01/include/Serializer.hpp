/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:00:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/10 23:02:55 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/10.
//

#ifndef CPP06_EX01_SERIALIZER_HPP_
#define CPP06_EX01_SERIALIZER_HPP_

#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
  static uintptr_t Serialize(Data *ptr);
  static Data *Deserialize(uintptr_t raw);
};

#endif // CPP06_EX01_SERIALIZER_HPP_
