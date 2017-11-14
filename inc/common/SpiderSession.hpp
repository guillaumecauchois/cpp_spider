/*
** SpiderSession.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/common/SpiderSession.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Nov 02 14:57:29 2017 Guillaume CAUCHOIS
** Last update Thu Nov 02 14:57:29 2017 Guillaume CAUCHOIS
*/

#ifndef		_SPIDER_SESSION__HPP_
# define	_SPIDER_SESSION__HPP_
# include <boost/enable_shared_from_this.hpp>
# include <boost/shared_ptr.hpp>
# include "TcpConnection.hpp"
# include "Event.hpp"

class SpiderSession;

typedef boost::shared_ptr<SpiderSession>	SpiderSessionPtr;

class SpiderSession : public boost::enable_shared_from_this<SpiderSession>
{
public:
  ~SpiderSession();

  static SpiderSessionPtr	create(connectorPtr connector)
  {
    SpiderSessionPtr session (new SpiderSession(connector));

    session->waitForData();
    return session;
  }

  template <class T>
  void	send(const T& obj)
  {
    this->_connector->async_write(obj,
				  boost::bind(&SpiderSession::handleWrite, shared_from_this(),
					      boost::asio::placeholders::error)
    );
  }

private:
  SpiderSession(connectorPtr &connector);
  void	waitForData();

  void	handleWrite(const boost::system::error_code& error);
  void	handleRead(const boost::system::error_code& error);

  connectorPtr			_connector;
  Event				_event;
};

#endif		/* !_SPIDER_SESSION__HPP_! */