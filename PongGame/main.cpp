// Pong game
#include "Bat.h"
#include "Ball.h"

#include <sstream>
#include <cstdlib>

#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong", sf::Style::Fullscreen);
	window.setFramerateLimit(300);
	window.setMouseCursorVisible(false);

	sf::Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	sf::Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	int score = 0;
	int lives = 3;

	Bat bat(1920 / 2, 1080 - 20);
	Ball ball(1920 / 2, 0);

	// HUD
	sf::Text hud;
	sf::Font font;
	font.loadFromFile("fonts/ka1.ttf");
	hud.setFont(font);
	hud.setCharacterSize(50);
	hud.setFillColor(sf::Color::White);
	hud.setStyle(sf::Text::Italic);
	hud.setPosition(20, 20);

	sf::Clock clock;
	while (window.isOpen())
	{
		/* Handle the player input */

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		/* Update */

		sf::Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);

		std::stringstream ss;
		ss << "Score    " << score << "\nLives\t  " << lives;
		hud.setString(ss.str());

		// Handle ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y)
		{
			ball.reboundBottom();

			lives--;
			if (score >= 0)
			{
				score--;
			}
			if (lives < 1)
			{
				score = 0;
				lives = 3;

				if (score >= 0)
				{
					score--;
				}
			}
		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();
			score++;
		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 ||
			ball.getPosition().left + 10 > window.getSize().x)
		{
			ball.reboundSides();
		}

		if (ball.getPosition().intersects(bat.getPosition()))
		{
			ball.reboundBatOrTop();
		}

		/* Draw */

		window.clear();
		window.draw(spriteBackground);
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}

