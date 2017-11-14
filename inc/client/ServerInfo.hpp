/*
** ServerInfo.hpp for cpp_spider in /home/pierre/Tek3/cpp/cpp_spider/inc/client
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Oct 07 14:57:12 2017 Pierre
** Last update Sat Oct 07 16:46:21 2017 Pierre
*/

#ifndef SERVER_INFO_HPP
#define SERVER_INFO_HPP

# include <iostream>
# include <fstream>
# include <string>

class ServerInfo
{
private:
  std::string	_filename;
  std::string	_ip;
  unsigned short	_port;

public:
  ServerInfo(std::string filename);
  virtual ~ServerInfo();

  void parseServerConfig();
  bool isIpCorrect(const std::string &ip);
  bool isPortCorrect(const std::string &port);

  const std::string& getFilename(void) const;
  const std::string& getIp(void) const;
  unsigned short getPort(void) const;

  void setFilename(const std::string &filename);
  void setIp(const std::string &ip);
  void setPort(const unsigned short &port);
};

#endif //SERVER_INFO_HPP
