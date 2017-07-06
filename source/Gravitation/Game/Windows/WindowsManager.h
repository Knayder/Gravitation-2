#pragma once
#include <unordered_map>
#include "Window.h"

class WindowsManager final {
public:
	typedef std::unordered_map<std::string, Window*> WindowsContainer;

	~WindowsManager();
	WindowsManager(const WindowsManager &) = delete;
	void operator=(const WindowsManager &) = delete;

	static Window *add(Window *object, const std::string &name);
	static bool remove(const std::string &name);
	static void clear();
	static Window *get(const std::string &name);



private:
	WindowsManager();

	static WindowsManager &getInstance();

	WindowsContainer windowsContainer;
};