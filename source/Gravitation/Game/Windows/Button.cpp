#include "Button.h"

Button::Button(const std::string &fileName) :
	sf::Sprite()
{
	sf::Image image;
	image.create(9, 9, sf::Color::Red);
	texture.loadFromImage(image);
	setTexture(texture);
}
