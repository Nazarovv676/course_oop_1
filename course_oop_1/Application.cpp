#include <iostream>

#include "Application.h"
#include "Rectangle.h"
#include <deque>

using namespace std;

void Application::run()
{
	const unsigned WINDOW_WIDTH = 700;
	const unsigned WINDOW_HEIGHT = 700;

	const int framerateLimit = 120;

	const float movementSpeed = 200.f;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application", Style::Close);
	window.setFramerateLimit(framerateLimit);

	controller.setScreenSize(Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));

	float dt;
	Clock dt_clock;

	Vector2f velocity;

	deque<Vector2f> lastTrajectory;
	bool isRecording = false;
	bool isPlaying = false;

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
				if (event.key.code == Keyboard::S) {
					controller.swapCurrent();
				}
				if (event.key.code == Keyboard::A) {
					controller.addRandomly();
				}
				if (event.key.code == Keyboard::C) {
					controller.changeColorRandomly();
				}
				if (event.key.code == Keyboard::D) {
					controller.deleteCurrent();
				}
				if (event.key.code == Keyboard::R) {
					if (!isRecording) {
						lastTrajectory.clear();
					}
					isRecording = !isRecording;
				}
				if (event.key.code == Keyboard::E) {
					if (isRecording) {
						isRecording = false;
					}
					if (isPlaying) {
						lastTrajectory.clear();
					}
					isPlaying = !isPlaying;
				}
				break;

			default:
				break;
			}
		}

		if (!isPlaying) {
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
		}

		if (isPlaying) {
			if (lastTrajectory.size() == 0) {
				isPlaying = false;
			}
			else {
				velocity = lastTrajectory.front();
				lastTrajectory.pop_front();
			}
		}


		if (isRecording) {
			lastTrajectory.push_back(velocity);
		}

		controller.maybeMove(velocity);

		window.clear();
		controller.draw(&window);
		window.display();
	}
}
