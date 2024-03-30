#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::Vector2f Position;
	sf::RectangleShape Shape;

	float Speed = 2500.0f;
	float DirectionX = .2f;
	float DirectionY = .2f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void reboundBottom();
	void update(sf::Time dt);

};
