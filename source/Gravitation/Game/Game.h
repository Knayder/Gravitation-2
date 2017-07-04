#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Entity\AstroObject.h"
#include "Entity\AstroObjectsManager.h"
#include "Physics.h"

class Game final {
public:
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	
	static void init();
	static float getDeltaTime();
	static sf::RenderWindow &getWindow();
private:
	Game();
	static Game &getInstance();

	sf::RenderWindow window;

	bool ableToLeave;
	sf::Clock clock;
	sf::Clock consoleLogClock;
	float maxFps;
	float deltaTime;

	static void eventHandler();
	static void consoleLog();
	static bool fpsChecker();

	
};