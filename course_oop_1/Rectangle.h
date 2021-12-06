#pragma once

#include <SFML/Graphics.hpp>

#include "Figure.h"

using namespace sf;

class Rectangle : virtual public IFigure
{
	Vector2f size;
	Color color;
	RectangleShape* shape;
public:
	Rectangle() {
		createShape();
	};

	Rectangle(Vector2f size, Color color) : size(size), color(color) {
		createShape();
	}

	virtual ~Rectangle() {
		delete shape;
	}

	void createShape() {
		shape = new RectangleShape();
		shape->setSize(size);
		shape->setFillColor(color);
	}

    virtual void draw(RenderWindow* window) override;

	virtual void move(Vector2f velocity) override;
};

