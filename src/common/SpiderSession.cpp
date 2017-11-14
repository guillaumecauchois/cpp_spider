/*
** SpiderSession.cpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/src/common/SpiderSession.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Nov 02 15:14:29 2017 Guillaume CAUCHOIS
** Last update Thu Nov 02 15:14:29 2017 Guillaume CAUCHOIS
*/

#include "SpiderSession.hpp"
#include "ServerCore.hpp"

SpiderSession::SpiderSession(connectorPtr &connector) : _connector(connector)
{
}

SpiderSession::~SpiderSession()
{
}

void	SpiderSession::waitForData()
{
  this->_connector->async_read(this->_event,
			       boost::bind(&SpiderSession::handleRead, shared_from_this(),
					   boost::asio::placeholders::error)
  );
}

void	SpiderSession::handleRead(const boost::system::error_code &error)
{
  if (!error)
  {
    EventBeautifuler	eventBeautifuler;

    std::cout << eventBeautifuler.process(this->_event) << std::endl;
    this->waitForData();
  }
}

void SpiderSession::handleWrite(const boost::system::error_code &error) {}