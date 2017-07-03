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

void AstroObjectsManager::addObject()
{
}

void AstroObjectsManager::removeObject()
{
}

void AstroObjectsManager::update()
{
	AstroObjectsManager& instance = getInstance();
	std::size_t size = instance.container.size();
	for (int i = 0; i < size-1; i++) {
		AstroObject *main = instance.container[i];
		for (int j = i + 1; j < size; j++) {
			AstroObject *sub = instance.container[j];
			float force = (main->getMass() * sub->getMass()) / 
				std::pow(Math::distance(main->getPosition(), sub->getPosition()), 2);
			sf::Vector2f direction = Math::normalizedVector(Math::deltaVector(main->getPosition(), sub->getPosition()));
			main->accelerate(direction * (force / main->getMass()));
			sub->accelerate((-direction) * (force / sub->getMass()));
		}
	}
}

