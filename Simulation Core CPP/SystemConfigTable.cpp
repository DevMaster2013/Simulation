#include "SystemConfigTable.h"

sim::SystemConfigTable::SystemConfigTable()
{
}

sim::SystemConfigTable::~SystemConfigTable()
{
}

std::string sim::SystemConfigTable::getStringValue(const std::string & valueName)
{
	auto found = _configEntries.find(valueName);
	if (found != _configEntries.end())
		return found->second;

	return "";
}

void sim::SystemConfigTable::setStringValue(const std::string & valueName, const std::string & value)
{
	_configEntries[valueName] = value;
}

const sim::StringMap<std::string>& sim::SystemConfigTable::getValueMap() const
{
	return _configEntries;
}
