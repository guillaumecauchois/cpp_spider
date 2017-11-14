/*
** Position.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/common/Position.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Sep 28 08:57:15 2017 Guillaume CAUCHOIS
** Last update Thu Sep 28 08:57:15 2017 Guillaume CAUCHOIS
*/

#include "Position.hpp"

Position::Position()
{
}

Position::Position(const int &x, const int &y) : _x(x), _y(y) {}

Position::~Position() {}

int	Position::getX() const
{
  return this->_x;
}

int	Position::getY() const
{
  return this->_y;
}

void	Position::setX(const int &x)
{
  this->_x = x;
}

void	Position::setY(const int &y)
{
  this->_y = y;
}