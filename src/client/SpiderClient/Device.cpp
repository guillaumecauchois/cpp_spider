#include "Device.hpp"

Device::Device(std::string name, DeviceType type)
{
	this->_name = name;
	this->_type = type;
}

Device::~Device()
{
}

const std::string & Device::getName(void) const
{
	return (this->_name);
}

DeviceType Device::getType(void) const
{
	return (this->_type);
}