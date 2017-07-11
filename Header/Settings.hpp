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
	unsigned int cellGap;

	sf::Color bg;
	sf::Color livingCell;
	sf::Color deadCell;
public:
	Settings();
	Settings(std::string pathToFile);
	~Settings();
	void load(std::string pathToFile);
};

#endif //SETTINGS_H