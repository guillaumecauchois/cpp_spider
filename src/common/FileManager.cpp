/*
** FileManager.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/common/FileManager.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 08:04:00 2017 Guillaume CAUCHOIS
** Last update Fri Sep 29 08:04:00 2017 Guillaume CAUCHOIS
*/

#include <iostream>
#include <sstream>
#include "SpiderException.hpp"
#include "FileManager.hpp"

FileManager::FileManager(const std::string &path) : _path(path)
{
  std::ofstream	file(path);
  file.close();

  this->_stream = std::fstream(_path, std::fstream::in | std::fstream::out | std::fstream::ate);
  if (!this->_stream.is_open())
    throw SpiderException("cannot opening the file");
}

FileManager::~FileManager()
{
  this->_stream.close();
}

const std::string	FileManager::readFile(int size)
{
  std::stringstream	ss;
  auto			*str = new char[size];
  this->_stream.seekg(0, this->_stream.beg);
  this->_stream.read(str, size);

  ss << str;
  delete str;
  return ss.str();
}

void			FileManager::writeFile(const std::string &str)
{
  this->_stream.seekg(0, this->_stream.end);
  this->_stream << str;
}