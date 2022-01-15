#pragma once
#include <string>
enum Color {
    RED, ORANGE, YELLOW, GREEN, SKY, BLUE, PURPLE
};

std::string getColorName(Color color);

double getDistance(int xfirst, int yfirst, int xsecond, int ysecond);

void createRandomPoint(int& x, int& y);