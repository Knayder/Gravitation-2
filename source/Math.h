#pragma once
#include <SFML\Graphics.hpp>
class Math final {
public:
	static float distance(const sf::Vector2f &a, const sf::Vector2f &b) {
		sf::Vector2f d = deltaVector(a, b);
		return std::sqrt( d.x*d.x + d.y*d.y );
	}

	static sf::Vector2f deltaVector(const sf::Vector2f &a, const sf::Vector2f &b) {
		return b - a;
	}

	static sf::Vector2f normalizedVector(const sf::Vector2f &a) {
		return a / std::sqrt(a.x*a.x + a.y*a.y);
	}
};