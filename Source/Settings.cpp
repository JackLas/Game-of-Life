#include "Settings.hpp"

Settings::Settings()
{
	winWidth = 800;
	winHeight = 600;
	FPS = 60;

	fieldWidth = 80;
	fieldHeight = 60;
	cellGap = 2;

	bg = sf::Color::Black;
	livingCell = sf::Color::Green;
	deadCell = sf::Color::Red;
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