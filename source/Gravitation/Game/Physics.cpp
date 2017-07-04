#include "Physics.h"

Physics::Physics()
{
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
			direction *= force;
			main->addForce(direction);
			sub->addForce(-direction);
		}
	}
}
