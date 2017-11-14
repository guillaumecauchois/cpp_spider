#ifdef		_WIN32
# include <Windows.h>
#endif

#include "Process.hpp"

Process::Process() {};
Process::~Process() {};

void Process::UpdateProcess()
{
#ifdef _WIN32
  char window[255];
	DWORD tmp;
	HWND hwnd = GetForegroundWindow();
	GetWindowText(hwnd, window, sizeof(window));
	this->_name = std::string(window);
	std::replace(this->_name.begin(), this->_name.end(), ' ', '_');
	std::replace(this->_name.begin(), this->_name.end(), '\n', '_');

	GetWindowThreadProcessId(hwnd, &(tmp));
	this->setId(tmp);
#endif
}

void Process::setProcessusName(const std::string &pname)
{
  this->_name = pname;
}

void Process::setId(const int &id)
{
  this->_id = id;
}

const std::string & Process::getProcessusName() const
{
  return (this->_name);
}

int Process::getId() const
{
  return (this->_id);
}