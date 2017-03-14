#pragma once

#include "DLLExportDefinitions.h"
#include "Civilian.h"
#include "Civilization.h"
#include <cstdlib>

namespace sim
{
	class SIMAPI RandomGenerator
	{
	public:
		static Civilian* generateRandomCivilian(Civilization* civilization);
		static Civilian* generateRandomCivilian(Civilization* civilization, CivilianSex sex);
		static std::string getRandomCivilianName(CivilianSex sex);
		static size_t getRandomIndex(size_t minIndex = 0, size_t maxIndex = SIZE_MAX);
		static double getRandomCivilianAge(double maxAge);
	};
}