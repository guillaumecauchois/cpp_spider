/*
** EventCreator.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/common/EventCreator.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Sep 29 12:45:14 2017 Guillaume CAUCHOIS
** Last update Sat Sep 30 15:51:48 2017 Pierre
*/

#ifndef		_EVENT_FACTORY__HPP_
# define	_EVENT_FACTORY__HPP_
# include <unordered_map>
# include <vector>
# include <string>
# include <functional>
# include "Event.hpp"
# include "EventType.hpp"
# include "TcpConnection.hpp"

class EventFactory
{
private:
  std::unordered_map<EventType,
    std::function<Event* (std::vector<std::string>)>>	_command;

public:
  EventFactory();
  virtual ~EventFactory();

  /* Parse Info Event */
  static std::vector<std::string>	parseInfoFromProtoc(const std::string &);

  /* Event */
  Event	*createEvent(const std::vector<std::string> &);
  Event	*createEventStartConnection(const std::vector<std::string> &);
  Event	*createEventMousePosition(const std::vector<std::string> &);
  Event	*createEventMouseClick(const std::vector<std::string> &);
  Event	*createEventKeyPressed(const std::vector<std::string> &);
  Event	*createEventStopConnection(const std::vector<std::string> &);
};

#endif		/* !_EVENT_FACTORY__HPP_! */
