#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	Position.x = startX;
	Position.y = startY;

	Shape.setSize(sf::Vector2f(10, 10));
	Shape.setPosition(Position);
	Shape.setFillColor(sf::Color::Red);
}

sf::FloatRect Ball::getPosition()
{
	return Shape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return Shape;
}

float Ball::getXVelocity()
{
	return DirectionX;
}

void Ball::reboundSides()
{
	DirectionX = -DirectionX;
}

void Ball::reboundBatOrTop()
{
	DirectionY = -DirectionY;

}

void Ball::reboundBottom()
{
	Position.y = 0;
	Position.x = 500;
	DirectionY = -DirectionY;
}

void Ball::update(sf::Time dt)
{
	Position.y += DirectionY * Speed * dt.asSeconds();
	Position.x += DirectionX * Speed * dt.asSeconds();

	Shape.setPosition(Position);
}