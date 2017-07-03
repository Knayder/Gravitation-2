#include <SFML\Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
public:
	Entity(){}
	virtual void update(const float &) {}

};