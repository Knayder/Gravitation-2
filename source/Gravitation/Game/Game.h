#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Entity\AstroObject.h"
#include "Entity\AstroObjectsManager.h"
#include "Physics.h"
#include "Windows\Window.h"

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
	sf::View view;

	bool ableToLeave;
	sf::Clock clock;
	float maxFps;
	float deltaTime;

	static void eventHandler();
	static void consoleLog();
	static bool fpsChecker();
	static void followCursorWithView();
	
};