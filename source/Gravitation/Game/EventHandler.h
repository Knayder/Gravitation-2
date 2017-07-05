#pragma once
#include <SFML\Graphics.hpp>
#include "..\Game\Game.h"

class EventHandler final {
public:
	EventHandler(const EventHandler &) = delete;
	void operator=(const EventHandler &) = delete;

	static void getInput();
	static void interpertInput();
private:
	EventHandler();

	bool space, mouseLeft;
	float scrollDelta;

	static EventHandler &getInstance();
};