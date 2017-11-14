/*
** ServerInfo.cpp for cpp_spider in /home/pierre/Tek3/cpp/cpp_spider/src/client/SpiderClient
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Oct 07 15:06:49 2017 Pierre
** Last update Sat Oct 07 17:06:02 2017 Pierre
*/

# include "ServerInfo.hpp"
#include <Ws2tcpip.h>
#include "SpiderException.hpp"


ServerInfo::ServerInfo(std::string filename)
{
  _filename = filename;
}

ServerInfo::~ServerInfo()
{
}

const std::string& ServerInfo::getFilename(void) const
{
  return (_filename);
}

const std::string& ServerInfo::getIp(void) const
{
  return (_ip);
}

unsigned short ServerInfo::getPort(void) const
{
  return (_port);
}

void ServerInfo::setFilename(const std::string &filename)
{
  _filename = filename;
}

void ServerInfo::setIp(const std::string &ip)
{
  _ip = ip;
}

void ServerInfo::setPort(const unsigned short &port)
{
  _port = port;
}

bool ServerInfo::isIpCorrect(const std::string &ip)
{
  struct sockaddr_in sa;
  return (InetPton(AF_INET, ip.c_str(), &(sa.sin_addr)) != 0);
}

bool ServerInfo::isPortCorrect(const std::string &port)
{
  if (port.find_first_not_of("0123456789") != std::string::npos)
    return (false);
  int tmp = std::stoi(port, nullptr, 10);
  return (tmp >= 1000 && tmp <= 9999);
}

void ServerInfo::parseServerConfig()
{
  std::ifstream file(_filename);
  if (!file){
	  throw SpiderException("SERVER INFO ERROR : bad file\n");
    return ;
  }
  std::string tmp;
  std::string content;
  while (std::getline(file, tmp)){
    content += tmp;
  }
  std::size_t ip_pos = content.find("ip:", 0);
  std::size_t port_pos = content.find("port:", 0);
  if (ip_pos == std::string::npos || port_pos == std::string::npos){
	  throw SpiderException("SERVER INFO ERROR : incomplete file\n");
    return ;
  }
  std::string ip = content.substr(content.find("ip:") + 3, content.find("port:") - 3);
  std::string port = content.substr(content.find("port:") + 5);
  if (!isIpCorrect(ip)){
	  throw SpiderException("SERVER INFO ERROR : incorrect ip address format\n");
    return ;
  }
  if (!isPortCorrect(port)){
	  throw SpiderException("SERVER INFO ERROR : incorrect port format\n");
    return ;
  }
  setIp(ip);
  setPort(std::stoi(port));
}
