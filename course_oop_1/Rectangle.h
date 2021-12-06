#pragma once

#include <SFML/Graphics.hpp>

#include "Figure.h"

using namespace sf;

class Rectangle : virtual public IFigure
{
	Vector2f size;
	Color color;
public:
	Rectangle() {};

	Rectangle(Vector2f size, Color color) : size(size), color(color) {}

	virtual ~Rectangle() {}

    virtual void draw(RenderWindow* window) override;
};

