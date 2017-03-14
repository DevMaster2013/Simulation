#include "RandomGenerator.h"
#include "Civilian.h"
#include "Civilization.h"
#include "ResourceManager.h"
#include "NamesFileResource.h"
#include <random>

sim::Civilian * sim::RandomGenerator::generateRandomCivilian(Civilization* civilization)
{
	CivilianSex randomSex = (CivilianSex)getRandomIndex(0, (size_t)CivilianSex::SexesCount);
	return generateRandomCivilian(civilization, randomSex);
}

sim::Civilian * sim::RandomGenerator::generateRandomCivilian(Civilization * civilization, CivilianSex sex)
{
	std::string randomName = getRandomCivilianName(sex);
	Civilian* civilian = new Civilian(civilization, randomName);
	civilian->setSex(sex);
	return civilian;
}

std::string sim::RandomGenerator::getRandomCivilianName(CivilianSex sex)
{
	std::string resName = sex == CivilianSex::Female? "FemaleNames" : "MaleNames";
	const auto& resource = ResourceManager::getInstance()->getResource<NamesFileResource>(resName);
	auto& namesList = resource->getNamesList();
	return namesList[getRandomIndex(0, namesList.size())];
}

size_t sim::RandomGenerator::getRandomIndex(size_t minIndex, size_t maxIndex)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<size_t> distribution(minIndex, maxIndex);
	return distribution(generator);
}

double sim::RandomGenerator::getRandomCivilianAge(double maxAge)
{
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, maxAge);
	return distribution(generator);
}
