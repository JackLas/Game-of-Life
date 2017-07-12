#include "Settings.hpp"

Settings::Settings()
{
	winWidth = 800;
	winHeight = 600;
	FPS = 60;

	fieldWidth = winWidth - 200 - 40;
	fieldHeight = winHeight - 40;
	fieldPosition = sf::Vector2f(20, 20);
	numOfCellWidth = 50;
	numOfCellHeight = 50;
	cellGap = 2;

	generationDelay = 0.10;

	bg = sf::Color::Black;
	livingCell = sf::Color::Green;
	deadCell = sf::Color::Red;
	hoverCell = sf::Color::Blue;
}

Settings::Settings(std::string pathToFile)
{
	load(pathToFile);
}

Settings::~Settings()
{

}

void Settings::load(std::string pathToFile)
{

}