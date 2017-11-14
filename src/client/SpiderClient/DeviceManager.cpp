#include "DeviceManager.hpp"

DeviceManager::DeviceManager()
{

}

DeviceManager::~DeviceManager()
{

}

void	DeviceManager::addDevice(DeviceType type)
{
	bool exists = false;

	for (auto &search : this->_devices)
	{
		if (search->getType() == type)
			exists = true;
	}

	if (exists == false)
	{
		if (type == KEYBOARD)
			this->_devices.push_back(new Keyboard());
		else if (type == MOUSE)
			this->_devices.push_back(new Mouse());
	}
	else
		std::cerr << "This device is already created" << std::endl;
}

void	DeviceManager::removeDevice(DeviceType type)
{
}

std::vector<Device*> DeviceManager::getDevice(void) const
{
	return (this->_devices);
}
