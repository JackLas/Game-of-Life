#include "GameField.hpp"

GameField::GameField(Settings settings)
{
	mySettings = settings;
	
	float xOffset = mySettings.winWidth/mySettings.fieldWidth;
	float yOffset = mySettings.winHeight/mySettings.fieldHeight;
	sf::Vector2f size(xOffset - mySettings.cellGap, yOffset - mySettings.cellGap);

	for(unsigned int i = 0; i < mySettings.fieldHeight; ++i)
	{
		std::vector<Cell> tmp;
		for(unsigned int j = 0; j < mySettings.fieldWidth; ++j)
		{
			tmp.push_back(Cell(sf::Vector2f(j*xOffset + mySettings.cellGap/2, i*yOffset + mySettings.cellGap/2), sf::Vector2f(size)));
		}
		cells.push_back(tmp);
	}
}

GameField::~GameField()
{
}

void GameField::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < cells.size(); ++i)
	{
		for(unsigned int j = 0; j < cells[i].size(); ++j)
		{
			//if(cells[i][j].isAlive())
			//	cells[i][j].setColor(mySettings.livingCell);
			//else cells[i][j].setColor(mySettings.deadCell);

			target.draw(cells[i][j], states);
		}
	}
}