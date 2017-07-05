#include "Window.h"

Window::Window(const sf::Vector2f &size) :
	background(size),
	bar({ size.x, 9.f }),
	exitButton("test")
{
	background.setFillColor(sf::Color(250,250,250));
	background.setOutlineThickness(1);
	background.setOutlineColor(sf::Color(20,20,20));
	bar.setFillColor(sf::Color(220, 220, 220));
	exitButton.setPosition({ size.x - 9.f, 0.f });
}

void Window::draw(sf::RenderTarget & target, sf::RenderStates states) const{
	states.transform *= getTransform();
	target.draw(background, states);
	target.draw(bar, states);
	target.draw(exitButton, states);
}
