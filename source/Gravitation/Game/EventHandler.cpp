#include "EventHandler.h"


EventHandler::EventHandler() :
	space(false),
	mouseLeft(false),
	scrollDelta(0.f)
{

}

void EventHandler::getInput(){
	sf::Event event;
	sf::RenderWindow &window = Game::getWindow();
	EventHandler &instance = getInstance();

	while (window.pollEvent(event)) {
		
		if (event.type == sf::Event::Closed)
			window.close();

		else if (event.type == sf::Event::MouseWheelScrolled) {
			instance.scrollDelta = event.mouseWheelScroll.delta;
		}

		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space)
				instance.space = true;
		}

		else if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Space)
				instance.space = false;
		}

		else if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left)
				instance.mouseLeft = true;
		}
		
		else if (event.type == sf::Event::MouseButtonReleased) {
			if (event.mouseButton.button == sf::Mouse::Left)
				instance.mouseLeft = false;
		}

	}

	
}

void EventHandler::interpertInput()
{
	sf::RenderWindow &window = Game::getWindow();
	sf::View &view = Game::getView();
	EventHandler &instance = getInstance();

	sf::Vector2f viewMouse = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
	sf::Vector2f windowMouse = (sf::Vector2f)sf::Mouse::getPosition(window);
	static sf::Vector2f oldViewMouse = viewMouse;

	//============

	if (instance.space) {
		if (instance.mouseLeft) {
			view.move(oldViewMouse - viewMouse);
		}
	}

	if(instance.scrollDelta > 0)
		view.zoom(0.75f);
	else if(instance.scrollDelta < 0)
		view.zoom(1.25f);
	instance.scrollDelta = 0.f;

	//===========
	oldViewMouse = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
}

EventHandler & EventHandler::getInstance()
{
	static EventHandler instance;
	return instance;
}
