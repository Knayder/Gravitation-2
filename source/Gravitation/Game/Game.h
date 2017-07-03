#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Entity\AstroObject.h"

class Game final {
public:
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	Game(sf::RenderWindow *window);
	void init();
private:
	sf::RenderWindow *window;
	bool ableToLeave;
	sf::Clock clock;
	sf::Clock consoleLogClock;
	float maxFps;
	float deltaTime;

	void eventHandler();
	void consoleLog();
};