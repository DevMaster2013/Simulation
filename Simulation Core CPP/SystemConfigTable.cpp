#include "SystemConfigTable.h"

sim::SystemConfigTable::SystemConfigTable()
{
}

sim::SystemConfigTable::~SystemConfigTable()
{
}

std::string sim::SystemConfigTable::GetStringValue(const std::string & valueName)
{
	auto found = _configEntries.find(valueName);
	if (found != _configEntries.end())
		return found->second;

	return "";
}

void sim::SystemConfigTable::SetStringValue(const std::string & valueName, const std::string & value)
{
	_configEntries[valueName] = value;
}

const sim::StringMap<std::string>& sim::SystemConfigTable::GetValueMap() const
{
	return _configEntries;
}
