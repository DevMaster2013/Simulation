#include "ResourceManager.h"
#include "FileSystemHelper.h"
#include "NamesFileResource.h"
#include "ConfigFileResource.h"

void sim::ResourceManager::AddResource(const std::string& resName, sim::GameResource* resource)
{
	auto found = _gameResources.find(resName);
	if (found == _gameResources.end())
		_gameResources[resName] = resource;
}

bool sim::ResourceManager::LoadAllResources()
{
	const std::string resourcesPath = R"(..\Data\)";

	// Load configuration files
	if (!loadConfigFiles(resourcesPath + "Config"))
		return false;

	// Load names files
	if (!loadNamesResources(resourcesPath + "Names"))
		return false;

	return true;
}

void sim::ResourceManager::ReleaseAllResources()
{
	for each (auto& res in _gameResources)
	{
		res.second->Release();
		delete res.second;
	}
}

bool sim::ResourceManager::loadNamesResources(const std::string & baseDir)
{
	return loadResourceList<NamesFileResource>(baseDir, "*.sim");
}

bool sim::ResourceManager::loadConfigFiles(const std::string & baseDir)
{
	return loadResourceList<ConfigFileResource>(baseDir, "*.ini");
}

sim::GameResource * sim::ResourceManager::getResource(const std::string & resName)
{
	auto found = _gameResources.find(resName);
	if (found == _gameResources.end())
		return nullptr;

	GameResource* res = found->second;
	if (!res->IsLoaded())
		res->Load();

	return res;
}
