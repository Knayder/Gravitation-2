#include "Gravitation.h"

Gravitation::Gravitation(const sf::Vector2u &windowSize) : 
	windowSize(windowSize)
{
	settings.antialiasingLevel = 8;
	settings.majorVersion = 0;
	settings.minorVersion = 1;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Gravitation 2", sf::Style::Close | sf::Style::Titlebar, settings);
}

void Gravitation::init(){
	Game game(&window);
	game.init();
}
