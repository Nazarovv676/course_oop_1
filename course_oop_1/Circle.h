#pragma once

#include <SFML/Graphics.hpp>

#include "Figure.h"
#include "Triangle.h"

using namespace sf;

class Circle : virtual public IFigure
{
	float radius;
	Color color;
	CircleShape* shape;
	Vector2f position;

public:
	Circle() {
		createShape();
	};

	Circle(float radius, Color color) : radius(radius), color(color) {
		createShape();
	}

	Circle(float radius, Vector2f position, Color color) : radius(radius), position(position), color(color) {
		createShape();
	}

	Circle(IFigure* figure) {
		radius = figure->getSize().x / 2;
		position = figure->getShape()->getPosition();
		color = figure->getShape()->getFillColor();

		createShape();
	}

	virtual ~Circle() {
		delete shape;
	}

	void createShape() {
		shape = new CircleShape();
		shape->setRadius(radius);
		shape->setFillColor(color);
		shape->setPosition(position);
	}

	virtual void draw(RenderWindow* window) override;

	virtual void move(Vector2f velocity) override;

	virtual Shape* getShape() override;

	virtual void changeColorRandomly() override;

	virtual Vector2f getSize() {
		return Vector2f(radius * 2, radius * 2);
	};
};

