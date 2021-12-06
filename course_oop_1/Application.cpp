#include "Application.h"
#include "Rectangle.h"

void Application::run()
{
	RenderWindow window(VideoMode(500, 700), "SFML Application");

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::R) {
					controller.addFigure(new Rectangle(Vector2f(10, 10), Color::Blue));
				}
			}
		}

		controller.draw(&window);

		window.display();
	}
}
