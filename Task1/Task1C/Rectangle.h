#pragma once
#include "ShapesProperties.h"
#include <fstream>


struct Rectangle {
    int xleft, yleft, xright, yright;
    Color color;
};

void initRectangle(FILE* fp, Rectangle& rect);

double getRectanglePerimetr(Rectangle rectangle);

void printRectangle(Rectangle rectangle, std::ofstream& ofst);

Rectangle createRandomRectangle();