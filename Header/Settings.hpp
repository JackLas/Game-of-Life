#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML\Graphics.hpp>

class Settings
{
public:
	unsigned int winWidth;
	unsigned int winHeight;
	unsigned int FPS;

	unsigned int fieldWidth;
	unsigned int fieldHeight;
	sf::Vector2f fieldPosition;
	unsigned int numOfCellWidth;
	unsigned int numOfCellHeight;
	unsigned int cellGap;

	float generationDelay;

	sf::Color bg;
	sf::Color livingCell;
	sf::Color deadCell;
	sf::Color hoverCell;
public:
	Settings();
	Settings(std::string pathToFile);
	~Settings();
	void load(std::string pathToFile);
};

#endif //SETTINGS_H