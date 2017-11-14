/*
** FileManager.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/common/FileManager.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 07:57:21 2017 Guillaume CAUCHOIS
** Last update Fri Sep 29 07:57:21 2017 Guillaume CAUCHOIS
*/

#ifndef		_FILE_MANAGER__HPP_
# define	_FILE_MANAGER__HPP_
# include <string>
# include <fstream>

class FileManager
{
private:
  const std::string	_path;
  std::fstream		_stream;
  std::string		_buffer;

public:
  FileManager(const std::string &);
  virtual ~FileManager();
  void			writeFile(const std::string &);
  const std::string	readFile(int size);
};

#endif		/* !_FILE_MANAGER__HPP_! */