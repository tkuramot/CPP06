/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:00:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/10 23:00:42 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/10.
//

#include "Serializer.hpp"

uintptr_t Serializer::Serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::Deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
