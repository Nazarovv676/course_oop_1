#pragma once

#include <SFML/Graphics.hpp>

#include "Figure.h"

using namespace sf;

class Circle : public IFigure
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
		FloatRect bounds = figure->getShape()->getGlobalBounds();
		radius = (bounds.left + bounds.width - bounds.left) / 2;
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

	virtual void onTouch() override;
};

