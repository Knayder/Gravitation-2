#include "Physics.h"

Physics::Physics() :
	additionalSpeed(10)
{
}

Physics & Physics::getInstance()
{
	static Physics instance;
	return instance;
}

void Physics::gravitation(){
	AstroObjectsManager& instance = AstroObjectsManager::getInstance();
	std::size_t size = instance.container.size();
	for (int i = 0; i < size - 1; i++) {
		AstroObject *main = instance.container[i];
		for (int j = i + 1; j < size; j++) {
			AstroObject *sub = instance.container[j];
			float force = (main->getMass() * sub->getMass()) /
				std::pow(Math::distance(main->getPosition(), sub->getPosition()), 2);
			sf::Vector2f direction = Math::normalizedVector(Math::deltaVector(main->getPosition(), sub->getPosition()));
			direction *= force * getInstance().additionalSpeed;
			main->addForce(direction);
			sub->addForce(-direction);
		}
	}
}

void Physics::collisions()
{
	//TODO: DO THIS XD
}
