#include <SFML\Graphics.hpp>
#include "Gravitation\Gravitation.h"
#include "Test.h"
int main() {
	MATH_H_TEST();
	Gravitation game({1280u, 720u});
	game.init();
	return 0;
}