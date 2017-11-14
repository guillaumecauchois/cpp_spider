/*
** MouseButton.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/server/MouseButton.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 13:33:22 2017 Guillaume CAUCHOIS
** Last update Fri Sep 29 13:33:22 2017 Guillaume CAUCHOIS
*/

#ifndef		_MOUSE_BUTTON__HPP_
# define	_MOUSE_BUTTON__HPP_
# include <unordered_map>
# include <vector>
#include <boost/serialization/vector.hpp>

class MouseButton
{
public:
  enum	MouseButtonType
  {
    UNKNOWN_CLICK = -1,
    LEFT_CLICK = 0,
    RIGHT_CLICK,
    SCROLL_CLICK,
    SCROLL_UP,
    SCROLL_DOWN,
    BUTTON_1,
    BUTTON_2,
  };

public:
  MouseButton();
  virtual ~MouseButton();
  MouseButton::MouseButtonType	stringToMouseButtonType(const std::string &);
  const std::string		MouseButtonTypeToString(const MouseButtonType &);
  const std::string		MouseVectorButtonTypeToString(const std::vector<MouseButton::MouseButtonType> &);

  std::vector<MouseButton::MouseButtonType>	getVectorOfClicks(const std::string &);

private:
  std::unordered_map<MouseButton::MouseButtonType, std::string>	_dbButtonPair;
};

#endif		/* !_MOUSE_BUTTON__HPP_! */