#ifndef		_DEVICE_MANAGER__HPP_
# define	_DEVICE_MANAGER__HPP_
# include <iostream>
# include <vector>
# include "Device.hpp"
# include "Keyboard.hpp"
# include "Mouse.hpp"

class DeviceManager
{
  private:
    std::vector<Device*>		_devices;

  public:
    DeviceManager();
    ~DeviceManager();

    void					addDevice(DeviceType type);
    void					removeDevice(DeviceType type);
	std::vector<Device*>	getDevice(void) const;
};

#endif		_DEVICE_MANAGER__HPP_