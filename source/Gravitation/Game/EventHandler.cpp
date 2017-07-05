#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler & EventHandler::getInstance()
{
	static EventHandler instance;
	return instance;
}
