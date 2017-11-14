/*
** Position.hpp for cpp_spider in ./inc/common/Position.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Sep 28 08:53:09 2017 Guillaume CAUCHOIS
** Last update Thu Sep 28 08:53:09 2017 Guillaume CAUCHOIS
*/

#ifndef		_POSITION__HPP_
# define	_POSITION__HPP_

class Position
{
private:
  int		_x = 0;
  int		_y = 0;

public:
  Position();
  Position(const int &, const int &);
  virtual ~Position();

  int		getX() const;
  int		getY() const;
  void	setX(const int &);
  void	setY(const int &);

  template <class Archive>
  void	serialize(Archive &ar, const unsigned int version)
  {
    ar & _x;
    ar & _y;
  }
};

#endif		/* !_POSITION__HPP_! */