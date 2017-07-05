#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
class Window : public sf::Drawable, public sf::Transformable {
public:
	Window(const sf::Vector2f &size);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	sf::RectangleShape background, bar;
	Button exitButton;
};