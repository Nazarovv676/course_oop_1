#include "Triangle.h"

void Triangle::draw(RenderWindow* window)
{
	window->draw(*shape);
}

void Triangle::move(Vector2f velocity)
{
	shape->move(velocity);
	position += velocity;
}

Shape* Triangle::getShape()
{
	return shape;
}

void Triangle::onTouch()
{
	color = Color(rand() % 255, rand() % 255, rand() % 255);
	shape->setFillColor(color);
}