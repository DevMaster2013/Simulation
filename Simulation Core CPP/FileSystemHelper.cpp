#include "FileSystemHelper.h"
#include "StringHelper.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

std::vector<std::string> sim::FileSystemHelper::GetFilesInDirectory(const std::string & path, const std::string& pattern)
{
	std::vector<std::string> files;

	WIN32_FIND_DATAA findFileData;
	HANDLE fHandle = FindFirstFileA((path + "\\" + pattern).c_str(), &findFileData);
	bool found = fHandle != INVALID_HANDLE_VALUE;
	while (found)
	{
		files.push_back(path + "\\" + findFileData.cFileName);
		found = FindNextFileA(fHandle, &findFileData);
	}
	FindClose(fHandle);

	return files;
}

std::string sim::FileSystemHelper::GetFileNameWithoutPath(const std::string & filePath)
{	
	return StringHelper::Mid(filePath, filePath.find_last_of('\\') + 1);
}

std::string sim::FileSystemHelper::GetFileNameWithoutExtension(const std::string & filePath)
{
	auto fileName = GetFileNameWithoutPath(filePath);
	return StringHelper::Mid(fileName, 0, fileName.find('.') - 1);
}

std::string sim::FileSystemHelper::GetExtension(const std::string & filePath)
{	
	return StringHelper::Mid(filePath, filePath.find('.') + 1);
}
