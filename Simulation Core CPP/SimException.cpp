#include "SimException.h"

sim::SimException::SimException()
	: _errMessage("Undefined Error")
{
}

sim::SimException::SimException(const std::string & message)
	: _errMessage(message)
{
}

sim::SimException::~SimException()
{
}

const std::string& sim::SimException::GetMessage() const
{
	return _errMessage;
}
