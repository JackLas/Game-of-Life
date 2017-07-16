#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Settings.hpp"
#include "GameField.hpp"

class Game
{
private:
	Settings mySettings;

	sf::RenderWindow myWindow;
	sf::Clock clock;
	sf::Font font;
	bool isPaused;
	float generationDelay;
	float timeToGeneration;

	GameField gameField;

	sf::Text txGameStatus;
public:
	Game(Settings settings);
	~Game();
	void run();
protected:
	void handleInput();
	void update();
	void render();
	void switchPause();
};

#endif //GAME_H