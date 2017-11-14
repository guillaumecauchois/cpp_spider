/*
** EventType.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/server/EventType.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Sep 28 13:45:04 2017 Guillaume CAUCHOIS
** Last update Thu Sep 28 13:45:04 2017 Guillaume CAUCHOIS
*/

#ifndef		_EVENT_TYPE__HPP_
# define	_EVENT_TYPE__HPP_

typedef enum	e_EventType
{
  UNKNOWN = -1,
  START_CONNECTION = 0,
  MOUSE_POSITION = 1,
  MOUSE_CLICK,
  KEY_PRESSED,
  STOP_CONNECTION
}		EventType;

#endif		/* !_EVENT_TYPE__HPP_! */