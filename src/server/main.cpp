/*
** main.cpp for cpp_spider in ./src/server/main.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Sep 28 09:00:21 2017 Guillaume CAUCHOIS
** Last update Thu Sep 28 09:00:21 2017 Guillaume CAUCHOIS
*/

#include "ServerCore.hpp"
#include <iostream>

unsigned short	getPort(char **argv)
{
  unsigned short	port = 0;
  try
  {
    port = static_cast<unsigned short>(std::stoi(argv[1]));
  }
  catch (const std::exception &e)
  {
    return (0);
  }
  return (port);
}

int		main(int argc, char **argv)
{
  unsigned short		port;
  boost::asio::io_service	service;

  if (argc != 2 || !(port = getPort(argv)))
  {
    std::cerr << "Error: Please specify a valid port as param" << std::endl;
    return 1;
  }
  try
  {
    ServerCore	core(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), port));
    service.run();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}