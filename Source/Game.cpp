#include "Game.hpp"

Game::Game(Settings settings): myWindow(sf::VideoMode(settings.winWidth, settings.winHeight), "Game of Life", sf::Style::Close),
							   gameField(settings)
{
	mySettings = settings;
	myWindow.setFramerateLimit(mySettings.FPS);
	isPaused = true;
	generationDelay = mySettings.generationDelay;
	timeToGeneration = 0;
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

		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::C && isPaused)
				gameField.clear();
			if(event.key.code == sf::Keyboard::R && isPaused)
				gameField.randomize();
			if(event.key.code == sf::Keyboard::Space)
				switchPause();
		}
	}

	for(unsigned int y = 0; y < mySettings.numOfCellHeight; ++y)
	{
		for(unsigned int x = 0; x < mySettings.numOfCellWidth; ++x)
		{
			gameField.setHover(x, y, myWindow);
			if(gameField.isCellHover(x, y) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isPaused)
				gameField.setAlive(x, y);
		}
	}

}

void Game::update()
{
	sf::Time deltaTime = clock.restart();
	gameField.update();
	if(!isPaused)
	{
		timeToGeneration += deltaTime.asSeconds();
		if(timeToGeneration >= generationDelay)
		{
			gameField.nextGeneration();
			timeToGeneration = 0;
		}
	}
}

void Game::render()
{
	myWindow.clear(mySettings.bg);
		myWindow.draw(gameField);
	myWindow.display();
}

void Game::switchPause()
{
	isPaused = !isPaused;
}