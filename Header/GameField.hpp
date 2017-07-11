#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Settings.hpp"
#include "Cell.hpp"

class GameField: public sf::Drawable
{
private:
	std::vector<std::vector<Cell>> cells;
	Settings mySettings;
public:
	GameField(Settings settings);
	~GameField();
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
};

#endif //GAMEFIELD_H