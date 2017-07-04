#include "AstroObject.h"

AstroObject::AstroObject(const float &radius, const float &mass) : 
	Entity(radius),
	mass(mass)
{

}

void AstroObject::update(const float & deltaTime){
	move(velocity * deltaTime);
}

void AstroObject::accelerate(const sf::Vector2f & value){
	velocity += value;
}

sf::Vector2f AstroObject::getVelocity() const
{
	return velocity;
}

float AstroObject::getMass() const
{
	return mass;
}

void AstroObject::addForce(const sf::Vector2f &value)
{
	force += value;
}


