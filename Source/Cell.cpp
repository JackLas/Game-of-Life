#include "Cell.hpp"

Cell::Cell(sf::Vector2f position, sf::Vector2f size)
{
	initialization(position, size);
}

Cell::~Cell()
{
}

void Cell::initialization(sf::Vector2f position, sf::Vector2f size)
{
	myIsAlive = false;
	myIsHover = false;
	myShape.setSize(size); 
	myShape.setPosition(position);
}

void Cell::setColor(sf::Color color)
{
	myShape.setFillColor(color);
}

bool Cell::isHover()
{
	return myIsHover;
}

bool Cell::isAlive()
{
	return myIsAlive;
}

void Cell::setAlive(bool isAlive)
{
	myIsAlive = isAlive;
}

void Cell::setHover(bool isHover)
{
	myIsHover = isHover;
}

sf::FloatRect Cell::getBounds()
{
	return myShape.getGlobalBounds();
}

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(myShape, states);
}