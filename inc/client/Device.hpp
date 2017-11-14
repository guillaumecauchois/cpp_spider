#include <iostream>
#include "Process.hpp"

#ifndef		_DEVICE__HPP_
#define		_DEVICE__HPP_

enum DeviceType
{
	KEYBOARD = 0,
	MOUSE,
};

class Device
{

protected:
	std::string _name;
	DeviceType	_type;
public:
	Device(std::string name, DeviceType);
	~Device();

	const std::string & getName(void) const;
	DeviceType getType(void) const;
};

#endif		/* !_DEVICE__HPP_! */

