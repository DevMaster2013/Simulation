#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "SimTypes.h"
#include "GameResource.h"

namespace sim
{
	class SIMAPI ResourceManager
	{
		DECLARE_SINGLETON(ResourceManager)

	public:
		void addResource(const std::string& resName, GameResource* resource);	
		bool loadAllResources();
		void releaseAllResources();

	public:
		template<typename T> T* getResource(const std::string& resName);

	private:
		bool loadNamesResources(const std::string& baseDir);
		bool loadConfigFiles(const std::string& baseDir);
		GameResource* getResource(const std::string& resName);

	private:
		template<typename ResT> bool loadResourceList(const std::string& baseDir, const std::string& ext);

	private:
		StringMap<GameResource*> _gameResources;
	};

	template<typename T>
	inline T * ResourceManager::getResource(const std::string & resName)
	{
		auto resource = getResource(resName);
		if (resource == nullptr) return nullptr;
		return (T*)resource;
	}
	template<typename ResT>
	inline bool ResourceManager::loadResourceList(const std::string & baseDir, const std::string & ext)
	{
		auto fileList = FileSystemHelper::getFilesInDirectory(baseDir, ext);
		for each (auto& file in fileList)
		{
			auto resName = FileSystemHelper::getFileNameWithoutExtension(file);
			ResT* res = new ResT(resName, file);
			addResource(resName, res);
		}

		return true;
	}
}