#include "Game.hpp"

Game::Game(Settings settings): myWindow(sf::VideoMode(settings.winWidth, settings.winHeight), "Game of Life", sf::Style::Close),
							   gameField(settings)
{
	mySettings = settings;
	myWindow.setFramerateLimit(mySettings.FPS);
}

Game::~Game()
{
}

void Game::run()
{
	while(myWindow.isOpen())
	{
		handleInput();
		update();
		render();
	}
}

void Game::handleInput()
{
	sf::Event event;
	while(myWindow.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			myWindow.close();
	}
}

#include <iostream>
void Game::update()
{
	sf::Time deltaTime = clock.restart();
	std::cout << "DeltaTime = " << deltaTime.asSeconds() << std::endl;
}

void Game::render()
{
	myWindow.clear(mySettings.bg);
		myWindow.draw(gameField);
	myWindow.display();
}