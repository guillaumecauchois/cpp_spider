#pragma once

#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include "Position.hpp"
#include "Device.hpp"

class Mouse : public Device
{
private:
	Position *_position;
	std::string 	 _buttonPressed;

public:
	Mouse();
	~Mouse();

	void PrintCurrentMousePosition(void);
	void CheckButtonDown(int key);
	void MouseInformation(void);
	void ClikInformation(void);
	void updatePosition(void);

	Position				getMousePosition(void) const;
	std::string				getButtonPressed(void) const;
	void					refreshButtonPressed();
};

