#include "Circle.h"

void Circle::draw(RenderWindow* window)
{
	window->draw(*shape);
}

void Circle::move(Vector2f velocity)
{
	shape->move(velocity);
	position += velocity;
}

Shape* Circle::getShape()
{
	return shape;
}

void Circle::changeColorRandomly()
{
	color = Color(rand() % 255, rand() % 255, rand() % 255);
	shape->setFillColor(color);
}