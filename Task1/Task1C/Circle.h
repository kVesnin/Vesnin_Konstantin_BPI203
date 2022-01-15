#pragma once

#include "ShapesProperties.h"
#include <fstream>

struct Circle {
    int x, y, r;
    Color color;
};

void initCircle(FILE* fp, Circle& circle);
void printCircle(Circle circle, std::ofstream& ofst);
double getCirclePerimetr(Circle circle);
Circle createRandomCircle();
