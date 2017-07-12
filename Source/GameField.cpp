#include "GameField.hpp"

GameField::GameField(Settings settings)
{
	mySettings = settings;
	
	float xOffset = mySettings.fieldWidth/mySettings.numOfCellWidth;
	float yOffset = mySettings.fieldHeight/mySettings.numOfCellHeight;
	sf::Vector2f size(xOffset - mySettings.cellGap, yOffset - mySettings.cellGap);

	for(unsigned int i = 0; i < mySettings.numOfCellHeight; ++i)
	{
		std::vector<Cell> tmp;
		for(unsigned int j = 0; j < mySettings.numOfCellWidth; ++j)
		{
			tmp.push_back(Cell(sf::Vector2f(j*xOffset + mySettings.cellGap/2 + mySettings.fieldPosition.x, i*yOffset + mySettings.cellGap/2 + mySettings.fieldPosition.y), sf::Vector2f(size)));
		}
		cells.push_back(tmp);
	}
}

GameField::~GameField()
{
}

void GameField::update()
{
	for(unsigned int y = 0; y < cells.size(); ++y)
	{
		for(unsigned int x = 0; x < cells[y].size(); ++x)
		{
			if(cells[y][x].isHover())
				cells[y][x].setColor(mySettings.hoverCell);
			else if(cells[y][x].isAlive())
				cells[y][x].setColor(mySettings.livingCell);
			else cells[y][x].setColor(mySettings.deadCell);
		}
	}
}

void GameField::setHover(unsigned int x, unsigned int y, sf::RenderWindow &window)
{
	if(cells[y][x].getBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		cells[y][x].setHover(true);
	else cells[y][x].setHover(false);
}

void GameField::setAlive(unsigned int x, unsigned int y)
{
	cells[y][x].setAlive(true);
}

bool GameField::isCellHover(unsigned x, unsigned int y)
{
	return cells[y][x].isHover();
}

void GameField::clear()
{
	for(unsigned int y = 0; y < cells.size(); ++y)
		for(unsigned int x = 0; x < cells[y].size(); ++x)
			cells[y][x].setAlive(false);
}

#include <iostream>
int GameField::checkNeighborhood(int x, int y)
{
	int counter = 0;
	for(int i = y-1; i < y+2; ++i)
	{
		for(int j = x-1; j < x+2; ++j)
		{
			if(i < 0 || i > (int)mySettings.numOfCellHeight-1)
			{
				//std::cout << "i out of range" << std::endl;
				continue;
			}

			if(j < 0 || j > (int)mySettings.numOfCellWidth-1)
			{
				//std::cout << "j out of range" << std::endl;
				continue;
			}

			if(i == y && j == x)
			{
				//std::cout << "i == y || j == x" << std::endl;
				continue;
			}

			if(cells[i][j].isAlive())
				counter++;
		}
	}

	//std::cout << "Counter: " << counter << std::endl << std::endl;
	return counter;
}

void GameField::nextGeneration()
{
	for(unsigned int y = 0; y < cells.size(); ++y)
	{
		for(unsigned int x = 0; x < cells[y].size(); ++x)
		{
			if(checkNeighborhood(x, y) == 3)
				cells[y][x].setAlive(true);
			else cells[y][x].setAlive(false);
		}
	}
}

void GameField::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < cells.size(); ++i)
		for(unsigned int j = 0; j < cells[i].size(); ++j)
			target.draw(cells[i][j], states);
}