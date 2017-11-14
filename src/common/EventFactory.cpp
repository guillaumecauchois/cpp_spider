/*
** EventFactory.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/common/EventFactory.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 12:50:04 2017 Guillaume CAUCHOIS
** Last update Fri Sep 29 12:50:04 2017 Guillaume CAUCHOIS
*/

#include "EventFactory.hpp"
#include <iostream>
#include <SpiderException.hpp>

EventFactory::EventFactory()
{
  this->_command[EventType::START_CONNECTION] = std::bind(
    &EventFactory::createEventStartConnection,
    this,
    std::placeholders::_1);
  this->_command[EventType::KEY_PRESSED] = std::bind(
    &EventFactory::createEventKeyPressed,
    this,
    std::placeholders::_1);
  this->_command[EventType::MOUSE_POSITION] = std::bind(
    &EventFactory::createEventMousePosition,
    this,
    std::placeholders::_1);
  this->_command[EventType::MOUSE_CLICK] = std::bind(
    &EventFactory::createEventMouseClick,
    this,
    std::placeholders::_1);
  this->_command[EventType::STOP_CONNECTION] = std::bind(
    &EventFactory::createEventStopConnection,
    this,
    std::placeholders::_1);
}

EventFactory::~EventFactory() = default;

std::vector<std::string>	EventFactory::parseInfoFromProtoc(const std::string &line)
{
  std::vector<std::string>	vector;
  std::vector<std::string>	tmp;
  std::stringstream		ss;
  int				i;

  ss.str(line);
  i = 0;
  for (std::string word; std::getline(ss, word, ' ');)
  {
    if (i == 4 &&
	(vector.front() == "KEY_PRESSED" || vector.front() == "MOUSE_BUTTON_PRESSED"))
    {
      for (std::string word2; std::getline(ss, word2, ' ');)
	word += " " + word2;
    }
    vector.emplace_back(word);
    i++;
  }
  return vector;
}

Event	*EventFactory::createEvent(const std::vector<std::string> &infos)
{
  EventType					type = UNKNOWN;
  std::unordered_map<EventType, std::string>	dbEvent;

  if (infos.size() < 2)
    return nullptr;
  dbEvent[EventType::START_CONNECTION]	= "START_CONNECTION";
  dbEvent[EventType::MOUSE_POSITION]	= "MOUSE_POSITION";
  dbEvent[EventType::MOUSE_CLICK]	= "MOUSE_BUTTON_PRESSED";
  dbEvent[EventType::KEY_PRESSED]	= "KEY_PRESSED";
  dbEvent[EventType::STOP_CONNECTION]	= "STOP_CONNECTION";

  for (auto &item : dbEvent)
  {
    if (item.second == infos.at(0))
      type = item.first;
  }
  if (type == UNKNOWN)
    return nullptr;
  for (auto &it : this->_command)
  {
    if (it.first == type)
      return this->_command[type](infos);
  }
  return nullptr;
}

Event	*EventFactory::createEventStartConnection(
  const std::vector<std::string> &infos)
{
  auto		*event = new Event();
  int		timestamp;

  if (infos.size() != 2)
    return nullptr;
  event->setType(EventType::START_CONNECTION);
  try
  {
    timestamp = std::stoi(infos.at(1));
    event->setTimestamp(timestamp);
  }
  catch (const std::exception &e)
  {
    return nullptr;
  }
  return event;
}

Event	*EventFactory::createEventKeyPressed(const std::vector<std::string> &infos)
{
  auto		*event = new Event();
  int		timestamp;
  int		pid;
  Process	process;

  if (infos.size() != 5)
    return nullptr;
  event->setType(EventType::KEY_PRESSED);
  try
  {
    timestamp = std::stoi(infos.at(1));
    event->setTimestamp(timestamp);
    pid = std::stoi(infos.at(2));
    process.setId(pid);
  }
  catch (const std::exception &e)
  {
    return nullptr;
  }
  process.setProcessusName(infos.at(3));
  event->setProcess(process);
  event->setBuffer(infos.at(4));
  return event;
}

Event	*EventFactory::createEventMousePosition(const std::vector<std::string> &infos)
{
  auto		*event = new Event();
  int		timestamp;
  Position	pos(0, 0);
  Process	process;

  if (infos.size() != 6)
    return nullptr;
  event->setType(EventType::MOUSE_POSITION);
  try
  {
    timestamp = std::stoi(infos.at(1));
    event->setTimestamp(timestamp);
    pos.setX(std::stoi(infos.at(2)));
    pos.setY(std::stoi(infos.at(3)));
    process.setId(std::stoi(infos.at(4)));
    process.setProcessusName(infos.at(5));
  }
  catch (const std::exception e)
  {
    return nullptr;
  }
  event->setProcess(process);
  event->setPosition(pos);
  return event;
}

Event	*EventFactory::createEventMouseClick(const std::vector<std::string> &infos)
{
  auto		*event = new Event();
  int		timestamp;
  int		pid;
  Process	process;
  MouseButton	button;

  if (infos.size() != 5)
    return nullptr;
  event->setType(EventType::MOUSE_CLICK);
  try
  {
    timestamp = std::stoi(infos.at(1));
    event->setTimestamp(timestamp);
    pid = std::stoi(infos.at(2));
    process.setId(pid);
  }
  catch (const std::exception &e)
  {
    return nullptr;
  }
  process.setProcessusName(infos.at(2));
  event->setProcess(process);
  event->setMouseButton(button.getVectorOfClicks(infos.at(4)));
  return event;
}

Event	*EventFactory::createEventStopConnection(const std::vector<std::string> &infos)
{
  auto		*event = new Event();
  int		timestamp;

  if (infos.size() != 2)
    return nullptr;
  event->setType(EventType::STOP_CONNECTION);
  try
  {
    timestamp = std::stoi(infos.at(1));
    event->setTimestamp(timestamp);
  }
  catch (const std::exception &e)
  {
    return nullptr;
  }
  return event;
}