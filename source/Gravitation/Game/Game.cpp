#include "Game.h"

Game::Game() :
	ableToLeave(false),
	maxFps(60.f),
	deltaTime(0.f)

{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 0;
	settings.minorVersion = 1;
	window.create(sf::VideoMode(1280u, 720u), "Gravitation 2", sf::Style::Close | sf::Style::Titlebar, settings);

}

Game & Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::init() {
	Game &instance = getInstance();

	AstroObjectsManager::addObject(new AstroObject(50, 10000));
	while (instance.window.isOpen() && instance.ableToLeave == false) {
		if (!fpsChecker())
			continue;
		
		consoleLog();

		eventHandler();

		Physics::gravitation();
		AstroObjectsManager::update();

		//Draw
		instance.window.clear(sf::Color(37, 37, 48));
		AstroObjectsManager::draw();
		instance.window.display();
	}
}

void Game::eventHandler() {
	Game &instance = getInstance();
	sf::Event event;
	while (instance.window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			instance.window.close();
	}
}

void Game::consoleLog()
{
	Game &instance = getInstance();
	if (instance.consoleLogClock.getElapsedTime().asSeconds() >= 1.f) {
		instance.consoleLogClock.restart();
		system("cls");
		std::cout << "FPS: " << 1.f / instance.deltaTime << '\n';
	}
}

bool Game::fpsChecker(){
	Game &instance = getInstance();
	instance.deltaTime = instance.clock.getElapsedTime().asSeconds();
	if (instance.deltaTime < 1.f / instance.maxFps)
		return false;
	instance.clock.restart();
	return true;
}

float Game::getDeltaTime()
{
	return getInstance().deltaTime;
}

sf::RenderWindow & Game::getWindow()
{
	return getInstance().window;
}
