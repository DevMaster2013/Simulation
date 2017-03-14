#include "GameResource.h"

sim::GameResource::GameResource(const std::string & name, const std::string& resourceFileName)
	: _name(name)
	, _resourceFileName(resourceFileName)
	, _isLoaded(false)
{
}

sim::GameResource::~GameResource()
{
}

bool sim::GameResource::load()
{
	std::ifstream fileStream(_resourceFileName);
	if (fileStream.good())
	{
		if (!onLoad(fileStream))
		{			
			fileStream.close();
			return false;
		}
	}
	_isLoaded = true;
	fileStream.close();
	return true;
}

bool sim::GameResource::save()
{
	std::ofstream fileStream(_resourceFileName);
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

void sim::GameResource::release()
{
	if (_isLoaded) 
	{
		onRelease();
		_isLoaded = false;
	}
}

const std::string & sim::GameResource::getName() const
{
	return _name;
}

const std::string & sim::GameResource::getResourceFileName() const
{
	return _resourceFileName;
}

bool sim::GameResource::isLoaded() const
{
	return _isLoaded;
}

void sim::GameResource::setName(const std::string & name)
{
	_name = name;
}

void sim::GameResource::setResourceFileName(const std::string & name)
{
	_resourceFileName = name;
}
