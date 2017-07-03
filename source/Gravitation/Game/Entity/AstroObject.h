#include "Entity.h"

class AstroObject : public Entity, public sf::CircleShape {
public:
	AstroObject(const float &radius);
	virtual void update(const float &deltaTime) override;
private:
};

