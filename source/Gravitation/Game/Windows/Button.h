#pragma once
#include <SFML\Graphics.hpp>

class Button : public sf::Sprite {
public:
	Button(const std::string &fileName);
private:
	sf::Texture texture;
};