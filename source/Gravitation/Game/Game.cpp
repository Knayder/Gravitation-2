#include "Game.h"

Game::Game() :
	ableToLeave(false),
	maxFps(60.f),
	deltaTime(0.f)

{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 0;
	settings.minorVersion = 1;
	window.create(sf::VideoMode(1280u, 720u), "Gravitation 2", sf::Style::Close | sf::Style::Titlebar, settings);
	view = window.getDefaultView();
}

Game & Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::init() {
	Game &instance = getInstance();
	AstroObjectsManager::addObject(new AstroObject(1000, 1000, { 0.f,0.f }))
		->setVelocity({ 0.f, 0.f });
	AstroObjectsManager::addObject(new AstroObject(50, 1, { 0.f, 1600.f }, sf::Color(230, 100, 100)))
		->setVelocity({std::sqrt(1000.f / 1600.f),0});

	Window test({200.f, 300.f});
	test.setPosition(100, 100);

	while (instance.window.isOpen() && instance.ableToLeave == false) {
		if (!fpsChecker())
			continue;
		

		consoleLog();
		EventHandler::getInput();
		EventHandler::interpertInput();
		
		Physics::gravitation();
		AstroObjectsManager::update();

		instance.window.clear(sf::Color(37, 37, 48));
		//Types of drawing: Dynamic View and Static View

		instance.window.setView(instance.view);
		//Dynamic View
		AstroObjectsManager::draw();

		instance.window.setView(instance.window.getDefaultView());
		//Static View
		instance.window.draw(test);
		
		instance.window.display();
	}
}



void Game::consoleLog()
{
	static sf::Clock logClock;
	if (logClock.getElapsedTime().asSeconds() >= 0.5f) {
		logClock.restart();
		//system("cls");
		std::cout << "FPS: " << 1.f / Game::getDeltaTime() << '\n';
		float dist = Math::distance(AstroObjectsManager::get(0)->getPosition(), AstroObjectsManager::get(1)->getPosition());
		std::cout << "Distance: " << dist << '\n';
	}
}

bool Game::fpsChecker(){
	Game &instance = getInstance();
	instance.deltaTime = instance.clock.getElapsedTime().asSeconds();
	if (instance.deltaTime < 1.f / instance.maxFps)
		return false;
	instance.clock.restart();
	return true;
}



float Game::getDeltaTime()
{
	return getInstance().deltaTime;
}

sf::RenderWindow & Game::getWindow()
{
	return getInstance().window;
}

sf::View & Game::getView()
{
	return getInstance().view;
}
