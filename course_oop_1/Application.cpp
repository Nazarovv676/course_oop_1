#include <iostream>

#include "Application.h"
#include "Rectangle.h"

using namespace std;

void Application::run()
{
	RenderWindow window(VideoMode(500, 700), "SFML Application");
	window.setFramerateLimit(120);

	float dt;
	Clock dt_clock;

	const float movementSpeed = 100.f;

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
				if (event.key.code == Keyboard::R) {
					controller.addFigure(new Rectangle(Vector2f(30, 30), Color(rand() % 255, rand() % 255, rand() % 255)));
				}
				break;

			default:
				break;
			}
		}

		// Movement

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
		
		IFigure* currentFigure = controller.currentFigure();

		if (currentFigure != nullptr) {
			currentFigure->move(velocity);
		}

		// Colision

		// Render

		window.clear();

		controller.draw(&window);

		window.display();
	}
}
