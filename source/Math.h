#pragma once
#include <SFML\Graphics.hpp>
class Math final {
public:
	static float distance(const sf::Vector2f &a, const sf::Vector2f &b) {
		sf::Vector2f d = a - b;
		return std::sqrt( d.x*d.x + d.y*d.y );
	}
};