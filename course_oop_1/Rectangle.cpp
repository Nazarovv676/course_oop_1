#include "Rectangle.h"

void Rectangle::draw(RenderWindow* window)
{
	RectangleShape rectangle;
	rectangle.setSize(size);
	rectangle.setFillColor(color);
	rectangle.setPosition(Vector2f(10, 10));

	window->draw(rectangle);
}
