#include "AstroObject.h"

AstroObject::AstroObject(const float &radius) : 
	Entity(),
	sf::CircleShape(radius)
{
	
}

void AstroObject::update(const float & deltaTime)
{
}
