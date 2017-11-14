/*
** Event.cpp for cpp_spider in ./src/server/Event.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Sep 28 08:50:39 2017 Guillaume CAUCHOIS
** Last update Thu Sep 28 08:50:39 2017 Guillaume CAUCHOIS
*/

#include <sstream>
#include "Event.hpp"

Event::Event(const Event &event) : _position(event.getPosition().getX(),
					     event.getPosition().getY())
{
  this->_buffer = event.getBuffer();
  this->_process = event.getProcess();
  this->_timestamp = event.getTimestamp();
  this->_type = event.getType();
  this->_button = event.getMouseButton();
}

Event::Event(int timestamp, const Process &process, const Position &pos) :
	_type(EventType::MOUSE_POSITION),
	_process(process),
	_timestamp(timestamp),
	_position(pos) {}

Event::Event(int timestamp, const Process &process, const std::vector<MouseButton::MouseButtonType> &buttons) :
	_type(EventType::MOUSE_CLICK),
	_timestamp(timestamp),
	_process(process),
	_button(buttons) {}

Event::Event(int timestamp, const Process &process, const std::string &buffer) :
	_type(EventType::KEY_PRESSED),
	_timestamp(timestamp),
	_process(process),
	_buffer(buffer)
{}



const std::string	&Event::getBuffer() const
{
  return this->_buffer;
}

void		Event::setBuffer(const std::string &buffer)
{
  this->_buffer = buffer;
}

Position	Event::getPosition() const
{
  return this->_position;
}

void		Event::setPosition(const Position &pos)
{
  this->_position = pos;
}

Process		Event::getProcess() const
{
  return this->_process;
}

void		Event::setProcess(const Process &proc)
{
  this->_process = proc;
}

int		Event::getTimestamp() const
{
  return this->_timestamp;
}

void		Event::setTimestamp(const int &ts)
{
  this->_timestamp = ts;
}

EventType	Event::getType() const
{
  return this->_type;
}

void		Event::setType(const EventType &type)
{
  this->_type = type;
}

std::vector<MouseButton::MouseButtonType>	Event::getMouseButton() const
{
  return this->_button;
}

void		Event::setMouseButton(const std::vector<MouseButton::MouseButtonType> &mb)
{
  this->_button = mb;
}