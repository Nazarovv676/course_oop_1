#include "Rectangle.h"

void Rectangle::draw(RenderWindow* window)
{
	window->draw(*shape);
}

void Rectangle::move(Vector2f velocity)
{
	shape->move(velocity);
	position += velocity;
}

Shape* Rectangle::getShape()
{
	return shape;
}

void Rectangle::onTouch()
{
	color = Color(rand() % 255, rand() % 255, rand() % 255);
	shape->setFillColor(color);
}
