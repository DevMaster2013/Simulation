#include "FileSystemHelper.h"
#include "StringHelper.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

std::vector<std::string> sim::FileSystemHelper::getFilesInDirectory(const std::string & path, const std::string& pattern)
{
	std::vector<std::string> files;

	WIN32_FIND_DATAA findFileData;
	HANDLE fHandle = FindFirstFileA((path + "\\" + pattern).c_str(), &findFileData);
	BOOL found = fHandle != INVALID_HANDLE_VALUE;
	while (found)
	{
		files.push_back(path + "\\" + findFileData.cFileName);
		found = FindNextFileA(fHandle, &findFileData);
	}
	FindClose(fHandle);

	return files;
}

std::string sim::FileSystemHelper::getFileNameWithoutPath(const std::string & filePath)
{	
	return StringHelper::mid(filePath, filePath.find_last_of('\\') + 1);
}

std::string sim::FileSystemHelper::getFileNameWithoutExtension(const std::string & filePath)
{
	auto fileName = getFileNameWithoutPath(filePath);
	return StringHelper::mid(fileName, 0, fileName.find('.') - 1);
}

std::string sim::FileSystemHelper::getExtension(const std::string & filePath)
{	
	return StringHelper::mid(filePath, filePath.find('.') + 1);
}
