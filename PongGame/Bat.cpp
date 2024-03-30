#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	Position.x = startX;
	Position.y = startY;

	Shape.setSize(sf::Vector2f(200, 5));
	Shape.setPosition(Position);
	Shape.setFillColor(sf::Color::Green);
	Shape.setOutlineColor(sf::Color::Cyan);
	Shape.setOutlineThickness(1.0f);
	
}

sf::FloatRect Bat::getPosition()
{
	return Shape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
	return Shape;
}

void Bat::moveLeft()
{
	MovingLeft = true;

}

void Bat::moveRight()
{
	MovingRight = true;
}

void Bat::stopLeft()
{
	MovingLeft = false;

}

void Bat::stopRight()
{
	MovingRight = false;
}

void Bat::update(sf::Time dt)
{
	if (MovingLeft) {
		Position.x -= Speed * dt.asSeconds();
	}

	if (MovingRight) {
		Position.x += Speed * dt.asSeconds();
	}

	Shape.setPosition(Position);
}
