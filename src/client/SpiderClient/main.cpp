#include "ClientCore.hpp"
#include "ServerInfo.hpp"
#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <string>

int main(int argc, char **argv)
{
	HWND Wind;

	Wind = GetConsoleWindow();
	ShowWindow(Wind, true);

	try
	{
		boost::asio::io_service		service;
		ClientCore core(service);

		ServerInfo			info("ServerInfo.txt");
		info.parseServerConfig();
		const std::string	ip = info.getIp();
		unsigned short		port = info.getPort();
		core.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port));
		service.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}