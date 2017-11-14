#include "ClientCommand.hpp"



ClientCommand::ClientCommand()
{
}


ClientCommand::~ClientCommand()
{
}

const std::string ClientCommand::commandStartConnection(int timestamp) const
{
	return ("START_CONNECTION " + std::to_string(timestamp) + "\n");
}

const std::string ClientCommand::commandSendKeyboardBuffer(int timestamp, const std::string& key, int pid, const std::string& process) const
{
	return ("KEY_PRESSED " + std::to_string(timestamp) + " " + std::to_string(pid) + " " + process + " " + key + "\n");
}

const std::string ClientCommand::commandSendMousePostion(int timestamp, int x, int y, int pid, const std::string& procName) const
{
	return ("MOUSE_POSITION " + std::to_string(timestamp) + " " + std::to_string(x) + " " + std::to_string(y) +  " " + std::to_string(pid) + " " + procName + "\n");
}

const std::string ClientCommand::commandSendMouseButtonPressed(int timestamp, std::string id, int pid, const std::string& procName) const
{
	if (id == "")
		id = "NONE";
	return ("MOUSE_BUTTON_PRESSED " + std::to_string(timestamp) + " " + std::to_string(pid) + " " + procName + " " + id + "\n");
}

const std::string ClientCommand::commandEndConnection(int timestamp) const
{
	return ("STOP_CONNECTION " + std::to_string(timestamp) + "\n");
}