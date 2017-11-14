/*
** Log.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/server/Log.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Oct 02 12:46:36 2017 Guillaume CAUCHOIS
** Last update Mon Oct 02 12:46:36 2017 Guillaume CAUCHOIS
*/

#include <iostream>
#include "Log.hpp"

Log::Log() : _fileManager("log.txt") {}

Log::~Log() = default;

EventFactory	Log::getEventFactory() const
{
  return this->_eventFactory;
}

std::vector<Event>	Log::getEventLog() const
{
  return this->_events;
}

void	Log::addEvent(const Event &event)
{
  EventBeautifuler	beautifuler;
  const std::string	bEvent = beautifuler.process(event);

  this->_events.push_back(event);
  this->_fileManager.writeFile(bEvent);
  std::cout << bEvent;
}