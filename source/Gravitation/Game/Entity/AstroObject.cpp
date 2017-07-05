#include "AstroObject.h"

AstroObject::AstroObject(const float &radius, const float &mass, const sf::Vector2f &position, const sf::Color &color) : 
	Entity(radius),
	mass(mass)
{
	setPosition(position);
	setFillColor(color);
}

void AstroObject::update(const float & deltaTime){
	move(velocity*deltaTime);
	accelerate(force / mass);
	force = { 0.f, 0.f };
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


