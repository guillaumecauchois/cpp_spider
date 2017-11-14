#ifndef		_TCP_CONNECTION__HPP_
# define	_TCP_CONNECTION__HPP_
# include	<iostream>
# include	<boost/asio.hpp>
# include	<boost/array.hpp>
# include	<boost/tuple/tuple.hpp>
# include	<boost/bind.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<numeric>
# include	"SerializeHandler.hpp"

class TcpConnection
{
public:
  typedef boost::shared_ptr<TcpConnection> SocketPtr;

private:
  enum { header_length = 2 };
  boost::asio::ip::tcp::socket		_socket;
  std::string				_outbound_header;
  std::string				_outbound_data;
  char					_inbound_header[header_length];
  std::vector<char>			_inbound_data;

public:
  /* Constructor and destructors */
  TcpConnection(boost::asio::io_service &service) : _socket(service)
  {}

  ~TcpConnection() {}

  /**
  * Get Socket
  * @return : boost socket
  */
  boost::asio::ip::tcp::socket	&getSocket()
  {
    return (this->_socket);
  }

  /**
  * async_write encapsulation
  *
  * @tparam: T - The data structure to be write on socket
  * @tparam: Handler - The handle function will be called at end of async_write
  * @return: void (a callback is call)
  */
  template <typename T, typename Handler>
  void	async_write(const T& t, Handler handler)
  {
    this->_outbound_data = SerializeHandler::serializeObj(t);

    std::ostringstream				header_stream;
    header_stream << std::setw(header_length) << std::hex << this->_outbound_data.size();
    if (!header_stream || header_stream.str().size() != header_length)
    {
      boost::system::error_code		error(boost::asio::error::invalid_argument);
      this->_socket.get_io_service().post(boost::bind(handler, error));
      return;
    }
    this->_outbound_header = header_stream.str();
    std::vector<boost::asio::const_buffer>	buffers;
    buffers.push_back(boost::asio::buffer(this->_outbound_header));
    buffers.push_back(boost::asio::buffer(this->_outbound_data));
    boost::asio::async_write(_socket, buffers, handler);
  }

  /**
  * async_read encapsulation
  *
  * @tparam: T - The data structure to be bind from socket protoc
  * @tparam: Handler - The handle function will be called at end of async_read
  * @return: void (a callback is call)
  */
  template <typename T, typename Handler>
  void	async_read(T& t, Handler handler)
  {
    void (TcpConnection::*f)(const boost::system::error_code&, T&, boost::tuple<Handler>) = &TcpConnection::handle_read_header<T, Handler>;
    boost::asio::async_read(this->_socket, boost::asio::buffer(this->_inbound_header),
			    boost::bind(f,
					this,
					boost::asio::placeholders::error,
					boost::ref(t),
					boost::make_tuple(handler)
			    ));
  }

  /**
  * Header Handler
  *
  * @param: e - The errorcode
  * @tparam: T - The data structure to be bind
  * @tparam: Handler - The Handler function will be called at end of async_read
  * @return: void (a callback is call)
  */
  template <typename T, typename Handler>
  void	handle_read_header(const boost::system::error_code& e, T& t, boost::tuple<Handler> handler)
  {
    if (e)
      boost::get<0>(handler)(e);
    else
    {
      std::istringstream		is(std::string(this->_inbound_header, header_length));
      std::size_t			inbound_datasize = 0;

      if (!(is >> std::hex >> inbound_datasize))
      {
	boost::system::error_code	error(boost::asio::error::invalid_argument);
	boost::get<0>(handler)(error);
	return;
      }
      this->_inbound_data.resize(inbound_datasize);
      void (TcpConnection::*f)(const boost::system::error_code&, T&, boost::tuple<Handler>) = &TcpConnection::handleReadData<T, Handler>;

      boost::asio::async_read(this->_socket,
			      boost::asio::buffer(this->_inbound_data),
			      boost::bind(f, this,
					  boost::asio::placeholders::error, boost::ref(t), handler));
    }
  }

  /**
  * Data Read Handler
  *
  * @param: e - Error code
  * @tparam: T - The data structure to be bind
  * @tparam: Handler - The Handler function will be called at end of async_read
  * @return: void (a callback is call)
  */
  template <typename T, typename Handler>
  void	handleReadData(const boost::system::error_code& e, T& t, boost::tuple<Handler> handler)
  {
    if (e)
      boost::get<0>(handler)(e);
    else
    {
      try
      {
	std::string	data(std::string(this->_inbound_data.begin(), this->_inbound_data.end()));
	SerializeHandler::deserialize(t, data);
      }
      catch (std::exception& e)
      {
	std::cerr << e.what() << std::endl;
	boost::system::error_code error(boost::asio::error::invalid_argument);
	boost::get<0>(handler)(error);
	return;
      }
      boost::get<0>(handler)(e);
    }
  }
};

typedef boost::shared_ptr<TcpConnection> connectorPtr;

#endif		/* !_TCP_CONNECTION__HPP_! */