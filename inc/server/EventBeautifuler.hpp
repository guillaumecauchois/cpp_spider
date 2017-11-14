/*
** EventBeautifuler.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/server/EventBeautifuler.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Oct 02 14:37:07 2017 Guillaume CAUCHOIS
** Last update Mon Oct 02 14:37:07 2017 Guillaume CAUCHOIS
*/

#ifndef		_EVENT_BEAUTIFULER__HPP_
# define	_EVENT_BEAUTIFULER__HPP_
# include <map>
# include <functional>
# include <string>
# include <sstream>
# include <iostream>
# include "Event.hpp"
# include "EventType.hpp"

class EventBeautifuler
{
private:
  std::map<EventType, std::function<const std::string (Event)>>	_beautifuler;
public:
  EventBeautifuler();
  virtual ~EventBeautifuler();

  const std::string	process(const Event &event);

private:
  const std::string	eventBeautifulerStartConnection(const Event &event) const;
  const std::string	eventBeautifulerKeyPressed(const Event &event) const;
  const std::string	eventBeautifulerMousePosition(const Event &event) const;
  const std::string	eventBeautifulerMouseClick(const Event &event) const;
  const std::string	eventBeautifulerStopConnection(const Event &event) const;
};

#endif		/* !_EVENT_BEAUTIFULER__HPP_! */