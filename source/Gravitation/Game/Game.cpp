#include "Game.h"

Game::Game(sf::RenderWindow *window) :
	ableToLeave(false),
	maxFps(60.f),
	deltaTime(0.f)
{
	this->window = window;
}

void Game::init() {
	while (window->isOpen() && ableToLeave == false) {
		//Set max possible frames per second
		deltaTime = clock.getElapsedTime().asSeconds();
		if (deltaTime < 1.f / maxFps)
			continue;
		clock.restart();

		//consoleLog();

		eventHandler();

		//Draw
		window->clear(sf::Color(37, 37, 48));

		window->display();
	}
}

void Game::eventHandler() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::consoleLog()
{
	if (consoleLogClock.getElapsedTime().asSeconds() >= 1.f) {
		consoleLogClock.restart();
		system("cls");
		std::cout << "FPS: " << 1.f / deltaTime << '\n';
	}
}
