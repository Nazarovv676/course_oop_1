#include "Rectangle.h"

void Rectangle::draw(RenderWindow* window)
{
	window->draw(*shape);
}

void Rectangle::move(Vector2f velocity)
{
	shape->move(velocity);
}

Shape* Rectangle::getShape()
{
	return shape;
}
