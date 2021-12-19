#include "Controller.h"

const unsigned FIGURE_SIZE = 50;

IFigure* Controller::currentFigure()
{
	if (hasFigures()) {
		return _figures.back();
	}
	return nullptr;
}

void Controller::addFigure(IFigure* figure)
{
	_figures.push_back(figure);
}

void Controller::draw(RenderWindow* window)
{
	for (auto figure : _figures) {
		figure->draw(window);
	}
}

bool Controller::hasFigures()
{
	return _figures.size() > 0;
}

void Controller::maybeMove(Vector2f velocity)
{
	if (hasFigures()) {
		currentFigure()->move(velocity);
		resolveFiguresBounds(velocity);
		resolveScreenBounds();
	}
}

void Controller::setScreenSize(Vector2u size)
{
	screenSize = size;
}

void Controller::addRandomly()
{
	IFigure* figure = nullptr;
	switch (rand() % 2)
	{
	case 0:
		figure = new Rectangle(
			Vector2f(FIGURE_SIZE, FIGURE_SIZE),
			getScreenCenter(),
			generateRandColor()
		);
		break;

	case 1:
		figure = new Circle(
			FIGURE_SIZE / 2,
			getScreenCenter(),
			generateRandColor()
		);
		break;

	case 2:
		figure = new Triangle(
			FIGURE_SIZE / 2,
			getScreenCenter(),
			generateRandColor()
		);
		break;

	default:
		break;
	}
	_figures.push_back(figure);
}

void Controller::swapCurrent()
{
	IFigure* figure = nullptr;
	IFigure* current = currentFigure();
	switch (rand() % 3)
	{
	case 0:
		figure = new Rectangle(current);
		break;

	case 1:
		figure = new Circle(current);
		break;

	case 2:
		figure = new Triangle(current);
		break;

	default:
		break;
	}
	_figures.back() = figure;
	delete current;
}

void Controller::changeColorRandomly()
{
	currentFigure()->changeColorRandomly();
}

void Controller::deleteCurrent()
{
	if (hasFigures()) {
		_figures.pop_back();
	}
}

void Controller::resolveScreenBounds()
{
	Shape* shape = currentFigure()->getShape();

	float xDimHalf = currentFigure()->getSize().x / 2;
	float yDimHalf = currentFigure()->getSize().y / 2;

	if (shape->getPosition().x < -xDimHalf) {
		shape->setPosition(screenSize.x - xDimHalf, shape->getPosition().y);
	}
	if (shape->getPosition().y < -yDimHalf) {
		shape->setPosition(shape->getPosition().x, screenSize.y - yDimHalf);
	}
	if (shape->getPosition().x + xDimHalf > screenSize.x) {
		shape->setPosition(-xDimHalf, shape->getPosition().y);
	}
	if (shape->getPosition().y + yDimHalf > screenSize.y) {
		shape->setPosition(shape->getPosition().x, -yDimHalf);
	}
}

void Controller::resolveFiguresBounds(Vector2f lastMovementVelocity)
{
	Shape* shape = currentFigure()->getShape();

	for (int i = 0; i < _figures.size() - 1; i++) {
		FloatRect currentFigureBounds = shape->getGlobalBounds();
		FloatRect otherFigureBounds = _figures[i]->getShape()->getGlobalBounds();

		FloatRect intersect;
		currentFigureBounds.intersects(otherFigureBounds, intersect);

		float moveToLeft = 0;
		float moveToTop = 0;
		float moveToRight = 0;
		float moveToBottom = 0;
		if (intersect.top == otherFigureBounds.top) {
			moveToTop = intersect.height;
		}
		if (intersect.left == otherFigureBounds.left) {
			moveToLeft = intersect.width;
		}
		if (intersect.top + intersect.height == otherFigureBounds.top + otherFigureBounds.height) {
			moveToBottom = intersect.height;
		}
		if (intersect.left + intersect.width == otherFigureBounds.left + otherFigureBounds.width) {
			moveToRight = intersect.width;
		}

		float moveVertical = max(moveToBottom, moveToTop);
		float moveHorisontal = max(moveToRight, moveToLeft);


		if (moveVertical < moveHorisontal) {
			if (moveToTop > moveToBottom) {
				moveVertical = -moveVertical;
			}

			shape->move(Vector2f(0, moveVertical));
		}
		else {
			if (moveToLeft > moveToRight) {
				moveHorisontal = -moveHorisontal;
			}

			shape->move(Vector2f(moveHorisontal, 0));
		}

		if (intersect.top != 0 && intersect.left != 0) {
			swapCurrent();
		}
	}
}

Color Controller::generateRandColor()
{
	return Color(rand() % 255, rand() % 255, rand() % 255);
}

Vector2f Controller::getScreenCenter()
{
	return Vector2f(screenSize.x / 2 - FIGURE_SIZE / 2, screenSize.y / 2 - FIGURE_SIZE / 2);
}
