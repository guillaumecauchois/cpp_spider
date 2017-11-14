/*
** ServerCore.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/server/ServerCore.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Oct 03 12:15:59 2017 Guillaume CAUCHOIS
** Last update Tue Oct 03 12:15:59 2017 Guillaume CAUCHOIS
*/

#ifndef		_SERVER_CORE__HPP_
# define	_SERVER_CORE__HPP_
# include "Log.hpp"

class ServerCore
{
private:
  Log					_log;
  boost::asio::io_service&		_io_service;
  boost::asio::ip::tcp::acceptor	_acceptor;

public:
  ServerCore(boost::asio::io_service &, const boost::asio::ip::tcp::endpoint &);
  virtual ~ServerCore();

  void	waitForConnection();
  void	handleAccept(const boost::system::error_code&, connectorPtr &);
  Log	&getLog();
};

#endif		/* !_SERVER_CORE__HPP_! */