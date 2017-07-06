#include "WindowsManager.h"

WindowsManager::~WindowsManager()
{
	for (auto &it : windowsContainer)
		delete (it.second);
}

WindowsManager::WindowsManager()
{

}

WindowsManager & WindowsManager::getInstance(){
	static WindowsManager instance;
	return instance;
}



Window * WindowsManager::add(Window * object, const std::string & name)
{
	if (object != nullptr) {
		Window *result = WindowsManager::get(name);
		if (result != nullptr)
			delete result;
		WindowsContainer &container = getInstance().windowsContainer;
		container[name] = object;
	
	}
	return object;
}

bool WindowsManager::remove(const std::string & name)
{
	WindowsContainer &container = getInstance().windowsContainer;
	auto result = container.find(name);
	if (result != container.end()) {
		container.erase(result);
		return true;
	}
	return false;
}


void WindowsManager::clear()
{
	for (auto& it : getInstance().windowsContainer)
		delete (it.second);
	getInstance().windowsContainer.clear();
}

Window * WindowsManager::get(const std::string & name)
{
	WindowsContainer &container = getInstance().windowsContainer;
	auto result = container.find(name);
	if (result == container.end())
		return nullptr;
	return result->second;
}
