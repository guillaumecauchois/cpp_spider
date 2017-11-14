/*
** Log.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/server/Log.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Oct 02 12:07:42 2017 Guillaume CAUCHOIS
** Last update Mon Oct 02 12:07:42 2017 Guillaume CAUCHOIS
*/

#ifndef		_LOG__HPP_
# define	_LOG__HPP_

#include <vector>
#include "Event.hpp"
#include "FileManager.hpp"
#include "EventFactory.hpp"
#include "EventBeautifuler.hpp"

class Log
{
private:
  EventFactory		_eventFactory;
  std::vector<Event>	_events;
  FileManager		_fileManager;

public:
  Log();
  virtual ~Log();
  EventFactory		getEventFactory() const;
  std::vector<Event>	getEventLog() const;
  void			addEvent(const Event &);
};

#endif		/* !_LOG_HPP_! */