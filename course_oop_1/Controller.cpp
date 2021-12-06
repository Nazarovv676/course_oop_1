#include "Controller.h"

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
	return _figures.size() > 0 ;
}

void Controller::maybeMove(Vector2f velocity)
{
	if (hasFigures()) {
		currentFigure()->move(velocity);
		resolveScreenBounds();
		resolveFiguresBounds(velocity);
	}
}

void Controller::setScreenSize(Vector2u size)
{
	screenSize = size;
}

void Controller::resolveScreenBounds()
{
	Shape* shape = currentFigure()->getShape();

	if (shape->getPosition().x < 0.f) {
		shape->setPosition(0.f, shape->getPosition().y);
	}
	if (shape->getPosition().y < 0.f) {
		shape->setPosition(shape->getPosition().x, 0.f);
	}
	if (shape->getPosition().x > screenSize.x - shape->getGlobalBounds().width) {
		shape->setPosition(screenSize.x - shape->getGlobalBounds().width, shape->getPosition().y);
	}
	if (shape->getPosition().y > screenSize.y - shape->getGlobalBounds().height) {
		shape->setPosition(shape->getPosition().x, screenSize.y - shape->getGlobalBounds().height);
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
		Vector2f position = shape->getPosition();
		if (intersect.height != 0 && intersect.width != 0) {
			shape->move(Vector2f(-lastMovementVelocity.x, -lastMovementVelocity.y));
		}
	}
}
