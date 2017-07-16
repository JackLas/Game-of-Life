#include "Settings.hpp"

Settings::Settings()
{
	winWidth = 1130;
	winHeight = 640;
	FPS = 30;

	/*
	fieldWidth = winWidth - 200 - 40;
	fieldHeight = winHeight - 40;
	fieldPosition = sf::Vector2f(20, 20);
	numOfCellWidth = 50;
	numOfCellHeight = 50;
	*/

	fieldWidth = winWidth;
	fieldHeight = winHeight-20;
	fieldPosition = sf::Vector2f(0, 20);
	numOfCellWidth = 113;
	numOfCellHeight = 62;

	cellGap = 1;

	generationDelay = 0.07;

	bg = sf::Color::Black;
	text = sf::Color::White;
	livingCell = sf::Color::Green;
	deadCell = bg;//sf::Color::Red;
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