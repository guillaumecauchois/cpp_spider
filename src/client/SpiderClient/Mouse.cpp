#include "Mouse.hpp"

Mouse::Mouse() : Device("Mouse", MOUSE)
{
	std::cout << "Mouse created" << std::endl;

	this->_position = new Position();
	this->_buttonPressed = "";
}

Mouse::~Mouse()
{
}

void Mouse::PrintCurrentMousePosition(void)
{
	std::cout << "Position x= " << this->_position->getX() << " Position y= " << this->_position->getY() << std::endl;
}

void Mouse::CheckButtonDown(int key)
{
	switch (key)
	{
		case VK_LBUTTON: this->_buttonPressed += "LEFT_CLICK;"; break;
		case VK_RBUTTON: this->_buttonPressed += "RIGHT_CLICK;"; break;
		case VK_MBUTTON: this->_buttonPressed += "SCROLL_CLICK;"; break;
	}
}

void Mouse::MouseInformation(void)
{
	this->updatePosition();
}

void Mouse::ClikInformation(void)
{
	int key = 0;

	for (key = 0; key <= 3; key++)
	{
		if (GetAsyncKeyState(key) == -32767)
			CheckButtonDown(key);
	}
}

void Mouse::updatePosition(void)
{
	POINT p;

	if (GetCursorPos(&p))
	{
		this->_position->setX(p.x);
		this->_position->setY(p.y);
	}
}

Position Mouse::getMousePosition(void) const
{
	return (*(this->_position));
}

std::string  Mouse::getButtonPressed(void) const
{
	return (this->_buttonPressed);
}

void Mouse::refreshButtonPressed()
{
	this->_buttonPressed = "";
}