#include <iostream>

#include "Application.h"
#include "Rectangle.h"

using namespace std;

void Application::run()
{
	const unsigned WINDOW_WIDTH = 1000;
	const unsigned WINDOW_HEIGHT = 1000;

	const int framerateLimit = 120;

	const float movementSpeed = 100.f;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application", Style::Close);
	window.setFramerateLimit(framerateLimit);

	controller.setScreenSize(Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));

	float dt;
	Clock dt_clock;

	Vector2f velocity;

	while (window.isOpen()) {
		dt = dt_clock.restart().asSeconds();

		Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed: 
				if (event.key.code == Keyboard::C) {
					controller.swapCurrent();
				}
				if (event.key.code == Keyboard::A) {
					controller.addRandomly();
				}
				if (event.key.code == Keyboard::S) {
					controller.changeColorRandomly();
				}
				break;

			default:
				break;
			}
		}

		velocity.x = 0.f;
		velocity.y = 0.f;
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			velocity.y += -movementSpeed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			velocity.y += movementSpeed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			velocity.x += -movementSpeed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			velocity.x += movementSpeed * dt;
		}
		controller.maybeMove(velocity);

		window.clear();
		controller.draw(&window);
		window.display();
	}
}
