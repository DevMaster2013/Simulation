#include "NamesFileResource.h"

sim::NamesFileResource::NamesFileResource(const std::string & name, const std::string & resourceFileName)
	: GameResource(name, resourceFileName)
{
}

sim::NamesFileResource::~NamesFileResource()
{
}

bool sim::NamesFileResource::onLoad(std::ifstream & fileStream)
{
	_namesList.clear();
	std::string line;
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		_namesList.push_back(line);
	}

	return true;
}

bool sim::NamesFileResource::onSave(std::ofstream & fileStream)
{
	for each (auto& name in _namesList)
	{
		fileStream << name << std::endl;
	}
	return true;
}

void sim::NamesFileResource::onRelease()
{
	_namesList.clear();
}

void sim::NamesFileResource::AddName(const std::string & name)
{
	auto found = std::find(_namesList.begin(), _namesList.end(), name);
	if (found != _namesList.end())
		return;
	_namesList.push_back(name);
}

void sim::NamesFileResource::RemoveName(const std::string & name)
{
	auto found = std::find(_namesList.begin(), _namesList.end(), name);
	if (found != _namesList.end())
		_namesList.erase(found);
}

const std::vector<std::string>& sim::NamesFileResource::GetNamesList() const
{
	return _namesList;
}
