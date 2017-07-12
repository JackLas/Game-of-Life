#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Settings.hpp"
#include "Cell.hpp"

class GameField: public sf::Drawable
{
private:
	std::vector<std::vector<Cell>> curGen, prevGen;
	Settings mySettings;
public:
	GameField(Settings settings);
	~GameField();
	void update();
	void setHover(unsigned int x, unsigned int y, sf::RenderWindow &window);
	void setAlive(unsigned int x, unsigned int y);
	bool isCellHover(unsigned int x, unsigned int y);
	void clear();
	void nextGeneration();
	int checkNeighborhood(int x, int y);
	void randomize();
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
};

#endif //GAMEFIELD_H