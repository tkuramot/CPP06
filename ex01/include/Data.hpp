/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:17:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/10 23:17:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/10.
//

#ifndef A_OUT_INCLUDE_DATA_HPP_
#define A_OUT_INCLUDE_DATA_HPP_

#include <string>

class Data {
public:
  Data(const std::string &title, const std::string &content);
  Data(const Data &obj);
  ~Data();
  Data &operator=(const Data &obj);

  const std::string &GetTitle() const;
  void SetTitle(const std::string &title);
  const std::string &GetContent() const;
  void SetContent(const std::string &content);

private:
  std::string title_;
  std::string content_;
};

#endif // A_OUT_INCLUDE_DATA_HPP_
