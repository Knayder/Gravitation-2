#pragma once

#include <SFML\Graphics.hpp>
#include "Entity\AstroObjectsManager.h"

class Physics final {
public:
	Physics();
	Physics(const Physics &) = delete;
	void operator=(const Physics &) = delete;
	void gravitation();
};