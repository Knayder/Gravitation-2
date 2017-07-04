#include <SFML\Graphics.hpp>
#include "Game\Game.h"


class Gravitation final {
public:
	//Delete useless constructors.
	Gravitation(const Gravitation &) = delete;
	void operator=(const Gravitation &) = delete;

	Gravitation();
	void init();
private:
};