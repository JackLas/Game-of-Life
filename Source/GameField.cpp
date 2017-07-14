#include "GameField.hpp"
#include <ctime>
#include <cstdlib>

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
		curGen.push_back(tmp);
	}
	prevGen = curGen;
}

GameField::~GameField()
{
}

void GameField::update()
{
	for(unsigned int y = 0; y < curGen.size(); ++y)
	{
		for(unsigned int x = 0; x < curGen[y].size(); ++x)
		{
			if(curGen[y][x].isHover())
				curGen[y][x].setColor(mySettings.hoverCell);
			else if(curGen[y][x].isAlive())
				curGen[y][x].setColor(mySettings.livingCell);
			else curGen[y][x].setColor(mySettings.deadCell);
		}
	}
}

void GameField::setHover(unsigned int x, unsigned int y, sf::RenderWindow &window)
{
	if(curGen[y][x].getBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		curGen[y][x].setHover(true);
	else curGen[y][x].setHover(false);
}

void GameField::setAlive(unsigned int x, unsigned int y)
{
	curGen[y][x].setAlive(true);
}

bool GameField::isCellHover(unsigned x, unsigned int y)
{
	return curGen[y][x].isHover();
}

void GameField::clear()
{
	for(unsigned int y = 0; y < curGen.size(); ++y)
		for(unsigned int x = 0; x < curGen[y].size(); ++x)
			curGen[y][x].setAlive(false);
}

#include <iostream>
int GameField::checkNeighborhood(int x, int y)
{
	int counter = 0;
	for(int i = y-1; i <= y+1; ++i)
	{
		for(int j = x-1; j <= x+1; ++j)
		{
			if(i == y && j == x)
				continue;

			int tmpX = j, tmpY = i;

			if(i < 0)
				tmpY = i + mySettings.numOfCellHeight;

			if(i > (int)mySettings.numOfCellHeight-1)
				tmpY = i - mySettings.numOfCellHeight;

			if(j < 0)
				tmpX = j + mySettings.numOfCellWidth;

			if(j > (int)mySettings.numOfCellWidth-1)
				tmpX = j - mySettings.numOfCellWidth;

			if(prevGen[tmpY][tmpX].isAlive())
				counter++;
		}
	}
	return counter;
}

void GameField::nextGeneration()
{
	prevGen = curGen;
	for(unsigned int y = 0; y < curGen.size(); ++y)
	{
		for(unsigned int x = 0; x < curGen[y].size(); ++x)
		{
			int neighborhood = checkNeighborhood(x, y);
			if(neighborhood == 3 && !prevGen[y][x].isAlive())
				curGen[y][x].setAlive(true);
			else if(neighborhood >= 2 && neighborhood <= 3 && prevGen[y][x].isAlive())
				curGen[y][x].setAlive(true);
			else curGen[y][x].setAlive(false);
		}
	}
}

void GameField::randomize()
{
	srand(time(NULL));
	for(unsigned int y = 0; y < curGen.size(); ++y)
		for(unsigned int x = 0; x < curGen[y].size(); ++x)
			if((rand()%10000)%2 == 0)
				curGen[y][x].setAlive(true);
			else curGen[y][x].setAlive(false);

}

void GameField::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < curGen.size(); ++i)
		for(unsigned int j = 0; j < curGen[i].size(); ++j)
			target.draw(curGen[i][j], states);
}