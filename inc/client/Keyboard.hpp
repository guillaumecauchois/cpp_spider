
#ifndef		_KEYBOARD__HPP_
# define	_KEYBOARD__HPP_

#include <iostream>
#include <string>
#include <unordered_map>
#include "Device.hpp"

class Keyboard : public Device
{
	std::string								_typedKey;
	std::unordered_map<int, const char*>	_invisibleKey;
	std::unordered_map<int, const char*>	_normalKey;
	std::unordered_map<int, const char*>	_upperKey;
	std::unordered_map<int, const char*>	_altGrKey;
public:
	Keyboard();
	~Keyboard();

	void checkNormalInput(int);
	void captureKey(void);
	void captureOtherChar(int);
	void captureAltChar(int);
	void concatTypedKey(const std::string&y);
	void concatTypedKey(int);
	void refreshTypedKey(void);

	const std::string	&getKey(void) const;
};

#endif /* !_KEYBOARD__HPP_! */