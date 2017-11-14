/*
** SpiderException.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/common/SpiderException.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 08:33:24 2017 Guillaume CAUCHOIS
** Last update Fri Sep 29 08:33:24 2017 Guillaume CAUCHOIS
*/

#include "SpiderException.hpp"

SpiderException::SpiderException(const std::string &errMsg) throw() : _what(errMsg) {}

const char* SpiderException::what() const throw()
{
  return this->_what.c_str();
}