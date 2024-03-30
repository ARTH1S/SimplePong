#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
private:
	sf::Vector2f Position; 

	// A RectangleShape object
	sf::RectangleShape Shape;

	float Speed = 1000.0f;

	bool MovingRight = false;
	bool MovingLeft = false;


public:
	Bat(float startX, float startY);

	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void stopLeft(); 
	void stopRight();  
	void update(sf::Time dt); 

};
