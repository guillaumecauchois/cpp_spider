/*
** Process.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/common/Process.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Nov 01 14:29:00 2017 Guillaume CAUCHOIS
** Last update Wed Nov 01 14:29:00 2017 Guillaume CAUCHOIS
*/

#ifndef		_PROCESS__HPP_
# define	_PROCESS__HPP_
# include <iostream>
# include <algorithm>

class Process
{
private:
  std::string	_name;
  int		_id = 0;

public:
  Process();
  ~Process();

  void UpdateProcess();

  void		setId(const int &);
  void		setProcessusName(const std::string &pname);

  const		std::string& getProcessusName() const;
  int		getId() const;

  template <class Archive>
  void	serialize(Archive &ar, const unsigned int version)
  {
    ar & _name;
    ar & _id;
  }
};

#endif		/* !_PROCESS__HPP_! */

