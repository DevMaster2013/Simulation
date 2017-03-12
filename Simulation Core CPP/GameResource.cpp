#include "GameResource.h"

sim::GameResource::GameResource(const std::string & name)
	: _name(name)
{
}

sim::GameResource::~GameResource()
{
}

bool sim::GameResource::Load(const std::string & resourceFileName)
{
	std::ifstream fileStream(resourceFileName);
	if (fileStream.good())
	{
		if (!onLoad(fileStream))
		{			
			fileStream.close();
			return false;
		}
	}

	fileStream.close();
	return true;
}

bool sim::GameResource::Save(const std::string & resourceFileName)
{
	std::ofstream fileStream(resourceFileName);
	if (fileStream.good())
	{
		if (!onSave(fileStream))
		{
			fileStream.close();
			return false;
		}
	}

	fileStream.close();
	return true;
}

const std::string & sim::GameResource::GetName() const
{
	return _name;
}

void sim::GameResource::SetName(const std::string & name)
{
	_name = name;
}
