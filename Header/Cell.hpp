#ifndef CELL_H
#define CELL_H

#include <SFML\Graphics.hpp>

class Cell: public sf::Drawable
{
private:
	bool myIsAlive;
	bool myIsHover;
	sf::RectangleShape myShape;
public:
	Cell(sf::Vector2f position, sf::Vector2f size);
	~Cell();
	void initialization(sf::Vector2f position, sf::Vector2f size);
	void setColor(sf::Color color);
	bool isHover();
	bool isAlive();
	void setAlive(bool isAlive);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //CELL_H