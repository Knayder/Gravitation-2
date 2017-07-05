#pragma once
#include "Entity.h"

class AstroObject : public Entity {
public:
	AstroObject(const float &radius, const float &mass, const sf::Vector2f &position = {0.f,0.f}, const sf::Color &color = sf::Color::White);
	void update(const float &deltaTime) override;
	void accelerate(const sf::Vector2f &value);
	sf::Vector2f getVelocity() const;
	float getMass() const;
	void addForce(const sf::Vector2f &value);
private:
	float mass;
	sf::Vector2f velocity;
	sf::Vector2f force;

};

