#pragma once

class EventHandler final {
public:
	EventHandler(const EventHandler &) = delete;
	void operator=(const EventHandler &) = delete;

	
private:
	EventHandler();

	static EventHandler &getInstance();
};