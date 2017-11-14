/*
** mIOService.cpp for cpp_spider in cpp_spider/src/common/mIOService.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Oct 06 07:46:19 2017 Guillaume CAUCHOIS
** Last update Fri Oct 06 07:46:19 2017 Guillaume CAUCHOIS
*/

#include "mIoService.hpp"

mIoService::mIoService()
{
  this->_service = boost::shared_ptr<boost::asio::io_service>(new boost::asio::io_service);
}

mIoService::~mIoService() = default;

mIoService::mIoService(const mIoService &obj) : _service(obj._service) {}

boost::asio::io_service& mIoService::getService()
{
  return *this->_service;
}

void mIoService::runService()
{
  this->_service->run();
}