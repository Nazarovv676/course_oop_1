#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class IFigure
{
public:
	virtual ~IFigure() {}

	virtual void draw(RenderWindow* window) = 0;
};

