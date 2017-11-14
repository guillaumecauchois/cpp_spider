/*
** Event.hpp for cpp_spider in ./inc/server/Event.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Sep 28 08:51:27 2017 Guillaume CAUCHOIS
** Last update Thu Sep 28 08:51:27 2017 Guillaume CAUCHOIS
*/

#ifndef		_EVENT__HPP_
# define	_EVENT__HPP_
# include "Position.hpp"
# include "EventType.hpp"
# include "Process.hpp"
# include "MouseButton.hpp"

class TcpConnection;

class Event
{
private:
  std::vector<MouseButton::MouseButtonType>	_button;
  Position									_position;
  std::string								_buffer;
  EventType									_type = EventType::UNKNOWN;
  Process									_process;
  int										_timestamp = 0;

public:
  Event() = default;
  Event(int, const Process &, const Position &);
  Event(int, const Process &, const std::vector<MouseButton::MouseButtonType> &);
  Event(int, const Process &, const std::string &);
  ~Event() = default;
  Event(const Event &);

  Position					getPosition() const;
  void						setPosition(const Position &);
  const std::string			&getBuffer() const;
  void						setBuffer(const std::string &);
  EventType					getType() const;
  void						setType(const EventType &);
  Process					getProcess() const;
  void						setProcess(const Process &);
  int						getTimestamp() const;
  void						setTimestamp(const int &);
  std::vector<MouseButton::MouseButtonType>	getMouseButton() const;
  void						setMouseButton(const std::vector<MouseButton::MouseButtonType> &);

  template <class Archive>
  void	serialize(Archive& ar, const unsigned int version)
  {
    ar & _button;
    ar & _position;
    ar & _buffer;
    ar & _type;
    ar & _process;
    ar & _timestamp;
  }
};

#endif		/* !_EVENT__HPP_! */