#ifndef		_CLIENT_CORE__HPP_
# define	_CLIENT_CORE__HPP_
# include <boost/asio.hpp>
# include "TcpConnection.hpp"
# include <chrono>
# include <ctime>
# include "DeviceManager.hpp"
# include "ClientCommand.hpp"
# include "SerializeHandler.hpp"

class ClientCore
{
private:
  DeviceManager				_deviceManager;
  Process					_process;
  int						_timestamp;
  boost::asio::io_service	&_service;
  std::string				_ip;
  unsigned short			_port;

public:
  ClientCore(boost::asio::io_service &);
  ~ClientCore();

  void	connect(boost::asio::ip::tcp::endpoint &endpoint);
  void	process(TcpConnection::SocketPtr &connector);
  void	UpdateTimeStamp(void);
  void	UpdateCurrentProcess(void);

private:
  void	handleConnect(TcpConnection::SocketPtr, const boost::system::error_code &);
  void	handleWrite(const boost::system::error_code &);

};

#endif		/* !_CLIENT_CORE__HPP_! */