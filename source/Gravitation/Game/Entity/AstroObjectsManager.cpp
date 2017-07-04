#include "AstroObjectsManager.h"

AstroObjectsManager::~AstroObjectsManager()
{
	for (auto it : container)
		delete it;
}

AstroObjectsManager::AstroObjectsManager()
{
}


AstroObjectsManager & AstroObjectsManager::getInstance()
{
	static AstroObjectsManager instance;
	return instance;
}

AstroObject * AstroObjectsManager::addObject(AstroObject *obj)
{
	if (obj != nullptr)
		getInstance().container.push_back(obj);
	return obj;
}
 
bool AstroObjectsManager::removeObject(const unsigned int &index){
	AstroObjectsContainer &container = getInstance().container;
	if (index >= container.size())
		return false;
	container.erase(container.begin() + index);
	return true;
}

bool AstroObjectsManager::removeObject(const AstroObject *target) {
	AstroObjectsContainer &container = getInstance().container;
	auto toDelete = std::find(container.begin(), container.end(), target);
	if (toDelete == container.end())
		return false;
	container.erase(toDelete);
	return true;
}

void AstroObjectsManager::clear() {
	AstroObjectsContainer &container = getInstance().container;
	container.clear();
	for (auto it : container)
		delete it;
}

void AstroObjectsManager::update()
{
	
}

