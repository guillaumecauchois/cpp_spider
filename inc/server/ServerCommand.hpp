/*
** ServerCommand.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/server/ServerCommand.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Oct 03 13:56:23 2017 Guillaume CAUCHOIS
** Last update Tue Oct 03 13:56:23 2017 Guillaume CAUCHOIS
*/

#ifndef		_SERVER_COMMAND__HPP_
# define	_SERVER_COMMAND__HPP_
# include <vector>
# include <unordered_map>
# include <functional>
# include "EventFactory.hpp"
# include "Log.hpp"

class ServerCommand
{
private:
  std::unordered_map<std::string, std::function<void(TcpConnection *)>> _commands;
public:
  ServerCommand();
  virtual ~ServerCommand();

  void executeCommand(const std::string &, TcpConnection *);

private:
  void	commandMousePosition(TcpConnection *);
  void	commandKeyPressed(TcpConnection *);
  void	commandStopConnection(TcpConnection *);
};

#endif		/* !_SERVER_COMMAND__HPP_! */