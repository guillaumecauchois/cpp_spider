
#ifndef		_CLIENT_COMMAND__HPP_
# define	_CLIENT_COMMAND__HPP_
# include <iostream>
# include <string>

class ClientCommand
{
public:
	ClientCommand();
	~ClientCommand();

	const std::string commandStartConnection(int timestamp) const;
	const std::string commandSendKeyboardBuffer(int timestamp, const std::string& key, int pid, const std::string& process) const;
	const std::string commandSendMousePostion(int timestamp, int x, int y, int pid, const std::string& procName) const;
	const std::string commandSendMouseButtonPressed(int timestamp, std::string id, int pid, const std::string& procName) const;
	const std::string commandEndConnection(int timestamp) const;
};

#endif		/* !_CLIENT_COMMAND__HPP_! */