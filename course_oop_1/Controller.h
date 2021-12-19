#pragma once

#include <vector>

#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using namespace std;

class Controller
{
public:
	Controller() {};

	Controller(vector<IFigure*> figures) : _figures(figures) {}

	vector<IFigure*> figures() { return _figures; };

	IFigure* currentFigure();

	void addFigure(IFigure* figure);

	void draw(RenderWindow* window);

	bool hasFigures();

	void maybeMove(Vector2f velocity);

	void setScreenSize(Vector2u size);

	void addRandFigure();

	void swapCurrent();

	void deleteCurrent();

private:
	vector<IFigure*> _figures;
	Vector2u screenSize;

	void resolveScreenBounds();

	void resolveFiguresBounds(Vector2f lastMovementVelocity);

	Color generateRandColor();

	Vector2f getScreenCenter();
};

