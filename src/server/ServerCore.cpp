/*
** ServerCore.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/server/ServerCore.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Oct 03 16:54:43 2017 Guillaume CAUCHOIS
** Last update Tue Oct 03 16:54:43 2017 Guillaume CAUCHOIS
*/

#include "SpiderSession.hpp"
#include "ServerCore.hpp"

ServerCore::ServerCore(boost::asio::io_service& io_service, const boost::asio::ip::tcp::endpoint& endpoint) :
_acceptor(io_service, endpoint), _io_service(io_service)
{
  std::cout << "| ***** Welcome in Spider C++ Project ***** |" << std::endl;
  std::cout << "Contributors : ";
  std::cout << "Quentin BAUDET Guillaume CAUCHOIS Thomas FOSSAERT Robin GRATTEPANCHE ";
  std::cout << "Adrien WARIN Pierre STASZAK";
  std::cout << std::endl << "Waiting for connections ..." << std::endl;
  waitForConnection();
}

ServerCore::~ServerCore() {}

void	ServerCore::waitForConnection()
{
  connectorPtr	connector(new TcpConnection(this->_io_service));

  this->_acceptor.async_accept(connector->getSocket(),
			  boost::bind(&ServerCore::handleAccept, this,
				      boost::asio::placeholders::error,
				      connector)
  );
}

Log&	ServerCore::getLog()
{
  return this->_log;
}

void	ServerCore::handleAccept(const boost::system::error_code& error, connectorPtr &connector)
{
  if (!error)
  {
    SpiderSessionPtr session = SpiderSession::create(connector);
    waitForConnection();
  }
}