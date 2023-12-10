//
// Created by k.t. on 2023/12/10.
//

#include "Data.hpp"
Data::Data(const std::string &title, const std::string &content)
    : title_(title), content_(content) {}

Data::Data(const Data &obj)
    : title_(obj.title_), content_(obj.content_) {}

Data::~Data() {}

Data &Data::operator=(const Data &obj) {
  title_ = obj.title_;
  content_ = obj.content_;
  return *this;
}

const std::string &Data::GetTitle() const { return title_; }

void Data::SetTitle(const std::string &title) { title_ = title; }

const std::string &Data::GetContent() const { return content_; }

void Data::SetContent(const std::string &content) { content_ = content; }
