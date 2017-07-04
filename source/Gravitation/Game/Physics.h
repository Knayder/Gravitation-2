#pragma once

#include <SFML\Graphics.hpp>
#include "Entity\AstroObjectsManager.h"

class Physics final {
public:
	Physics(const Physics &) = delete;
	void operator=(const Physics &) = delete;

	static void gravitation();
	static void collisions();
private:
	int additionalSpeed;
	Physics();
	static Physics &getInstance();
};