// Pong game
#include "Bat.h"
#include "Ball.h"

#include <sstream>
#include <cstdlib>

#include <SFML/Graphics.hpp>


int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Pong", Style::Fullscreen);
	window.setFramerateLimit(300);
	window.setMouseCursorVisible(false);

	int score = 0;
	int lives = 3;

	Bat bat(1920 / 2, 1080 - 20);
	Ball ball(1920 / 2, 0);

	// HUD
	Text hud;
	Font font;
	font.loadFromFile("fonts/ka1.ttf");
	hud.setFont(font);
	hud.setCharacterSize(50);
	hud.setFillColor(Color::Green);

	hud.setPosition(20, 20);

	Clock clock;
	while (window.isOpen())
	{
		/* Handle the player input */

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		/* Update */

		Time dt = clock.restart();
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
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}

