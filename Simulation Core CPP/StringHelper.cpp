#include "StringHelper.h"
#include <algorithm>

std::string sim::StringHelper::trim(const std::string & value)
{
	std::string trimmed(value);
	auto toBeTrimmed = std::find_if(trimmed.begin(), trimmed.end(), [](char ch) {return ch == ' '; });
	trimmed.erase(toBeTrimmed);
	return trimmed;
}

std::string sim::StringHelper::mid(const std::string & value, size_t start, size_t end)
{
	return value.substr(start, (end - start) + 1);
}
