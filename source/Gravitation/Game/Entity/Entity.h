#include <SFML\Graphics.hpp>

class Entity : public sf::CircleShape  {
public:
	Entity(const float &radius) : 
		sf::CircleShape(radius)
	{

	}
	virtual void update() = 0;

};