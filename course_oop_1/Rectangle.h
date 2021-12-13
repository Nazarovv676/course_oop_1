#pragma once

#include <SFML/Graphics.hpp>

#include "Figure.h"

using namespace sf;

class Rectangle : virtual public IFigure
{
	Vector2f size;
	Color color;
	RectangleShape* shape;
	Vector2f position;
public:
	Rectangle() {
		createShape();
	};

	Rectangle(Vector2f size, Color color) : size(size), color(color) {
		createShape();
	}

	Rectangle(Vector2f size, Vector2f position, Color color) : size(size), position(position), color(color) {
		createShape();
	}

	Rectangle(IFigure* figure) {
		size = figure->getSize();
		position = figure->getShape()->getPosition();
		color = figure->getShape()->getFillColor();

		createShape();
	}

	virtual ~Rectangle() {
		delete shape;
	}

	void createShape() {
		shape = new RectangleShape();
		shape->setSize(size);
		shape->setFillColor(color);
		shape->setPosition(position);
	}

    virtual void draw(RenderWindow* window) override;

	virtual void move(Vector2f velocity) override;

	virtual Shape* getShape() override;

	virtual void changeColorRandomly() override;

	virtual Vector2f getSize() {
		return size;
	};
};

