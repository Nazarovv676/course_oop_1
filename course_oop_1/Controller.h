#pragma once

#include <vector>

#include "Figure.h"

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

private:
	vector<IFigure*> _figures;
};

