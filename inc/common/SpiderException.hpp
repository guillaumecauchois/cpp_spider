/*
** SpiderException.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/common/SpiderException.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 08:27:38 2017 Guillaume CAUCHOIS
** Last update Fri Sep 29 08:27:38 2017 Guillaume CAUCHOIS
*/

#ifndef		_SPIDER_EXCEPTION__HPP_
# define	_SPIDER_EXCEPTION__HPP_
# include <exception>
# include <string>

class SpiderException : public std::exception
{
private:
  const std::string	_what;
public:
  SpiderException(const std::string &) throw();
  virtual ~SpiderException() throw() {};
  virtual const char	*what(void) const throw();

};

#endif		/* !_SPIDER_EXCEPTION__HPP_! */