#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class IFigure
{
public:
	virtual ~IFigure() {}

	virtual void move(Vector2f velocity) = 0;

	virtual void draw(RenderWindow* window) = 0;

	virtual Shape* getShape() = 0;
};

