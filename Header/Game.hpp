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

	GameField gameField;
public:
	Game(Settings settings);
	~Game();
	void run();
protected:
	void handleInput();
	void update();
	void render();
};

#endif //GAME_H