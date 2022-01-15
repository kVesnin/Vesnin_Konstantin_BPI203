#pragma once

#include "ShapesProperties.h"
#include <fstream>

struct Triangle {
    int xfirst, yfirst, xsecond, ysecond, xthird, ythird;
    Color color;
};

void initTriangle(FILE* fp, Triangle& tr);
double getTrianglePerimetr(Triangle triangle);

void printTriangle(Triangle triangle, std::ofstream& ofst);
Triangle createRandomTriangle();