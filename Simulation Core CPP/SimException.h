#pragma once

#include "DLLExportDefinitions.h"
#include <string>

namespace sim
{
	class SIMAPI SimException
	{
	public:
		SimException();
		SimException(const std::string& message);
		virtual ~SimException();

	public:
		const std::string& getMessage() const;

	protected:
		std::string _errMessage;
	};
}