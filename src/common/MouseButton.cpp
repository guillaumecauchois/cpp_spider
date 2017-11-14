/*
** MouseButton.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/server/MouseButton.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Oct 02 11:26:30 2017 Guillaume CAUCHOIS
** Last update Mon Oct 02 11:26:30 2017 Guillaume CAUCHOIS
*/

#include <sstream>
#include "MouseButton.hpp"

MouseButton::MouseButton()
{
  this->_dbButtonPair[LEFT_CLICK] = "LEFT_CLICK";
  this->_dbButtonPair[RIGHT_CLICK] = "RIGHT_CLICK";
  this->_dbButtonPair[BUTTON_1] = "BUTTON_1";
  this->_dbButtonPair[BUTTON_2] = "BUTTON_2";
  this->_dbButtonPair[SCROLL_CLICK] = "SCROLL_CLICK";
  this->_dbButtonPair[SCROLL_UP] = "SCROLL_UP";
  this->_dbButtonPair[SCROLL_DOWN] = "SCROLL_DOWN";
}

MouseButton::~MouseButton() = default;

MouseButton::MouseButtonType	MouseButton::stringToMouseButtonType(
  const std::string &search)
{
  for (auto &item : this->_dbButtonPair)
  {
    if (item.second == search)
      return item.first;
  }
  return UNKNOWN_CLICK;
}

const std::string MouseButton::MouseButtonTypeToString(
  const MouseButtonType &buttonType)
{
  for (auto &item : this->_dbButtonPair)
  {
    if (item.first == buttonType)
      return item.second;
  }
  return "";
}


const std::string	MouseButton::MouseVectorButtonTypeToString(const std::vector<MouseButton::MouseButtonType> &vector)
{
  std::stringstream	ss;
  bool			first = true;

  for (auto &item : vector)
  {
    ((!first) ? (ss << " " << this->MouseButtonTypeToString(item)) : (ss << this->MouseButtonTypeToString(item)));
    first = false;
  }
  return (ss.str());
}

std::vector<MouseButton::MouseButtonType>	MouseButton::getVectorOfClicks(const std::string &line)
{
  std::vector<MouseButton::MouseButtonType>	vector;
  std::stringstream				ss;
  MouseButton		 			button;
  MouseButton::MouseButtonType			buttonType;

  ss.str(line);
  for (std::string item; std::getline(ss, item, ';');)
  {
    buttonType = button.stringToMouseButtonType(item);
    vector.emplace_back(buttonType);
  }
  return (vector);
}

