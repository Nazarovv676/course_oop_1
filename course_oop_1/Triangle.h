#pragma once

#include <SFML/Graphics.hpp>

#include "Figure.h"

using namespace sf;

class Triangle : public IFigure
{
	float radius;
	Color color;
	CircleShape* shape;
	Vector2f position;

public:
	Triangle() {
		createShape();
	};

	Triangle(float radius, Color color) : radius(radius), color(color) {
		createShape();
	}

	Triangle(float radius, Vector2f position, Color color) : radius(radius), position(position), color(color) {
		createShape();
	}

	Triangle(IFigure* figure) {
		radius = figure->getSize().x / 2;
		position = figure->getShape()->getPosition();
		color = figure->getShape()->getFillColor();

		createShape();
	}

	virtual ~Triangle() {
		delete shape;
	}

	void createShape() {
		shape = new CircleShape(radius, 3);

		shape->setFillColor(color);
		shape->setPosition(position);
	}

	virtual void draw(RenderWindow* window) override;

	virtual void move(Vector2f velocity) override;

	virtual Shape* getShape() override;

	virtual void onTouch() override;

	virtual Vector2f getSize() {
		return Vector2f(radius * 2, radius * 2);
	};
};

