#pragma once

#include <SFML/Graphics.hpp>

#include "Controller.h"

using namespace sf;

class Application
{
public:
	void run();

private:
	Controller controller;
};

