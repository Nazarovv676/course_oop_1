#include "Controller.h"

IFigure* Controller::currentFigure()
{
	return _figures.back();
}

void Controller::addFigure(IFigure* figure)
{
	_figures.push_back(figure);
}

void Controller::draw(RenderWindow* window)
{
	for (auto figure : _figures) {
		figure->draw(window);
	}
}
