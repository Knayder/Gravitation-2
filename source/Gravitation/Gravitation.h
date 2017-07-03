#include <SFML\Graphics.hpp>
#include "Game\Game.h"


class Gravitation final {
public:
	//Delete useless constructors.
	Gravitation(const Gravitation &) = delete;
	void operator=(const Gravitation &) = delete;

	Gravitation(const sf::Vector2u &windowSize);
	void init();
private:
	sf::RenderWindow window;
	sf::ContextSettings settings;
	sf::Vector2u windowSize;
};