#pragma once

#include "Shape.h"
#include <stdio.h>

enum { maxLen = 10000 };
struct Container {
    int len = 0;
    Shape shapeArr[maxLen];
};

bool pushShapesToContainer(Container& cont, FILE* fp);

void printContainer(Container cont, std::ofstream& ofst);

void createRandomContainer(Container& container, int len);