/*
** ServerCallback.cpp for cpp_spider in cpp_spider/src/server/ServerCallback.cpp
**
** Made by Adrien WARIN
** Login   <adrien.warin@epitech.eu>
**
** Started on  Mon Oct 02 12:01:14 2017 Adrien WARIN
** Last update Mon Oct 02 12:01:14 2017 Guillaume CAUCHOIS
*/

#include "ServerCommand.hpp"

ServerCommand::ServerCommand()
{
  this->_commands["KEY_PRESSED"] = std::bind(
    &ServerCommand::commandKeyPressed,
    this,
    std::placeholders::_1
  );
  this->_commands["MOUSE_POSITION"] = std::bind(
    &ServerCommand::commandMousePosition,
    this,
    std::placeholders::_1
  );
  this->_commands["STOP_CONNECTION"] = std::bind(
    &ServerCommand::commandKeyPressed,
    this,
    std::placeholders::_1
  );
}

ServerCommand::~ServerCommand()
{

}

void ServerCommand::executeCommand(const std::string &commandName, TcpConnection *connector)
{
  for (auto &item : this->_commands)
  {
    if (item.first == commandName)
      this->_commands[commandName](connector);
  }
}

void	ServerCommand::commandMousePosition(TcpConnection *connector)
{
  connector->writeSocket("MOUSE_POSITION\n");
}

void	ServerCommand::commandKeyPressed(TcpConnection *connector)
{
  connector->writeSocket("KEY_PRESSED\n");
}

void ServerCommand::commandStopConnection(TcpConnection *connector)
{
  connector->writeSocket("STOP_CONNECTION\n");
}